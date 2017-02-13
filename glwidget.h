#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>

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

private slots:
    void onTimer();

private:
    QTimer                  m_timer;

    QOpenGLShaderProgram    *m_shaderProgram;
    QOpenGLShader           *m_vertexShader;
    QOpenGLShader           *m_fragmentShader;
    QOpenGLShader           *m_tesselationControlShader;
    QOpenGLShader           *m_tesselationEvaluationShader;

    GLuint          m_glVAO;

};

#endif // GLWIDGET_H
