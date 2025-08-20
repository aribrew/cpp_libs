
# If defined, the resulting binary will be named this
PROJECT_NAME					:= LogTest

# This path, if set, will be seached for source files (excluding MAIN)
SRC_PATH 						:= 

# OR you can add here the source files to build
SRCS 							:= 

# The main source file, if any
MAIN							:= LogTest.cpp

# Dependencies (Must have their own Makefile)
DEPS							:= ANSI Log StringHelpers

# Header paths to include in headers search
INCLUDE							:= .
INCLUDE 						+= ANSI
INCLUDE 						+= Log
INCLUDE 						+= StringHelpers

# Dynamic libraries to link
LIBS							:=

# Where to build things
BUILD_PATH						:= /tmp/cpp/build
OBJS_PATH						:= /tmp/cpp/obj




########################## D A N G E R  Z O N E ###########################

#### Functions ####
# ${1}: What to find
# ${2}: Where
define FIND
$(shell find -L ${2}/** -type f -name ${1})
endef


# ${1}: What to find
# ${2}: Where
# ${3}: Excluding
define FIND_EXCLUDING
$(shell find -L ${2}/** -type f -name ${1} -not -name ${3})
endef


# ${1}: A list of paths with headers
define INCLUDE_FLAGS_FROM
$(strip $(foreach path,${1},-I ${inc}))
endef


# ${1}: A list of dynamic library names
define LIBS_FLAGS_FROM
$(strip $(foreach lib,${1},-l${lib}))
endef


# ${1}: A list of paths with libraries
define LIBS_PATHS_FLAGS_FROM
$(strip $(foreach path,${1},-L ${inc}))
endef


# Obtains the paths of all provided files.
# The sort function also removes duplicates.
# ${1}: File list
define PATHS_OF
$(sort $(foreach file,${1},$(dir ${file})))
endef


# Obtains the .o file path from the given source file
# ${1}: Source file
# ${2}: Objs path
define SRC2OBJ
${2}/$(subst .c,.o,$(subst .cpp,.o,${1}))
endef


# Obtains a list of all folders below this one
# ${1}: Path
define TREE
$(shell find ${1}/** -type d)
endef
###################


#### Helpers ####
# Locate ALL source files below ${1} (excluding ${MAIN})
# ${1}: SRC path
ifneq (${MAIN},)
define FIND_ALL_SRCS
$(strip $(call FIND_EXCLUDING,"*.c",${1},${MAIN})$\
		$(call FIND_EXCLUDING,"*.cpp",${1},${MAIN}))
endef

else

define FIND_ALL_SRCS
$(strip $(call FIND_EXCLUDING,"*.c",${1},"main.c")$\
		$(call FIND_EXCLUDING,"*.cpp",${1},"main.cpp"))
endef
endif

# ${1}: Path where local dependencies are
define FIND_ALL_DEPS_SRCS
$(strip $(call FIND,"*.c",${1})$\
		$(call FIND,"*.cpp",${1}))
endef
#################




ifneq (${WINDIR},)
	SYSTEM						:= windows
else
	UNAME						:= $(shell uname)

	ifeq (${UNAME},Darwin)
		SYSTEM					:= macos
	else ifeq (${UNAME},Linux)
		SYSTEM					:= linux
	else
		SYSTEM					:= other
	endif
endif


BUILD_PATH						:= ${BUILD_PATH}/${SYSTEM}
OBJS_PATH						:= ${OBJS_PATH}/${SYSTEM}

EXEC							:= ${BUILD_PATH}

ifeq (${PROJECT_NAME},)
	EXEC						:= ${BUILD_PATH}
	EXEC						+= /$(basename $(notdir ${MAIN_OBJ}))
else
	EXEC						:= ${BUILD_PATH}/${PROJECT_NAME}
endif

ifeq (${SYSTEM},windows)
	EXEC						:= ${EXEC}.exe
endif


MAIN_OBJ						:= $(call SRC2OBJ,${MAIN},${OBJS_PATH})

ifneq (${SRC_PATH},)
SRCS							:= 
endif

ifneq (${SRCS},)
OBJS 							:=
endif

INCLUDE_FLAGS					:= $(foreach path,${INCLUDE},-I ${path} )
LINK_FLAGS						:= $(foreach lib,${LIBS},-L ${lib} )


C								:= gcc
CXX								:= g++




# All objetives, that aren't files, must have an entry here
.PHONY: all clean info obj run


# Special objetive. Always called when making.
all: ${OBJ} ${EXEC}
	$(info All objetives done)


clean:
	rm -r ${BUILD_PATH}
	rm -r ${OBJS_PATH}
	rm ${EXEC}
	

${OBJS_PATH}:
	mkdir -p ${OBJS_PATH}


${BUILD_PATH}:
	mkdir -p ${BUILD_PATH}


${MAIN_OBJ}: ${OBJS_PATH} ${MAIN}
ifeq ($(suffix ${MAIN}),.c)
	${C} -c ${MAIN} -o ${MAIN_OBJ} ${INCLUDE_FLAGS}
else
	${CXX} -c ${MAIN} -o ${MAIN_OBJ} ${INCLUDE_FLAGS}
endif


${EXEC}: ${BUILD_PATH} ${MAIN_OBJ} ${OBJS}
ifeq ($(suffix ${MAIN}),.c)
	${C} ${OBJS} ${MAIN_OBJ} -o ${EXEC} ${LINK_FLAGS}
else
	${CXX} ${OBJS} ${MAIN_OBJ} -o ${EXEC} ${LINK_FLAGS}
endif
	

# What to build
/tmp/touched: # What is needed
	# Steps to build
	touch $@


# A recommended objetive for checking vars (pardon, macros)
info:
	$(info PROJECT_NAME: ${PROJECT_NAME})
	$(info EXEC: ${EXEC})
	$(info SRC_PATH: ${SRC_PATH})
	$(info OBJS_PATH: ${OBJS_PATH})
	$(info BUILD_PATH: ${BUILD_PATH})

	$(info MAIN: ${MAIN})
	$(info MAIN_OBJ: ${MAIN_OBJ})

	$(info SRCS: ${SRCS})
	$(info OBJS: ${OBJS})

	$(info INCLUDE: ${INCLUDE})
	$(info INCLUDE_FLAGS: ${INCLUDE_FLAGS})

	$(info LIBS: ${LIBS})
	$(info LINK_FLAGS: ${LINK_FLAGS})

	$(info DEPS: ${DEPS})

run:
	chmod +x "${EXEC}"
	${EXEC}
	
