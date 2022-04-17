#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

uniform vec3 color;

uniform mat4 projMat;
uniform mat4 viewMat;
uniform mat4 modelMat;

void main()
{
	gl_Position = projMat * viewMat * modelMat * vec4(aPos.x, aPos.y, aPos.z, 1.0);
	ourColor = color;
	TexCoord = vec2(aTexCoord.x, aTexCoord.y);
}