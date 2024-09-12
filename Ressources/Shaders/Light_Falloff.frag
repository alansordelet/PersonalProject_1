uniform sampler2D texture;	// Texture of Scene Rendered
uniform vec3 AmbientLight;	// Scene Light colors : sun, moon...
uniform vec3 LightPosition;	// Spot Light Position
uniform vec3 LightColor;	// Spot Light colors
uniform float LightRadius;	// Spot Light Radius
uniform float LightFalloff;	// where the Light start to FallOff

void main()
{
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
	// Normalized light vector and distance to the light surface.
	vec3 L = LightPosition - gl_FragCoord.xyz;
	float distance = length(L);
	float d = max(distance - LightRadius, 0);
	L /= distance;
	// calculate basic attenuation
	float attenuation = 1 / pow(d/LightRadius + 1, 2);
	attenuation = (attenuation - LightFalloff) / ( 1 - LightFalloff);
	attenuation = max(attenuation, 0);
	
	vec4 finalPixel = (gl_Color * pixel);
	finalPixel *= vec4(AmbientLight, 1.0); // IF FIRST PASS ONLY!
	finalPixel += (pixel * vec4(LightColor, 1.0) * attenuation);
	gl_FragColor = finalPixel;
}