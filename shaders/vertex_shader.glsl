//attribute vec4 qt_Vertex;
//attribute vec4 qt_MultiTexCoord0;
//uniform mat4 qt_ModelViewProjectionMatrix;
//varying vec4 qt_TexCoord0;

//void main(void)
//{
//    gl_Position = qt_ModelViewProjectionMatrix * qt_Vertex;
//    qt_TexCoord0 = qt_MultiTexCoord0;
//}

//#version 410 core
//void main(void)
//{
//    gl_Position = vec4(0.0, 0.0, 0.5, 1.0);
//}

#version 410 core
out vec4 vertexColor;
//out vec4 vertexColor2;
layout (location = 0) in vec4 offset;
void main(void)
{
    const vec4 vertices[3] = vec4[3](
		vec4(0.0, 0.5, 0.5, 1.0),
		vec4(-0.5, -0.5, 0.5, 1.0),
		vec4(0.5, -0.5, 0.5, 1.0)
		);
    const vec4 colors[3] = vec4[3](
		vec4(1.0, 0.0, 0.0, 1.0),
		vec4(0.0, 1.0, 0.0, 1.0),
		vec4(0.0, 0.0, 1.0, 1.0)
		);
    vertexColor = colors[gl_VertexID];
//    vertexColor2 = colors[gl_VertexID];
    gl_Position = vertices[gl_VertexID] + offset;
}
