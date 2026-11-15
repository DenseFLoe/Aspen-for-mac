// Native diagnostics for QTBUG-149612. No Qt private headers or runtime patches.
#define QT_NO_KEYWORDS
#include "CocoaAccessibilityCheck.h"
#include <QAccessible>
#include <QApplication>
#include <QTableWidget>
#import <AppKit/AppKit.h>

// Test bridge to the platform plugin. Fail if the selector disappears instead
// of silently falling back to offscreen / C++-only accessibility.
@interface NSObject (AspenAccessibilityProbe)
+ (id)elementWithId:(QAccessible::Id)identifier;
@end

bool checkCocoaSelection(QWidget *view, int expectedCells, QString *error)
{
    if (QGuiApplication::platformName() != "cocoa") {
        *error = "Native accessibility check requires QT_QPA_PLATFORM=cocoa";
        return false;
    }
    // Enter via QNSView as an actual AX client would, activating model events.
    NSView *nativeView = reinterpret_cast<NSView *>(view->window()->winId());
    (void)[nativeView accessibilityAttributeValue:NSAccessibilityChildrenAttribute];
    if (!QAccessible::isActive()) {
        *error = "Cocoa accessibility did not activate";
        return false;
    }
    auto *iface = QAccessible::queryAccessibleInterface(view);
    if (!iface || !iface->isValid()) {
        *error = "Missing accessible view interface";
        return false;
    }
    const auto identifier = QAccessible::uniqueId(iface);
    Class bridge = NSClassFromString(@"QMacAccessibilityElement");
    if (!bridge || ![bridge respondsToSelector:@selector(elementWithId:)]) {
        *error = "Cocoa accessibility bridge/selector unavailable";
        return false;
    }
    @autoreleasepool {
        id element = [[bridge elementWithId:identifier] retain];
        if (!element) {
            *error = "Missing native accessibility element";
            return false;
        }
        // Materialize placeholder cells BEFORE requesting selected children:
        // replacing those placeholders triggered the upstream ownership bug.
        if (iface->tableInterface()) {
            for (id row in [element accessibilityRows])
                (void)[row accessibilityChildren];
        }
        NSArray *selection = [element accessibilitySelectedChildren];
        const auto count = [selection count];
        [element release];
        if (count != NSUInteger(expectedCells)) {
            *error = QString("Native selected cell count %1 != %2").arg(count).arg(expectedCells);
            return false;
        }
    }
    // Pool drainage must not remove the parent interface or its cached cells.
    if (QAccessible::accessibleInterface(identifier) != iface) {
        *error = "Native query deleted the view accessibility interface";
        return false;
    }
    error->clear();
    return true;
}

bool checkCocoaTableLifecycle(QString *error)
{

    for (int repeat = 0; repeat < 4; ++repeat) {
        QAccessible::Id identifier = 0;
        @autoreleasepool {
            auto *table = new QTableWidget(2, 2);
            table->setSelectionMode(QAbstractItemView::SingleSelection);
            table->setSelectionBehavior(QAbstractItemView::SelectRows);
            table->resize(800, 300);
            table->show();
            QCoreApplication::processEvents();
            identifier = QAccessible::uniqueId(QAccessible::queryAccessibleInterface(table));
            bool ok = true;
            for (int columns : {2, 3, 2, 3, 2}) {
                table->clearSelection();
                table->setColumnCount(columns);
                ok = checkCocoaSelection(table, 0, error);
                if (!ok) break;
                table->selectRow(0);
                ok = checkCocoaSelection(table, columns, error);
                if (!ok) break;
                table->setRowCount(0);
                ok = checkCocoaSelection(table, 0, error);
                if (!ok) break;
                table->setRowCount(2);
            }
            delete table;
            if (!ok) return false;
        }
        if (QAccessible::accessibleInterface(identifier)) {
            *error = "Destroyed table still has an accessible interface";
            return false;
        }
    }
    return true;
}
