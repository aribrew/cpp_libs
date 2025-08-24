# If defined, the resulting binary will be named this.
# Otherwise, it will be named as ${MAIN}.
# So, if we have no main, THIS MUST BE SET.
PROJECT_NAME					:= filesystem_test

# If set, this path will be seached for source files (excluding MAIN)
# 
# This is intended for the case we have a src folder with all the sources
# below it. The object paths for each one will have this folder
# (for example 'src') replaced by ${OBJS_PATH}.
SRC_PATH 						:= 

# Also you can add here more source files to build.
#
# This is intended for the case we have a bunch of source files,
# with or without sub-folders, and want to add them to the build.
#
# The object paths of each one will be ${OBJS_PATH}/{SRCS.entry}
MORE_SRCS 						:= 

# The main source file, if any. If none, we assume this is a library.
#
# You must put the full path to your main source file, because it may be
# in SRC_PATH root or can be elsewhere...
MAIN_SRC						:= FilesystemTest.cpp

# Header paths to include in headers search
INCLUDE							:= .
INCLUDE 						+= FilesystemHelpers
INCLUDE							+= Log
INCLUDE 						+= ANSI
INCLUDE 						+= StringHelpers
INCLUDE 						+= SystemHelpers

# Libs paths to include in libraries search (both static and dynamic)
LIBS_PATHS 						:= FilesystemHelpers/build/linux
LIBS_PATHS 						+= Log/build/linux
LIBS_PATHS 						+= ANSI/build/linux
LIBS_PATHS 						+= StringHelpers/build/linux
LIBS_PATHS 						+= SystemHelpers/build/linux

# Libraries to link with (libwhatever.so and libwhatever.a)
LIBS							:= filesystemhelpers
LIBS 							+= log
LIBS 							+= ansi
LIBS 							+= stringhelpers
LIBS 							+= systemhelpers

# Where to build things
BUILD_PATH						:= build
OBJS_PATH						:= obj

# User flags for ar and both the C and the C++ compiler
C_FLAGS							:= 
CXX_FLAGS						:=
AR_FLAGS						:=




# DO NOT TOUCH THIS
include Sys.mk

