//uniform sampler2D qt_Texture0;
//varying vec4 qt_TexCoord0;

//void main(void)
//{
//    gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);
//}

//#version 410 core
//out vec4 color;
//void main(void)
//{
//    color = vec4(0.0, 0.5, 0.3, 1.0);
//}

#version 450 core
in vec4 vertexColor;
out vec4 color;
void main(void)
{
    color = vertexColor;
//    color = vec4(0.0, 0.5, 0.3, 1.0);
}
