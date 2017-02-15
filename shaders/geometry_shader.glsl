#version 450 core

layout (triangles) in;
layout (points, max_vertices = 3) out;

//in vec4 vertexColor2;
out vec4 vertexColor;

void main(void)
{
    int i;
  //  vertexColor = vertexColor2;
    for(i = 0; i < gl_in.length(); ++i)
    {
        gl_Position = gl_in[i].gl_Position;
        EmitVertex();
    }
}
