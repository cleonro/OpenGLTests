
#version 410 core

layout (triangles, equal_spacing, cw) in;

patch in vec4 vertexColor1;
out vec4 vertexColor2;

void main(void)
{
    vertexColor2 = vertexColor1;
    gl_Position = (gl_TessCoord.x * gl_in[0].gl_Position
	    + gl_TessCoord.y * gl_in[1].gl_Position
	    + gl_TessCoord.z * gl_in[2].gl_Position);
}
