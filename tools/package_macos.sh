#!/bin/sh
# Package only into a newly reserved build directory. Never cleans local assets.
set -eu
build_dir=${1:-build}
qt_prefix=${2:-$(brew --prefix qt)}
test -d "$build_dir/AspenPlusUIShell.app"
package_dir=$(mktemp -d "$build_dir/macos-package.XXXXXX")
bundle="$package_dir/AspenPlusUIShell.app"
ditto "$build_dir/AspenPlusUIShell.app" "$bundle"
# Deploy only this Widgets application's plugins. Homebrew splits optional Qt
# modules across prefixes, and scanning every plugin can pull in unresolved PDF,
# SVG or virtual-keyboard dependencies. Include offscreen for the package check.
plugin_root=$("$qt_prefix/bin/qmake" -query QT_INSTALL_PLUGINS)
set -- "$bundle" -no-plugins -always-overwrite
for plugin in platforms/libqcocoa.dylib platforms/libqoffscreen.dylib sqldrivers/libqsqlite.dylib; do
    test -f "$plugin_root/$plugin"
    destination="$bundle/Contents/PlugIns/$plugin"
    mkdir -p "$(dirname "$destination")"
    ditto "$plugin_root/$plugin" "$destination"
    set -- "$@" "-executable=$destination"
done
for plugin in imageformats/libqjpeg.dylib imageformats/libqgif.dylib imageformats/libqico.dylib styles/libqmacstyle.dylib; do
    if test -f "$plugin_root/$plugin"; then
        destination="$bundle/Contents/PlugIns/$plugin"
        mkdir -p "$(dirname "$destination")"
        ditto "$plugin_root/$plugin" "$destination"
        set -- "$@" "-executable=$destination"
    fi
done
mkdir -p "$bundle/Contents/Resources"
printf '[Paths]\nPlugins = PlugIns\n' > "$bundle/Contents/Resources/qt.conf"
"$qt_prefix/bin/macdeployqt" "$@" > "$package_dir/deployment.log" 2>&1 || {
    cat "$package_dir/deployment.log"
    exit 1
}
cat "$package_dir/deployment.log"
if grep -q '^ERROR:' "$package_dir/deployment.log"; then
    exit 1
fi
test -f "$bundle/Contents/PlugIns/sqldrivers/libqsqlite.dylib"
QT_PLUGIN_PATH= QT_QPA_PLATFORM_PLUGIN_PATH= QT_QPA_PLATFORM=offscreen "$bundle/Contents/MacOS/AspenPlusUIShell" --self-check
ditto -c -k --sequesterRsrc --keepParent "$bundle" "$package_dir/AspenPlusUIShell-macOS.zip"
printf 'Local macOS package: %s\n' "$package_dir/AspenPlusUIShell-macOS.zip"
