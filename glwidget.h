#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>

class QOpenGLShaderProgram;
class QOpenGLShader;

class GLWidget : public QOpenGLWidget
{
public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    QOpenGLShaderProgram    *m_shaderProgram;
    QOpenGLShader           *m_vertexShader;
    QOpenGLShader           *m_fragmentShader;

    GLuint          m_glVAO;

};

#endif // GLWIDGET_H
