### Generic Makefile.include for Webots controllers, physics plugins, robot
### window libraries, remote control libraries and other libraries
### to be used with GNU make
###
### Platforms: Windows, Mac OS X, Linux
### Languages: C, C++, Java
###
### Authors: Olivier Michel, Yvan Bourquin, Fabien Rohrer
###          Edmund Ronald, Sergei Poskriakov
###
###-----------------------------------------------------------------------------
###
### This file is meant to be included from the Makefile files located in the
### Webots projects subdirectories. It is possible to set a number of variables
### to customize the build process, i.e., add source files, compilation flags,
### include paths, libraries, etc. These variables should be set in your local
### Makefile just before including this Makefile.include. This Makefile.include
### should never be modified.
###
### Here is a description of the variables you may set in your local Makefile:
###
### ---- C Sources ----
### if your program uses several C source files:
### C_SOURCES = my_plugin.c my_clever_algo.c my_graphics.c
###
### ---- C++ Sources ----
### if your program uses several C++ source files:
### CXX_SOURCES = my_plugin.cc my_clever_algo.cpp my_graphics.c++
###
### ---- Compilation options ----
### if special compilation flags are necessary:
### CFLAGS = -Wno-unused-result
###
### ---- Linked libraries ----
### if your program needs additional libraries:
### INCLUDE = -I"/my_library_path/include"
### LIBRARIES = -L"/path/to/my/library" -lmy_library -lmy_other_library
###
### --- Webots included libraries ---
### In your C++ program, if you want to use the C API, add
### USE_C_API = true
### or if you want to link with the Qt framework embedded in Webots:
### QT = core gui widgets network
###
### ----- Java -----
### if your program uses several C source files:
### JAVA_SOURCES = my_plugin.java my_clever_algo.java
###
### if your Java controller needs additional libraries, you should define
### the CLASSPATH environment variable as explained in the Webots User Guide
### CLASSPATH=relative/mylib.jar
###
###-----------------------------------------------------------------------------
CXX_SOURCES  = EPuckFramework.cpp
CXX_SOURCES += math/Matrix.cpp math/MVTools.cpp
CXX_SOURCES += modules/EPuckBodyProvider.cpp modules/EPuckBodySend.cpp modules/ProjectModule.cpp
CXX_SOURCES += kernel/Communication.cpp kernel/Config.cpp kernel/Drawing.cpp kernel/Framework.cpp kernel/Log.cpp kernel/Timer.cpp
CXX_SOURCES += utils/net/Addr.cpp utils/net/Exception.cpp utils/net/Handler.cpp utils/net/Socket.cpp utils/net/TCPSocket.cpp utils/net/UDPSocket.cpp 

### Do not modify: this includes Webots global Makefile.include
space :=
space +=
WEBOTS_HOME_PATH=$(subst $(space),\ ,$(strip $(subst \,/,$(WEBOTS_HOME))))
include $(WEBOTS_HOME_PATH)/resources/Makefile.include
