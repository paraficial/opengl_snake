#version 330 core

in vec3 fragmentColor;

out vec3 color;

void main() {
	color = fragmentColor;
	//color = vec3(1,1,1);
}
