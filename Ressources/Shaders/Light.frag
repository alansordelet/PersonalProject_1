#version 120
uniform sampler2D texture;	// Texture of Scene Rendered
uniform vec3 AmbientLight;	// Scene Light colors : sun, moon...
uniform vec3 LightPosition;	// Spot Light Position
uniform vec3 LightColor;	// Spot Light colors
uniform float LightRadius;	// Spot Light Radius

void main()
{
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	float dist = sqrt(pow(LightPosition.x - gl_FragCoord.x, 2) + 
					pow(LightPosition.y - gl_FragCoord.y, 2) +
					pow(LightPosition.z - gl_FragCoord.z, 2));
	vec4 finalPixel;
	if(dist <= LightRadius)
	{
		finalPixel = (gl_Color * pixel) + (pixel * vec4(LightColor, 1.0f));
	}
	else
	{
		finalPixel = (gl_Color * pixel) * vec4(AmbientLight, 1.0f);
	}
	gl_FragColor = finalPixel;
}