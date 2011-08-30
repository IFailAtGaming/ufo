######################################################################
# Automatically generated by qmake (2.01a) niedz. sie 28 23:15:23 2011
######################################################################

TEMPLATE = app
TARGET =
DEPENDPATH += . importer os
INCLUDEPATH += . importer os

# Input
HEADERS += citybuilding.h \
           cityitem.h \
           citymap.h \
           gfx.h \
           logger.h \
           mouse.h \
           screen.h \
           shaderprogram.h \
           surface.h \
           timer.h \
           utils.h \
           importer/bitmap.h \
           importer/cpngfile.h \
           importer/cursor.h \
           importer/palette.h \
           importer/pckfile.h \
           importer/pcxfile.h \
           importer/tabfile.h \
           os/FileEnums.h \
           os/FileIO.h \
           os/FileWin32.h \
    os/filelinux.h \
    importer/peoplepath.h
SOURCES += citybuilding.cpp \
           cityitem.cpp \
           citymap.cpp \
           gfx.cpp \
           logger.cpp \
           main.cpp \
           mouse.cpp \
           screen.cpp \
           shaderprogram.cpp \
           timer.cpp \
           utils.cpp \
           importer/bitmap.cpp \
           importer/cpngfile.cpp \
           importer/cursor.cpp \
           importer/palette.cpp \
           importer/pckfile.cpp \
           importer/pcxfile.cpp \
           importer/tabfile.cpp \
           os/FileEnums.cpp \
           os/FileIO.cpp \
           os/FileWin32.cpp \
    os/filelinux.cpp \
    importer/peoplepath.cpp

LIBS += -lSDL -lGL -lGLEW
