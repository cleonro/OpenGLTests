#include <GL/glew.h>

#include "glwidget.h"

#include <cmath>

#include <QOpenGLShaderProgram>
#include <QOpenGLShader>



GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , m_shaderProgram(nullptr)
    , m_vertexShader(nullptr)
    , m_fragmentShader(nullptr)
    , m_tesselationControlShader(nullptr)
    , m_tesselationEvaluationShader(nullptr)
    , m_geometryShader(nullptr)
{
    connect(&m_timer, &QTimer::timeout, this, &GLWidget::onTimer);
    m_timer.setInterval(1000.0 / 60.0);
    //m_timer.start();
}

GLWidget::~GLWidget()
{

}

void GLWidget::resizeGL(int w, int h)
{

}

void GLWidget::onTimer()
{
    this->update();
}

void GLWidget::initializeGL()
{
    glewExperimental = GL_TRUE;
    glewInit();
    this->initializeOpenGLFunctions();

    glClearColor(0.2, 0.3, 0.5, 0.7);

    m_shaderProgram = new QOpenGLShaderProgram();
    m_vertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
    m_fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);
    m_tesselationControlShader = new QOpenGLShader(QOpenGLShader::TessellationControl);
    m_tesselationEvaluationShader = new QOpenGLShader(QOpenGLShader::TessellationEvaluation);
    m_geometryShader = new QOpenGLShader(QOpenGLShader::Geometry);

    if(m_vertexShader->compileSourceFile(":/graphics/shaders/vertex_shader.glsl"))
    {
        qDebug() << "vertex shader compiled.";
    }
    else
    {
        qDebug() << "vertex shader not compiled!";
    }
    if(m_fragmentShader->compileSourceFile(":/graphics/shaders/fragment_shader.glsl"))
    {
        qDebug() << "fragment shader compiled.";
    }
    else
    {
        qDebug() << "fragment shader not compiled!";
    }
    if(m_tesselationControlShader->compileSourceFile(":/graphics/shaders/tesselation_control_shader.glsl"))
    {
        qDebug() << "tesselation control shader compiled.";
    }
    else
    {
        qDebug() << "tesselation control shader not compiled!";
    }
    if(m_tesselationEvaluationShader->compileSourceFile(":/graphics/shaders/tesselation_evaluation_shader.glsl"))
    {
        qDebug() << "tesselation evaluation shader compiled.";
    }
    else
    {
        qDebug() << "tesselation evaluation shader not compiled!";
    }
    if(m_geometryShader->compileSourceFile(":/graphics/shaders/geometry_shader.glsl"))
    {
        qDebug() << "geometry shader compiled.";
    }
    else
    {
        qDebug() << "geometry shader not compiled!";
    }

    m_shaderProgram->addShader(m_vertexShader);
    m_shaderProgram->addShader(m_fragmentShader);
//    m_shaderProgram->addShader(m_tesselationControlShader);
//    m_shaderProgram->addShader(m_tesselationEvaluationShader);
    //m_shaderProgram->addShader(m_geometryShader);

    if(m_shaderProgram->link())
    {
        qDebug() << "shader program linked.";
    }
    else
    {
        qDebug() << "shader program not linked!";
    }

    //glGenVertexArrays(1, &m_glVAO);
    glCreateVertexArrays(1, &m_glVAO);
    glBindVertexArray(m_glVAO);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}



void GLWidget::paintGL()
{
    static double currentTime = 0.0;
    currentTime += 1.0 / 60.0;

    GLfloat attrib[] = {
        0.5f * cosf(currentTime),
        0.5f * sinf(currentTime),
        0.0f,
        0.0f
    };

    const GLfloat color[] = {0.2, 0.3, 0.0, 1.0};
    glClearBufferfv(GL_COLOR, 0, color);

    m_shaderProgram->bind();

//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPointSize(4.0f);
    glVertexAttrib4fv(0, attrib);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    //glDrawArrays(GL_PATCHES, 0, 3);

    m_shaderProgram->release();
}

