#version 410 core


layout (vertices = 3) out;

in vec4 vertexColor[];
patch out vec4 vertexColor1;

void main(void)
{
    vertexColor1 = vertexColor[gl_InvocationID];
    if(gl_InvocationID == 0)
    {
        gl_TessLevelInner[0] = 3.0;
        gl_TessLevelOuter[0] = 1.0;
        gl_TessLevelOuter[1] = 2.0;
        gl_TessLevelOuter[2] = 3.0;
    }

    gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;
}
