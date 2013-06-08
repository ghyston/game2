#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin_4.x-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/514568350/Matrix4f.o \
	${OBJECTDIR}/_ext/658183900/GameEngine.o \
	${OBJECTDIR}/_ext/658183900/GlobalData.o \
	${OBJECTDIR}/_ext/1408417640/Button.o \
	${OBJECTDIR}/_ext/1408417640/GameGui.o \
	${OBJECTDIR}/_ext/1408417640/TouchController.o \
	${OBJECTDIR}/_ext/1408417640/Widget.o \
	${OBJECTDIR}/_ext/686220982/BaseRenderable.o \
	${OBJECTDIR}/_ext/686220982/Camera.o \
	${OBJECTDIR}/_ext/686220982/Grid.o \
	${OBJECTDIR}/_ext/686220982/Matrix4f.o \
	${OBJECTDIR}/_ext/686220982/Renderer.o \
	${OBJECTDIR}/_ext/686220982/Shader.o \
	${OBJECTDIR}/_ext/2139180284/TouchManager.o \
	${OBJECTDIR}/_ext/2139180284/TowerTouchProcessor.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lglut32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game2.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game2.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	g++ -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/514568350/Matrix4f.o: ../../../src/engine/Common/Matrix4f.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/514568350
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/514568350/Matrix4f.o ../../../src/engine/Common/Matrix4f.cpp

${OBJECTDIR}/_ext/658183900/GameEngine.o: ../../../src/engine/GameEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/658183900
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/658183900/GameEngine.o ../../../src/engine/GameEngine.cpp

${OBJECTDIR}/_ext/658183900/GlobalData.o: ../../../src/engine/GlobalData.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/658183900
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/658183900/GlobalData.o ../../../src/engine/GlobalData.cpp

${OBJECTDIR}/_ext/1408417640/Button.o: ../../../src/engine/Gui/Button.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1408417640
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1408417640/Button.o ../../../src/engine/Gui/Button.cpp

${OBJECTDIR}/_ext/1408417640/GameGui.o: ../../../src/engine/Gui/GameGui.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1408417640
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1408417640/GameGui.o ../../../src/engine/Gui/GameGui.cpp

${OBJECTDIR}/_ext/1408417640/TouchController.o: ../../../src/engine/Gui/TouchController.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1408417640
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1408417640/TouchController.o ../../../src/engine/Gui/TouchController.cpp

${OBJECTDIR}/_ext/1408417640/Widget.o: ../../../src/engine/Gui/Widget.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1408417640
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1408417640/Widget.o ../../../src/engine/Gui/Widget.cpp

${OBJECTDIR}/_ext/686220982/BaseRenderable.o: ../../../src/engine/Renderer/BaseRenderable.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/686220982
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/686220982/BaseRenderable.o ../../../src/engine/Renderer/BaseRenderable.cpp

${OBJECTDIR}/_ext/686220982/Camera.o: ../../../src/engine/Renderer/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/686220982
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/686220982/Camera.o ../../../src/engine/Renderer/Camera.cpp

${OBJECTDIR}/_ext/686220982/Grid.o: ../../../src/engine/Renderer/Grid.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/686220982
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/686220982/Grid.o ../../../src/engine/Renderer/Grid.cpp

${OBJECTDIR}/_ext/686220982/Matrix4f.o: ../../../src/engine/Renderer/Matrix4f.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/686220982
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/686220982/Matrix4f.o ../../../src/engine/Renderer/Matrix4f.cpp

${OBJECTDIR}/_ext/686220982/Renderer.o: ../../../src/engine/Renderer/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/686220982
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/686220982/Renderer.o ../../../src/engine/Renderer/Renderer.cpp

${OBJECTDIR}/_ext/686220982/Shader.o: ../../../src/engine/Renderer/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/686220982
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/686220982/Shader.o ../../../src/engine/Renderer/Shader.cpp

${OBJECTDIR}/_ext/2139180284/TouchManager.o: /cygdrive/D/projects/Game2/src/engine/Gui/TouchManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2139180284
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2139180284/TouchManager.o /cygdrive/D/projects/Game2/src/engine/Gui/TouchManager.cpp

${OBJECTDIR}/_ext/2139180284/TowerTouchProcessor.o: /cygdrive/D/projects/Game2/src/engine/Gui/TowerTouchProcessor.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2139180284
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/2139180284/TowerTouchProcessor.o /cygdrive/D/projects/Game2/src/engine/Gui/TowerTouchProcessor.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/game2.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
