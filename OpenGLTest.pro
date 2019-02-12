#-------------------------------------------------
#
# Project created by QtCreator 2017-01-31T15:30:27
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = OpenGLTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui

DISTFILES += \
    shaders/vertex_shader.glsl \
    shaders/fragment_shader.glsl \
    shaders/tesselation_control_shader.glsl \
    shaders/tesselation_evaluation_shader.glsl \
    shaders/geometry_shader.glsl

RESOURCES += \
    resource.qrc

unix:!macx {
 LIBS += -lGLEW
}

win32 {
  INCLUDEPATH += "c:/Program Files (x86)/NVIDIA Corporation/Nsight Visual Studio Edition 6.0/Monitor/glew/include/"
  DEPENDPATH += "c:/Program Files (x86)/NVIDIA Corporation/Nsight Visual Studio Edition 6.0/Monitor/glew/lib/Release/x64/"
  LIBS += -L"c:/Program Files (x86)/NVIDIA Corporation/Nsight Visual Studio Edition 6.0/Monitor/glew/lib/Release/x64/" -lglew32
}
