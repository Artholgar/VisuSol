#version 330

uniform sampler2D uTexture;
in vec3 vPosition;
in vec3 vNormal;
in vec2 vTextureCoord;

out vec4 fColor;

void main() {
    fColor = texture(uTexture, vTextureCoord);
}