uniform float 		time;
uniform vec2 		resolution;
uniform sampler2D 	iChannel0;
uniform vec2	  	iRipple_Position;

vec2 position;


vec3 grid(vec3 colour, float linesize, float xc, float yc){
	float xmod = mod(position.x, xc);
	float ymod = mod(position.y, yc);
	return xmod < linesize || ymod < linesize ? vec3(52) : colour;
}

vec3 circle(vec3 colour, float size, float linesize, float xc, float yc){
	float dist = distance(position, vec2(xc, yc));
	return colour * clamp(-(abs(dist - size)*linesize * 32.0) + 0.9, 0.0, 5.0);
}

vec3 red = vec3(1, 1, 5);
vec3 green = vec3(5, 6, 8);
vec3 blue = vec3(4, 23, 23);
void main( ) {

	float posX = iRipple_Position.x/resolution.x;
	float posY = 1-(iRipple_Position.y/resolution.y);
	
	
	position = ( gl_FragCoord.xy / resolution.xy );
	position.y = position.y * resolution.y/resolution.x + 0.15;
	
	vec3 color = vec3(0.0,0.0,0.01);
	//float ratio = resolution.x / resolution.y;
	color += circle(red, 0.7*time, 1.0, posX, posY);
	
	//color += grid(blue * 0.2, 0.001, 0.06, 0.06);
	color *= 2.0 - distance(position, vec2(0.5, 0.5));
	gl_FragColor = vec4(color, 0.1 );

}