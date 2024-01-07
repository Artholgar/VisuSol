#version 330

in vec3 vPosition;
in vec3 vNormal;
in vec2 vTextureCoord;

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightPos_vs;
uniform vec3 uLightIntensity;

uniform sampler2D uTexture;

out vec3 fColor;

vec3 blinnPhong()
{
    vec3 wi = normalize(uLightPos_vs - vPosition);
    vec3 w0 = normalize(-vPosition);
    float d = distance(uLightPos_vs, vPosition);

    vec3 halfVector = (w0 + wi) / 2;
    vec3 color = (uLightIntensity / (d * d)) * (uKd * dot(wi, vNormal) + uKs * pow(dot(halfVector, vNormal), uShininess));

    return color;
}



void main()
{
    fColor = texture(uTexture, vTextureCoord).xyz * blinnPhong();
}