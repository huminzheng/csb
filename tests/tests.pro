TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle

SOURCES += \
    src/main.cpp \
    src/ParticleTests.cpp \
    src/TriMeshTests.cpp \
    src/SimulatedMeshTests.cpp \
    src/DistanceConstraintTests.cpp \
    src/BendingConstraintTests.cpp \
    src/PinConstraintTests.cpp

DEPENDPATH += . ../csb
INCLUDEPATH = ../csb/include
INCLUDEPATH += \
    /usr/local/include/glm/glm \
    /usr/local/include/glm

LIBS += -lgtest -pthread -L../csb -lcsb

QMAKE_CXXFLAGS += -O3 -std=c++14

HEADERS += \
    src/UtilMacros.h

DISTFILES +=
