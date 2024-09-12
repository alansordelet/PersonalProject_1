#include"tools.h"
#include"music.h"

sfSprite* BackgroundS;
sfTexture* BackgroundT;

sfSprite* PlayS;
sfTexture* PlayT;

sfSprite* Play2S;
sfTexture* Play2T;

sfSprite* TitleS;
sfTexture* TitleT;

sfSprite* OptionsBackS;
sfTexture* OptionsBackT;

sfSprite* OptionsS;
sfTexture* OptionsT;
sfTexture* Options2T;

sfSprite* BackS;
sfTexture* BackT;
sfTexture* Back2T;

sfSprite* EditorS;
sfTexture* EditorT;
sfTexture* Editor2T;

sfSprite* ExitS;
sfTexture* ExitT;
sfTexture* Exit2T;

float mousetimer;
float mousetimer2;
float soundclicktimemenu;

void initmenu()
{
	BackgroundT = sfTexture_createFromFile(TEXTURE_PATH"peakpx.jpg", NULL);
	BackgroundS = sfSprite_create();
	sfSprite_setTexture(BackgroundS, BackgroundT, sfTrue);
	sfSprite_setScale(BackgroundS, vector2f(1, 1.2));

	TitleT = sfTexture_createFromFile(TEXTURE_PATH"TITLE.png", NULL);
	TitleS = sfSprite_create();
	sfSprite_setTexture(TitleS, TitleT, sfTrue);
	sfSprite_setScale(TitleS, vector2f(1, 1)); 
	sfSprite_setPosition(TitleS, vector2f(10, 30));

	PlayT = sfTexture_createFromFile(TEXTURE_PATH"Play.png", NULL);
	PlayS = sfSprite_create();
	sfSprite_setTexture(PlayS, PlayT, sfTrue);
	sfSprite_setScale(PlayS, vector2f(0.9, 0.9));
	sfSprite_setPosition(PlayS, vector2f(50, 630));


	Play2T = sfTexture_createFromFile(TEXTURE_PATH"PlayHighlight.png", NULL);
	Play2S = sfSprite_create();
	sfSprite_setTexture(Play2S, Play2T, sfTrue);
	sfSprite_setScale(Play2S, vector2f(0.9, 0.9));

	OptionsBackT = sfTexture_createFromFile(TEXTURE_PATH"OptionsBack.jpg", NULL);
	OptionsBackS = sfSprite_create();
	sfSprite_setTexture(OptionsBackS, OptionsBackT, sfTrue);
	sfSprite_setScale(OptionsBackS, vector2f(0.9, 1.15));

	OptionsT = sfTexture_createFromFile(TEXTURE_PATH"Options.png", NULL);
	Options2T = sfTexture_createFromFile(TEXTURE_PATH"OptionsHighlight.png", NULL);
	OptionsS = sfSprite_create();
	sfSprite_setTexture(OptionsS, OptionsT, sfTrue);
	sfSprite_setScale(OptionsS, vector2f(0.9, 0.9)); 
	sfSprite_setPosition(OptionsS, vector2f(50, 710));

	EditorT = sfTexture_createFromFile(TEXTURE_PATH"EditorMode.png", NULL);
	Editor2T = sfTexture_createFromFile(TEXTURE_PATH"EditorModeHigh.png", NULL);
	EditorS = sfSprite_create();
	sfSprite_setTexture(EditorS, EditorT, sfTrue);
	sfSprite_setScale(EditorS, vector2f(0.9, 0.9));
	sfSprite_setPosition(EditorS, vector2f(50, 630));

	BackT = sfTexture_createFromFile(TEXTURE_PATH"Back.png", NULL);
	Back2T = sfTexture_createFromFile(TEXTURE_PATH"BackHighlight.png", NULL);
	BackS = sfSprite_create();
	sfSprite_setTexture(BackS, BackT, sfTrue);
	sfSprite_setScale(BackS, vector2f(0.9, 0.9));
	sfSprite_setPosition(BackS, vector2f(750, 90));

	ExitT = sfTexture_createFromFile(TEXTURE_PATH"Exit.png", NULL);
	Exit2T = sfTexture_createFromFile(TEXTURE_PATH"ExitHighlight.png", NULL);
	ExitS = sfSprite_create();
	sfSprite_setTexture(ExitS, ExitT, sfTrue);
	sfSprite_setScale(ExitS, vector2f(0.9, 0.9));
	sfSprite_setPosition(ExitS, vector2f(720, 20));
}
void updateMenu(sfRenderWindow* _window)
{
	if (state == MENU)
	{
		if (sfKeyboard_isKeyPressed(sfKeySpace) )
		{
			state = EDITOR;
			sfMusic_pause(MusicIntro);

			
		}
	}

}
void displaymenu(sfRenderWindow* window)
{
	mousetimer += GetDeltaTime();
	mousetimer2 += GetDeltaTime();


	sfVector2i mousepose = sfMouse_getPositionRenderWindow(window);
	sfVector2f curseurpos = vector2f((float)mousepose.x, (float)mousepose.y);
	if (state == MENU)
	{
		sfRenderWindow_drawSprite(window, BackgroundS, NULL);
		sfRenderWindow_drawSprite(window, PlayS, NULL);
		sfRenderWindow_drawSprite(window, ExitS, NULL);
		sfRenderWindow_drawSprite(window, OptionsS, NULL);
		sfRenderWindow_drawSprite(window, TitleS, NULL);
		
		if (curseurpos.x > 50 && curseurpos.x < 300 && curseurpos.y > 630 && curseurpos.y < 690)
		{
			sfSprite_setTexture(PlayS, Play2T, sfTrue);
			if (sfMouse_isButtonPressed(sfMouseLeft) && mousetimer > 0.2)
			{
				sfMusic_pause(MusicIntro);
				sfSound_play(introSound);
				sfSound_play(FirstSectionSound);
				sfView_reset(viewGame, FlRect(500.0f, 1500.0f, 200.0f, 150.0f));
				sfView_setCenter(viewGame, vector2f(PosPlayer.x, PosPlayer.y));
				sfRenderWindow_setView(window, viewGame);
				state = GAME;
				mousetimer = 0;
			}
	    }
		else
		{
			sfSprite_setTexture(PlayS, PlayT, sfTrue);
		}
		if (curseurpos.x > 50 && curseurpos.x < 300 && curseurpos.y > 710 && curseurpos.y < 770)
		{
			sfSprite_setTexture(OptionsS, Options2T, sfTrue);
			if (sfMouse_isButtonPressed(sfMouseLeft) && mousetimer > 0.2)
			{
				state = OPTIONS;
			}
		}
		else
		{
			sfSprite_setTexture(OptionsS, OptionsT, sfTrue);
		}
		if (curseurpos.x > 720 && curseurpos.x < 970 && curseurpos.y > 20 && curseurpos.y < 80)
		{
			sfSprite_setTexture(ExitS, Exit2T, sfTrue);
			if (sfMouse_isButtonPressed(sfMouseLeft) && mousetimer > 0.2)
			{
				sfWindow_close(window);
			}
		}
		else
		{
			sfSprite_setTexture(ExitS, ExitT, sfTrue);
		}
	}
	if (state == OPTIONS)
	{

		sfRenderWindow_drawSprite(window, OptionsBackS, NULL);
		sfRenderWindow_drawSprite(window, BackS, NULL);
		sfRenderWindow_drawSprite(window, EditorS, NULL);
		if (curseurpos.x > 50 && curseurpos.x < 300 && curseurpos.y > 630 && curseurpos.y < 690)
		{
			sfSprite_setTexture(EditorS, Editor2T, sfTrue);
			if (sfMouse_isButtonPressed(sfMouseLeft) && mousetimer > 0.5)
			{
				state = EDITOR;
				//sfMusic_pause(MusicIntro);
			}
		}
		else
		{
			sfSprite_setTexture(EditorS, EditorT, sfTrue);
		}
		if (curseurpos.x > 750 && curseurpos.x < 980 && curseurpos.y > 90 && curseurpos.y < 150)
		{
			sfSprite_setTexture(BackS, Back2T, sfTrue);
			if (sfMouse_isButtonPressed(sfMouseLeft) && mousetimer > 0.2)
			{
				state = MENU;
			}
		}
		else
		{
			sfSprite_setTexture(BackS, BackT, sfTrue);
		}

		/*if (Circle_Collision(, vector2f(curseurpos.x, curseurpos.y), 20, 20))
		{
			MusicVolume -= 10.0f;
			setMusicVolume(MusicVolume);
		}*/
		//if (sfMouse_isButtonPressed(sfMouseLeft) && soundclicktimemenu > 0.1)
		//{

		//	if (Circle_Collision(vector2f(50, 50), curseurpos, 20, 20) == sfTrue)
		//	{
		//		MusicVolume -= 10.0f;
		//		setMusicVolume(MusicVolume);
		//		//SetVolume(MUSIC, -10);
		//	}
		//	//if (Circle_Collision(positionsoundplus, curseurpos, 20, 20) == sfTrue)
		//	//{
		//	//	SFXVolume += 10.0f;
		//	//	setMusicVolume(musicVolume);
		//	//	//SetVolume(MUSIC, +10);
		//	//}
		//	if (Circle_Collision(positionfxminus, curseurpos, Rayonmousemenu, Rayonupdatesound) == sfTrue)
		//	{
		//		SFXVolume -= 10.0f;
		//		setSoundVolume(SFXVolume);
		//	}
		//	if (Circle_Collision(positionfxplus, curseurpos, Rayonmousemenu, Rayonupdatesound) == sfTrue)
		//	{
		//		SFXVolume += 10.0f;
		//		setSoundVolume(+10);
		//	}
		//	soundclicktimemenu = 0.0f;
		//}
		//
	}
	
}