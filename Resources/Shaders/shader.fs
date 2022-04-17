#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;

void main()
{
	FragColor = texture2D(texture1, TexCoord) * vec4(ourColor, 1.0);
	
	if (FragColor.w < 1.0) {
		discard;
	}
}