#pragma once

#include <QApplication>
#include <QColor>
#include <QPalette>
#include <QStyleHints>

inline void applyLightTheme(QApplication &app)
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 8, 0)
    app.styleHints()->setColorScheme(Qt::ColorScheme::Light);
#endif
    app.setStyle("Fusion");

    // The captured Aspen interface is light, even when the desktop is dark.
    // Set every surface and bevel role used by Fusion's unstyled controls.
    QPalette palette;
    palette.setColor(QPalette::Window, QColor("#d6e4f3"));
    palette.setColor(QPalette::WindowText, QColor("#172532"));
    palette.setColor(QPalette::Base, Qt::white);
    palette.setColor(QPalette::AlternateBase, QColor("#edf3f8"));
    palette.setColor(QPalette::Text, QColor("#172532"));
    palette.setColor(QPalette::Button, QColor("#edf3f8"));
    palette.setColor(QPalette::ButtonText, QColor("#172532"));
    palette.setColor(QPalette::BrightText, Qt::white);
    palette.setColor(QPalette::Light, Qt::white);
    palette.setColor(QPalette::Midlight, QColor("#edf3f8"));
    palette.setColor(QPalette::Mid, QColor("#a9bacd"));
    palette.setColor(QPalette::Dark, QColor("#8e9da9"));
    palette.setColor(QPalette::Shadow, QColor("#667b8f"));
    palette.setColor(QPalette::Highlight, QColor("#c7ddf5"));
    palette.setColor(QPalette::HighlightedText, QColor("#172532"));
    palette.setColor(QPalette::ToolTipBase, QColor("#fffdeb"));
    palette.setColor(QPalette::ToolTipText, QColor("#172532"));
    palette.setColor(QPalette::Link, QColor("#007cb9"));
    palette.setColor(QPalette::LinkVisited, QColor("#6a4aa6"));
    palette.setColor(QPalette::PlaceholderText, QColor("#788b9d"));
    for (const auto role : {QPalette::WindowText, QPalette::Text, QPalette::ButtonText})
        palette.setColor(QPalette::Disabled, role, QColor("#96969d"));
    palette.setColor(QPalette::Disabled, QPalette::Base, QColor("#e9e9ef"));
    palette.setColor(QPalette::Disabled, QPalette::Button, QColor("#e9e9ef"));
    app.setPalette(palette);
}
