#include"Lighting.h"


sfTexture* tmp;
sfSprite* tmpS;


sfVector2f speed2 = { 100, 100 };
sfVector2f posplayer2;

sfVector3f PosLight = { 312.5, 800, 1 };

float radius = 160;

void initLight()
{
	tmp = sfTexture_create(1000, 800);
	tmpS = sfSprite_create();

	


	shader = sfShader_createFromFile(NULL, NULL, "../Ressources/Shaders/Light_Falloff.frag");
	renderState.shader = shader;
	renderState.blendMode = sfBlendAlpha;
	renderState.transform = sfTransform_Identity;
	renderState.texture = NULL;
}




void updatelight(sfRenderWindow* window)
{
	posplayer2.x = 400;
	posplayer2.y = 57;

	
	if (state == GAME)
	{
		PosLight.x = posplayer2.x + 100;
		PosLight.y = 460 - posplayer2.y;
		if (sfKeyboard_isKeyPressed(sfKeyQ))
		{
			posplayer2.x -= speed2.x * GetDeltaTime();
		}
		if (sfKeyboard_isKeyPressed(sfKeyD))
		{
			posplayer2.x += speed2.x * GetDeltaTime();
		}
		if (sfKeyboard_isKeyPressed(sfKeyZ))
		{
			posplayer2.y -= speed2.y * GetDeltaTime();
		}
		if (sfKeyboard_isKeyPressed(sfKeyS))
		{
			posplayer2.y += speed2.y * GetDeltaTime();
		}
		sfShader_setVec3Uniform(shader, "AmbientLight", vector3f(0.05, 0.05, 0.05));
	}
	if (state == EDITOR)
	{
		sfShader_setVec3Uniform(shader, "AmbientLight", vector3f(0.6, 0.6, 0.6));
		PosLight.x = posplayer2.x ;
		PosLight.y =  posplayer2.y;
		sfVector2i position;

		sfVector2i mousepositio;
		mousepositio = sfMouse_getPosition(window);
		sfVector2f mapPixelToCoords;
		mapPixelToCoords = sfRenderWindow_mapPixelToCoords(window, mousepositio, viewEditor);
		position.x = (int)mapPixelToCoords.x / 16;
		position.y = (int)mapPixelToCoords.y / 16;
		posplayer2.x = position.x;
		posplayer2.y = position.y;
	}
	
	if (sfKeyboard_isKeyPressed(sfKeyUp))
	{
		radius += 0.5;
	}
	if (sfKeyboard_isKeyPressed(sfKeyDown))
	{
		radius -= 0.5;
	}

	
	sfShader_setVec3Uniform(shader, "LightPosition", PosLight);
	sfShader_setVec3Uniform(shader, "LightColor", vector3f(0.4f, 0.4f, 0.4f));
	sfShader_setFloatUniform(shader, "LightRadius", radius);
	
}

void displaylight(sfRenderWindow* window)
{
	sfTexture_updateFromRenderWindow(tmp, window, 0, 0);
}