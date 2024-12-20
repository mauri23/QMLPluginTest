# QMLPluginTest

## Overview

This project aims to provide an exmaple of  QML plugin deployment for an Android target.  
The current status of the project is "In progress", it means that by now the goal is not reached yet.

## Project Description
The project structure is simple:
- the **app** folder contains the main QML application
- the **MyWonderfulPlugin** folder contains the QML plugin implementation

The app uses the *MyWonderfulItem* component exported by the plugin (see *MyWonderfulPlugin.cpp* and *main.qml*)

## Project build
The project build is currently being performed with the following environment:
- Qt 6.8.1
- Android NDK 26.1.10909125
- Kit "Android Qt 6.8.1 Clang arm64-v8a" (debug)

The build generates the following apk:
- <OUT_DIR>/app/android-build/build/outputs/apk/debug/android-build-debug.apk

## Install and test
Install the apk on the device with adb:  
    `adb install <OUT_DIR>/app/android-build/build/outputs/apk/debug/android-build-debug.apk`

Before to start the application attach to logcat:  
```
adb logcat -c
adb logcat |grep libapp
```

The current output is:
```

12-20 11:30:33.046  2032  2070 D libapp_arm64-v8a.so: Import paths: QList("qrc:/android_rcc_bundle/qml", "/data/app/~~RTWVNxHesl_ipSehrkN82g==/org.qtproject.example.app-YArisjN7nP1cvqONgVlc5Q==/lib/arm64", "qrc:/qt-project.org/imports", "qrc:/qt/qml")
12-20 11:30:33.075  2032  2070 W libapp_arm64-v8a.so: QQmlApplicationEngine failed to load component
12-20 11:30:33.075  2032  2070 W libapp_arm64-v8a.so: qrc:/main.qml:2:1: module "MyWonderfulPlugin" is not installed
12-20 11:30:33.078  2032  2070 I libapp_arm64-v8a.so: main() returned -1

```

## Analysis
* The plugin seems to be successfully generated: looking into the apk (just open it with 7-zip) we can see that in the lib/arm64-v8a/ folder is present the *libplugins_MyWonderfulPlugin_MyWonderfulPlugin_arm64-v8a.so* file related to the plugin
* As far as I understand, the plugin deployment is pretty different than Windows/Unix environment, where the plugin must follow a precise structure (a specific folder/folder tree having the same name of the module containing the .dll/.so of the plugin alongside the qmldir file).
   * For example, if I would deploy such plugin on windows, I need to create a folder named MyWonderfulPlugin where to put the MyWonderfulPlugin.dll and the qmldir. The the folder's parent path must be added to the Qt engine's plugins path in order to be resolved
* In Android it seems that the deployment phase processes the plugins in order to generate a library with the following structure **libplugin_[ModuleName]\_[PluginName]\_[Arch].so**
* Although the file is generated properly, it still fails to be loaded.





