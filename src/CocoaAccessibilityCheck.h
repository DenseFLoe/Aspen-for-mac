#pragma once
#include <QString>
class QWidget;

// Diagnostic-only native Cocoa probes; never disable accessibility.
bool checkCocoaSelection(QWidget *view, int expectedCells, QString *error);
bool checkCocoaTableLifecycle(QString *error);
