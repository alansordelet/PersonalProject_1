#include"tools.h"
#include"map.h"
#include"Player.h"
#include"lighting.h"

sfTexture* SkullT;
sfSprite* SkullS;

sfTexture* PortalT;
sfSprite* PortalS;
sfTexture* PlayerT;

sfTexture* FirstSpeechT;
sfSprite* FirstSpeechS;

sfTexture* SecondSpeechT;
sfSprite* SecondSpeechS;

sfTexture* BookSpeechT;
sfSprite* BookSpeechS;

sfTexture* ThirdSpeechT;
sfSprite* ThirdSpeechS;
sfVector2f firstpos = { 60,65.0f };
sfVector2f Secondpos = { 600,540.0f };
sfVector2f thirdpos = { 1185,430 };

float animtime = 0.0f;
float speechtimer = 0.0f;
int FrameX = 0;
int FrameY = 1;

sfBool IsMoving = sfFalse;
sfBool UnlockLibrary = sfFalse;
sfFloatRect Playerrec = { 0,0,64,64 };
sfVector2f scale2 = { 0.4f, 0.4f };
sfVector2f vitesse = { 100.0f, 100.0f };
sfVector2f SizeMap = { 2812,2812.0f };
sfVector2f posUnlock = { 432,750 };
sfIntRect Movement = { 0 , 0 , 64, 64 };
float timerunlock;

void PlayerInit()
{
	PlayerT = sfTexture_createFromFile(TEXTURE_PATH"maybe.png", NULL);
	PlayerSprite = sfSprite_create();
	sfSprite_setTexture(PlayerSprite, PlayerT, sfTrue);
	sfSprite_setOrigin(PlayerSprite, vector2f(64 / 2, 64 / 2));
	PosPlayer.x = 45;
	PosPlayer.y = 92;

	SkullT = sfTexture_createFromFile(TEXTURE_PATH"PortalUnlock.png", NULL);
	SkullS = sfSprite_create();
	sfSprite_setTexture(SkullS, SkullT, sfTrue);
	sfSprite_setPosition(SkullS, posUnlock);
	sfSprite_setScale(SkullS, vector2f(0.14, 0.14));

	BookSpeechT = sfTexture_createFromFile(TEXTURE_PATH"Bookshelf.png", NULL);
	BookSpeechS = sfSprite_create();
	sfSprite_setTexture(BookSpeechS, BookSpeechT, sfTrue);
	
	sfSprite_setScale(BookSpeechS, vector2f(0.1, 0.1));

	PortalT = sfTexture_createFromFile(TEXTURE_PATH"PortalAcquired.png", NULL);
	PortalS = sfSprite_create();
	sfSprite_setTexture(PortalS, PortalT, sfTrue);
	sfSprite_setPosition(PortalS, vector2f(435, 752));
	sfSprite_setScale(PortalS, vector2f(0.1, 0.1));
	viewGamePosition.x = 100;
	viewGamePosition.y = 100;

	FirstSpeechT = sfTexture_createFromFile(TEXTURE_PATH"FirstSpeech.png", NULL);
	FirstSpeechS = sfSprite_create();
	sfSprite_setTexture(FirstSpeechS, FirstSpeechT, sfTrue);
	sfSprite_setPosition(FirstSpeechS, firstpos);
	sfSprite_setScale(FirstSpeechS, vector2f(0.1, 0.1));

	SecondSpeechT = sfTexture_createFromFile(TEXTURE_PATH"SecondSpeech.png", NULL);
	SecondSpeechS = sfSprite_create();
	sfSprite_setTexture(SecondSpeechS, SecondSpeechT, sfTrue);
	sfSprite_setPosition(SecondSpeechS, Secondpos);
	sfSprite_setScale(SecondSpeechS, vector2f(0.1, 0.1));

	ThirdSpeechT = sfTexture_createFromFile(TEXTURE_PATH"ThirdSpeech.png", NULL);
	ThirdSpeechS = sfSprite_create();
	sfSprite_setTexture(ThirdSpeechS, ThirdSpeechT, sfTrue);
	sfSprite_setPosition(ThirdSpeechS, thirdpos);
	sfSprite_setScale(ThirdSpeechS, vector2f(0.1, 0.1));
}

void displayPlayer(sfRenderWindow* _window)
{
	sfSprite_setTextureRect(PlayerSprite, Movement);

	animtime += GetDeltaTime();
	if (IsMoving == sfTrue)
	{
		if (animtime > 0.07)
		{
			FrameX++;
			if (FrameX > 8) FrameX = 0;
			Movement.left = FrameX * Movement.width;
			Movement.top = FrameY * Movement.height;
			sfSprite_setTextureRect(PlayerSprite, Movement);
			animtime = 0.0f;
		}
	}
	else
	{
		FrameX = 0;
		Movement.left = FrameX * Movement.width;
		sfSprite_setTextureRect(PlayerSprite, Movement);
	}


	sfSprite_setPosition(PlayerSprite, PosPlayer);
	sfSprite_setScale(PlayerSprite, scale2);

	sfRenderWindow_drawSprite(_window, PlayerSprite, &renderState);
	
	sfRenderWindow_drawSprite(_window, SkullS, NULL);
	if (timerunlock < 2 && timerunlock > 0)
	{
		sfRenderWindow_drawSprite(window, PortalS, NULL);
	}
	
}

void displaytexts(sfRenderWindow* window)
{
	if (Circle_Collision(vector2f(firstpos.x, firstpos.y+20), vector2f(PosPlayer.x, PosPlayer.y), 40, 40))
	{
		sfRenderWindow_drawSprite(window, FirstSpeechS, &renderState);
		
	}
	if (Circle_Collision(vector2f(Secondpos.x, Secondpos.y), vector2f(PosPlayer.x, PosPlayer.y), 30, 30) )
	{
		sfRenderWindow_drawSprite(window, SecondSpeechS, &renderState);
		
	}
	if (Circle_Collision(vector2f(thirdpos.x, thirdpos.y-10), vector2f(PosPlayer.x, PosPlayer.y), 20, 20) )
	{
		sfRenderWindow_drawSprite(window, ThirdSpeechS, &renderState);
		
	}

	if (Circle_Collision(vector2f(207, 85), vector2f(PosPlayer.x, PosPlayer.y), 20, 20))
	{
		sfSprite_setPosition(BookSpeechS, vector2f(PosPlayer.x-17, PosPlayer.y -40));
		sfRenderWindow_drawSprite(window, BookSpeechS, &renderState);

	}

	
	
	
}

void updatePlayer(sfRenderWindow* _window)
{
	if (state == GAME)
	{

		IsMoving = sfFalse;
		sfFloatRect playerfrect = sfSprite_getGlobalBounds(PlayerSprite);
		if (sfKeyboard_isKeyPressed(sfKeyZ) && PosPlayer.y > 0)
		{
			if (!collisionMapPlayer(playerfrect, UP, vitesse))
			{
				PosPlayer.y -= vitesse.y * GetDeltaTime();
				FrameY = UP;
				if (PosPlayer.y > (sfView_getSize(viewGame).y / 2) && PosPlayer.y < SizeMap.y - (sfView_getSize(viewGame).y / 2))
				{
					viewGamePosition.y = PosPlayer.y;
				}
			}


			IsMoving = sfTrue;
			animtime += GetDeltaTime();
		}


		else if (sfKeyboard_isKeyPressed(sfKeyS) && PosPlayer.y < 2365)
		{
			if (!collisionMapPlayer(playerfrect, DOWN, vitesse))
			{
				PosPlayer.y += vitesse.y * GetDeltaTime();
				FrameY = DOWN;
				if (PosPlayer.y > (sfView_getSize(viewGame).y / 2) && PosPlayer.y < SizeMap.y - (sfView_getSize(viewGame).y / 2))
				{
					viewGamePosition.y = PosPlayer.y;
				}

			}
			IsMoving = sfTrue;
			animtime += GetDeltaTime();
		}

		if (sfKeyboard_isKeyPressed(sfKeyQ) && PosPlayer.x > 0)
		{
			if (!collisionMapPlayer(playerfrect, LEFT, vitesse))
			{
				PosPlayer.x -= vitesse.x * GetDeltaTime();
				FrameY = LEFT;
				if (PosPlayer.x > (sfView_getSize(viewGame).x / 2) && PosPlayer.x < SizeMap.x - (sfView_getSize(viewGame).x / 2))
				{
					viewGamePosition.x = PosPlayer.x;
				}

			}
			IsMoving = sfTrue;

			animtime += GetDeltaTime();
		}

		else if (sfKeyboard_isKeyPressed(sfKeyD) && PosPlayer.x < 3170)
		{
			if (!collisionMapPlayer(playerfrect, RIGHT, vitesse))
			{

				PosPlayer.x += vitesse.x * GetDeltaTime();
				FrameY = RIGHT;
				if (PosPlayer.x > (sfView_getSize(viewGame).x / 2) && PosPlayer.x < SizeMap.x - (sfView_getSize(viewGame).x / 2))
				{
					viewGamePosition.x = PosPlayer.x;
				}

			}
			IsMoving = sfTrue;
			animtime += GetDeltaTime();
		}

		sfView_setCenter(viewGame, viewGamePosition);

		if (sfKeyboard_isKeyPressed(sfKeyBackspace))
		{
			state = MENU;
			
		}
		if (sfKeyboard_isKeyPressed(sfKeyNumpad6))
		{
			UnlockLibrary = sfTrue;

		}
		if (Circle_Collision(vector2f(posUnlock.x, posUnlock.y), vector2f(PosPlayer.x, PosPlayer.y), 20, 20))
		{

			UnlockLibrary = sfTrue;
			
			timerunlock += GetDeltaTime();
			
		}
		if (timerunlock < 2 && timerunlock > 0)
		{
			
			sfSprite_setPosition(SkullS, vector2f(422, 750));
			sfSprite_setScale(SkullS, vector2f(0.1, 0.1));
			
		}
		else if (timerunlock > 2)
		{
			sfSprite_setPosition(SkullS, vector2f(-3000, 200));
		}
		
	}

}



sfBool collisionMapPlayer(sfFloatRect _MaleSprite, Direction _direction, sfVector2f _vitesse)
{

	if (UnlockLibrary == sfTrue)
	{

		if (_direction == UP)
		{
			PlayerS.x = (int)_MaleSprite.left / 16;
			PlayerS.y = (int)(_MaleSprite.top - _vitesse.y * GetDeltaTime()) / 16;
			PlayerS2.x = (int)(_MaleSprite.left + _MaleSprite.width) / 16;
			PlayerS2.y = (int)(_MaleSprite.top - _vitesse.y * GetDeltaTime()) / 16;
			if (maphitbox[PlayerS.y][PlayerS.x] >= 1 && maphitbox[PlayerS.y][PlayerS.x] <= 1 || maphitbox[PlayerS2.y][PlayerS2.x] >= 1 && maphitbox[PlayerS2.y][PlayerS2.x] <= 1)
			{
				return sfTrue;
			}




		}
		else if (_direction == DOWN)
		{

			PlayerS.x = (int)(_MaleSprite.left) / 16;
			PlayerS.y = (int)(_MaleSprite.top + _MaleSprite.height + _vitesse.y * GetDeltaTime()) / 16;
			PlayerS2.x = (int)(_MaleSprite.left + _MaleSprite.width) / 16;
			PlayerS2.y = (int)(_MaleSprite.top + _MaleSprite.height + _vitesse.y * GetDeltaTime()) / 16;

			if (maphitbox[PlayerS.y][PlayerS.x] >= 1 && maphitbox[PlayerS.y][PlayerS.x] <= 1 || maphitbox[PlayerS2.y][PlayerS2.x] >= 1 && maphitbox[PlayerS2.y][PlayerS2.x] <= 1)
			{
				return sfTrue;
			}


		}

		else if (_direction == LEFT)
		{
			PlayerS.x = (int)(_MaleSprite.left - (_MaleSprite.width / 16) - _vitesse.x * GetDeltaTime()) / 16;
			PlayerS.y = (int)(_MaleSprite.top / 16);
			PlayerS2.x = (int)(_MaleSprite.left - _vitesse.x * GetDeltaTime()) / 16;
			PlayerS2.y = (int)(_MaleSprite.top + _MaleSprite.height) / 16;
			if (maphitbox[PlayerS.y][PlayerS.x] >= 1 && maphitbox[PlayerS.y][PlayerS.x] <= 1 || maphitbox[PlayerS2.y][PlayerS2.x] >= 1 && maphitbox[PlayerS2.y][PlayerS2.x] <= 1)
			{
				return sfTrue;
			}


		}
		else if (_direction == RIGHT)
		{
			PlayerS.x = (int)(_MaleSprite.left + _MaleSprite.width + _vitesse.x * GetDeltaTime()) / 16;
			PlayerS.y = (int)(_MaleSprite.top) / 16;
			PlayerS2.x = (int)(_MaleSprite.left + _MaleSprite.width + _vitesse.x * GetDeltaTime()) / 16;
			PlayerS2.y = (int)(_MaleSprite.top + _MaleSprite.height) / 16;

			if (maphitbox[PlayerS.y][PlayerS.x] >= 1 && maphitbox[PlayerS.y][PlayerS.x] <= 1 || maphitbox[PlayerS2.y][PlayerS2.x] >= 1 && maphitbox[PlayerS2.y][PlayerS2.x] <= 1)

			{
				return sfTrue;
			}
		}
		
	}
	if (UnlockLibrary == sfFalse)
	{

		if (_direction == UP)
		{
			PlayerS.x = (int)_MaleSprite.left / 16;
			PlayerS.y = (int)(_MaleSprite.top - _vitesse.y * GetDeltaTime()) / 16;
			PlayerS2.x = (int)(_MaleSprite.left + _MaleSprite.width) / 16;
			PlayerS2.y = (int)(_MaleSprite.top - _vitesse.y * GetDeltaTime()) / 16;
			if (maphitbox[PlayerS.y][PlayerS.x] >= 1 && maphitbox[PlayerS.y][PlayerS.x] <= 2 || maphitbox[PlayerS2.y][PlayerS2.x] >= 1 && maphitbox[PlayerS2.y][PlayerS2.x] <= 2)
			{
				return sfTrue;
			}




		}
		else if (_direction == DOWN)
		{

			PlayerS.x = (int)(_MaleSprite.left) / 16;
			PlayerS.y = (int)(_MaleSprite.top + _MaleSprite.height + _vitesse.y * GetDeltaTime()) / 16;
			PlayerS2.x = (int)(_MaleSprite.left + _MaleSprite.width) / 16;
			PlayerS2.y = (int)(_MaleSprite.top + _MaleSprite.height + _vitesse.y * GetDeltaTime()) / 16;

			if (maphitbox[PlayerS.y][PlayerS.x] >= 1 && maphitbox[PlayerS.y][PlayerS.x] <= 2 || maphitbox[PlayerS2.y][PlayerS2.x] >= 1 && maphitbox[PlayerS2.y][PlayerS2.x] <= 2)
			{
				return sfTrue;
			}


		}

		else if (_direction == LEFT)
		{
			PlayerS.x = (int)(_MaleSprite.left - (_MaleSprite.width / 16) - _vitesse.x * GetDeltaTime()) / 16;
			PlayerS.y = (int)(_MaleSprite.top / 16 +1);
			PlayerS2.x = (int)(_MaleSprite.left - _vitesse.x * GetDeltaTime()) / 16;
			PlayerS2.y = (int)(_MaleSprite.top + _MaleSprite.height) / 16;
			if (maphitbox[PlayerS.y][PlayerS.x] >= 1 && maphitbox[PlayerS.y][PlayerS.x] <= 2 || maphitbox[PlayerS2.y][PlayerS2.x] >= 2 && maphitbox[PlayerS2.y][PlayerS2.x] <= 2)
			{
				return sfTrue;
			}


		}
		else if (_direction == RIGHT)
		{
			PlayerS.x = (int)(_MaleSprite.left + _MaleSprite.width + _vitesse.x * GetDeltaTime()) / 16;
			PlayerS.y = (int)(_MaleSprite.top) / 16;
			PlayerS2.x = (int)(_MaleSprite.left + _MaleSprite.width + _vitesse.x * GetDeltaTime()) / 16;
			PlayerS2.y = (int)(_MaleSprite.top + _MaleSprite.height) / 16;

			if (maphitbox[PlayerS.y][PlayerS.x] >= 1 && maphitbox[PlayerS.y][PlayerS.x] <= 2  || maphitbox[PlayerS2.y][PlayerS2.x] >= 1 && maphitbox[PlayerS2.y][PlayerS2.x] <= 2)

			{
				return sfTrue;
			}
		}
	
	}

	return sfFalse;

}