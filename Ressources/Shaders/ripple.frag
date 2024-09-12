uniform vec2      iResolution;           // viewport resolution (in pixels)
uniform float     iGlobalTime;           // shader playback time (in seconds)          
uniform sampler2D iChannel0;          // input channel. XX = 2D/Cube
uniform vec2	  iRipple_Position;

void main()
{
	vec4 color_vague = vec4(0.0,0.0,1.0,0.5);
	vec2 uv = gl_TexCoord[0].xy;
	float posX = iRipple_Position.x/iResolution.x;
	float posY = iRipple_Position.y/iResolution.y;
	
	float w = posX - uv.x ;
    float h = posY - uv.y;
	float distanceFromCenter = sqrt(w * w + h * h);

	float sinArg = clamp(-iGlobalTime*iGlobalTime+distanceFromCenter / (sqrt(iGlobalTime)*0.1),0.0,2.0*3.1415926535);
	float slope = sin(sinArg)/(iGlobalTime*5);
	vec4 color = texture2D(iChannel0, uv + normalize(vec2(w, h)) * slope * 0.03);
	color *= color_vague;
	color *= color_vague.a;
	color += texture2D(iChannel0, uv + normalize(vec2(w, h)) * slope * 0.03);
	gl_FragColor = color;
	//vec4 pixel = texture2D(iChannel0, gl_TexCoord[0].xy);
	//gl_FragColor = vec4(1.0,0.0,0.0,0.5) * pixel;
	
	/*  
	float sinArg = distanceFromCenter * 20.0 - iGlobalTime * 10.1;
	float slope = cos(sinArg);
	vec4 color = texture2D(iChannel0, uv + normalize(vec2(w, h)) * slope * 0.02);
	color *= color_vague;
	color *= color_vague.a;
	
	color += texture2D(iChannel0, uv + normalize(vec2(w, h)) * slope * 0.02);
	gl_FragColor = color;
	*/
	//gl_FragColor = texture2D(iChannel0, gl_TexCoord[0].xy);
	//gl_FragColor = vec4(0.5,0.0,0.9,0.5);
}