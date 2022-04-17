#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

uniform vec3 color;
uniform vec2 pos;
uniform vec2 offset;

void main()
{
	gl_Position = vec4(aPos.x + pos.x, aPos.y + pos.y, aPos.z, 1.0);
	ourColor = color;
	TexCoord = vec2(aTexCoord.x + offset.x, aTexCoord.y + offset.y);
}