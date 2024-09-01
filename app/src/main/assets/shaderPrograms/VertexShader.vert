#version 300 es

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 ourColor;
out vec2 TexCoord;
out vec3 fragmentPosition;

uniform mat4 transform;

void main()
{
	//gl_Position = transform * vec4(aPos, 1.0f);
	fragmentPosition = aPos;
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	ourColor = aColor;
	TexCoord = aTexCoord;
}