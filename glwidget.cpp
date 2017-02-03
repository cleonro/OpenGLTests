#include "glwidget.h"

#include <QOpenGLShaderProgram>
#include <QOpenGLShader>

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , m_shaderProgram(nullptr)
    , m_vertexShader(nullptr)
    , m_fragmentShader(nullptr)
{

}

GLWidget::~GLWidget()
{

}

void GLWidget::resizeGL(int w, int h)
{

}

void GLWidget::initializeGL()
{
    glClearColor(0.2, 0.3, 0.5, 0.7);

    m_shaderProgram = new QOpenGLShaderProgram();
    m_vertexShader = new QOpenGLShader(QOpenGLShader::Vertex);
    m_fragmentShader = new QOpenGLShader(QOpenGLShader::Fragment);

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

    m_shaderProgram->addShader(m_vertexShader);
    m_shaderProgram->addShader(m_fragmentShader);
    if(m_shaderProgram->link())
    {
        qDebug() << "shader program linked.";
    }
    else
    {
        qDebug() << "shader program not linked!";
    }

    glGenVertexArrays(1, &m_glVAO);
    glBindVertexArray(m_glVAO);
}

void GLWidget::paintGL()
{
    const GLfloat color[] = {0.2, 0.3, 0.0, 1.0};
    glClearBufferfv(GL_COLOR, 0, color);

    m_shaderProgram->bind();

    glPointSize(40.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    m_shaderProgram->release();
}

