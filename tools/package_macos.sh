#!/bin/sh
# Package only into a newly reserved build directory. Never cleans local assets.
set -eu
build_dir=${1:-build}
qt_prefix=${2:-$(brew --prefix qt)}
test -d "$build_dir/AspenPlusUIShell.app"
package_dir=$(mktemp -d "$build_dir/macos-package.XXXXXX")
bundle="$package_dir/AspenPlusUIShell.app"
ditto "$build_dir/AspenPlusUIShell.app" "$bundle"
"$qt_prefix/bin/macdeployqt" "$bundle" -always-overwrite
test -f "$bundle/Contents/PlugIns/sqldrivers/libqsqlite.dylib"
QT_QPA_PLATFORM=offscreen "$bundle/Contents/MacOS/AspenPlusUIShell" --self-check
ditto -c -k --sequesterRsrc --keepParent "$bundle" "$package_dir/AspenPlusUIShell-macOS.zip"
printf 'Local macOS package: %s\n' "$package_dir/AspenPlusUIShell-macOS.zip"
