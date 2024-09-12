#ifdef GL_ES
precision mediump float;
#endif


uniform float	iTime;
uniform vec2	resolution;
uniform sampler2D iChannel0;
uniform sampler2D iChannel1;

void main( void )
{
	vec2 uv = gl_FragCoord.xy / resolution.xy;
	vec2 block = floor(gl_FragCoord.xy / vec2(16));
	vec2 uv_noise = block / vec2(64);
	uv_noise += floor(vec2(iTime) * vec2(1234.0, 3543.0)) / vec2(64);
	
	float block_thresh = pow(fract(iTime * 1236.0453), 2.0) * 0.2;
	float line_thresh = pow(fract(iTime * 2236.0453), 3.0) * 0.7;
	
	vec2 uv_r = uv, uv_g = uv, uv_b = uv;

	// glitch some blocks and lines
	if (texture(iChannel1, uv_noise).r < block_thresh ||
		texture(iChannel1, vec2(uv_noise.y, 0.0)).g < line_thresh) {

		vec2 dist = (fract(uv_noise) - 0.5) * 0.3;
		uv_r += dist * 0.1;
		uv_g += dist * 0.2;
		uv_b += dist * 0.125;
	}

	gl_FragColor.r = texture(iChannel0, uv_r).r;
	gl_FragColor.g = texture(iChannel0, uv_g).g;
	gl_FragColor.b = texture(iChannel0, uv_b).b;

	// loose luma for some blocks
	if (texture(iChannel1, uv_noise).g < block_thresh)
		gl_FragColor.rgb = gl_FragColor.ggg;

	// discolor block lines
	if (texture(iChannel1, vec2(uv_noise.y, 0.0)).b * 3.5 < line_thresh)
		gl_FragColor.rgb = vec3(0.0, dot(gl_FragColor.rgb, vec3(1.0)), 0.0);

	// interleave lines in some blocks
	if (texture(iChannel1, uv_noise).g * 1.5 < block_thresh ||
		texture(iChannel1, vec2(uv_noise.y, 0.0)).g * 2.5 < line_thresh) {
		float line = fract(gl_FragCoord.y / 3.0);
		vec3 mask = vec3(3.0, 0.0, 0.0);
		if (line > 0.333)
			mask = vec3(0.0, 3.0, 0.0);
		if (line > 0.666)
			mask = vec3(0.0, 0.0, 3.0);
		
		gl_FragColor.xyz *= mask;
	}

gl_FragColor += vec4(0.2, 0.2, 0.2, 0.9);










/*
	vec2 uv = gl_FragCoord.xy / resolution.xy;
    
    
    vec4 glitch;
    
    vec2 uvOffset = texture(noise, vec2(time*50.0)).rg;
    uvOffset.x *= 0.02;
    uvOffset.y *= 0.052;
    
    glitch.r = texture(currentTexture, uv + uvOffset + vec2(-0.02*texture(noise, vec2(uv.x,uv.y/200.0 + time*50.0)).r, (tan(sin(time*50.0)) * 0.6 ) * 0.05) ).r;
    glitch.g = vec4(texture(currentTexture, uv + uvOffset)).g;
    glitch.b = texture(currentTexture, uv / uvOffset + vec2(-0.01*texture(noise, vec2(uv.x/2.0,uv.y + time*50.0)).r, -0.2) ).b;
    
    
    glitch.rgb = mix(glitch.rgb, vec3(dot(glitch.rgb, vec3(.43))), 0.5);
    
	gl_gl_FragColor = vec4(glitch) ;//* vec4(1.0, 0.0, 0.0, 1.0);//vec4(glitch);
	
*/
}