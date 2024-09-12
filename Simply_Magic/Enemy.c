#include"tools.h"
#include"Player.h"
#include"music.h"
#include"Lighting.h"
sfSprite* EnemyS;
sfTexture* EnemyT;

sfSprite* Enemy2S;
sfTexture* Enemy2T;

sfSprite* Enemy3S;
sfTexture* Enemy3T;

sfSprite* RunS;
sfSprite* RunS2;
sfTexture* RunT;

sfSprite* HideS;
sfTexture* HideT;

sfSprite* StopS;
sfTexture* StopT;

sfSprite* AttackS;
sfTexture* AttackT;

sfSprite* MenuEscS;
sfTexture* MenuEscT;

sfSprite* VictoryS;
sfTexture* VictoryT;

sfSprite* DeathscreenS;
sfTexture* DeathscreenT;

sfSprite* DeathskullS;
sfTexture* DeathskullT;

sfSprite* TurnS;
sfTexture* TurnT;

sfSprite* DeathS;
sfTexture* DeathT;

sfSprite* WallMessageS;
sfTexture* WallMessageT;

sfSprite* Boss1S;
sfTexture* Boss1T;

sfSprite* ThankS;
sfTexture* ThankT;

sfBool activate = sfFalse;
sfBool Deathbool = sfFalse;
sfBool bossmove1;
sfBool bossmove2;
sfBool bossmove3;
sfBool bossmove4;

sfIntRect scaryman = {0, 0, 16, 15};

sfVector2f posEnemy = { 426, 800 };
sfVector2f posEnemy2 = { 1150, 1125 };
sfVector2f posEnemy3 = { 1120, 425 };
sfVector2f posboss1 = { 90, 1050 };
sfVector2f speedEnemy = { 100, 100 };
sfVector2f speedEnemy2 = { 110, 110 };
sfBool enemymoving = sfFalse;
sfBool enemymovingright = sfFalse;
sfBool enemymovingLeft = sfFalse;
sfBool enemymovingUp = sfFalse;

sfBool enemymoving2 = sfFalse;
sfBool enemymovingright2 = sfFalse;
sfBool enemymovingLeft2 = sfFalse;
sfBool enemymovingFirst = sfFalse;

sfBool enemymoving3 = sfFalse;
sfBool enemymovingright3 = sfFalse;
sfBool enemymovingLeft3 = sfFalse;
sfBool enemymovingDown3 = sfFalse;
sfBool enemymovingUp3 = sfFalse;


sfBool finalmessage = sfFalse;


sfSprite* SignS;
sfTexture* SignT;

sfIntRect skullrect = { 0,0,223, 284 };

int FrameD = 0;
int FrameZ = 0;
int FrameL = 0;
float animtime2;
float animerun;
float animehide;
float animeenemy;
float animeenemy3;
float keytimer2;
float messagetimer;
float bosstimer;

void initEnemy()
{
	EnemyT = sfTexture_createFromFile(TEXTURE_PATH"ScaryMan.png", NULL);
	EnemyS = sfSprite_create();
	sfSprite_setTexture(EnemyS, EnemyT, sfTrue);

	VictoryT = sfTexture_createFromFile(TEXTURE_PATH"Victory.jpg", NULL);
	VictoryS = sfSprite_create();
	sfSprite_setTexture(VictoryS, VictoryT, sfTrue);
	sfSprite_scale(VictoryS, vector2f(1, 1.2));

	ThankT = sfTexture_createFromFile(TEXTURE_PATH"Thanks.png", NULL);
	ThankS = sfSprite_create();
	sfSprite_setTexture(ThankS, ThankT, sfTrue);
	sfSprite_scale(ThankS, vector2f(1, 1.2));
	sfSprite_setPosition(ThankS, vector2f(100,300));

	Enemy2T = sfTexture_createFromFile(TEXTURE_PATH"ScaryMan.png", NULL);
	Enemy2S = sfSprite_create();
	sfSprite_setTexture(Enemy2S, Enemy2T, sfTrue);

	Enemy3T = sfTexture_createFromFile(TEXTURE_PATH"ScaryMan.png", NULL);
	Enemy3S = sfSprite_create();
	sfSprite_setTexture(Enemy3S, Enemy3T, sfTrue);

	DeathscreenT = sfTexture_createFromFile(TEXTURE_PATH"DeathBackground.png", NULL);
	DeathscreenS = sfSprite_create();
	sfSprite_setTexture(DeathscreenS, DeathscreenT, sfTrue);
	//sfSprite_setPosition(DeathscreenS, vector2f(PosPlayer.x-100, PosPlayer.y-100));

	DeathskullT = sfTexture_createFromFile(TEXTURE_PATH"Deathscreen.png", NULL);
	DeathskullS = sfSprite_create();
	sfSprite_setTexture(DeathskullS, DeathskullT, sfTrue);
	sfSprite_scale(DeathskullS, vector2f(1.2, 1.2));
	sfSprite_setPosition(DeathskullS, vector2f(2, -100));

	Boss1T = sfTexture_createFromFile(TEXTURE_PATH"ScaryMan.png", NULL);
	Boss1S = sfSprite_create();
	sfSprite_setTexture(Boss1S, Boss1T, sfTrue);
	sfSprite_setPosition(Boss1S, posboss1);

	WallMessageT = sfTexture_createFromFile(TEXTURE_PATH"WALLMESSAGE.png", NULL);
	WallMessageS = sfSprite_create();
	sfSprite_setTexture(WallMessageS, WallMessageT, sfTrue);
	sfSprite_setScale(WallMessageS, vector2f(0.5, 0.5));
	sfSprite_setPosition(WallMessageS, vector2f(60, 385));


	RunT = sfTexture_createFromFile(TEXTURE_PATH"RUN.png", NULL);
	RunS = sfSprite_create();
	RunS2 = sfSprite_create();
	sfSprite_setTexture(RunS, RunT, sfTrue);
	sfSprite_setTexture(RunS2, RunT, sfTrue);
	sfSprite_setScale(RunS, vector2f(0.6, 0.6));
	sfSprite_setScale(RunS2, vector2f(0.6, 0.6));
	sfSprite_setPosition(RunS, vector2f(320, 565));
	sfSprite_setPosition(RunS2, vector2f(1155, 250));

	HideT = sfTexture_createFromFile(TEXTURE_PATH"HIDE.png", NULL);
	HideS = sfSprite_create();
	sfSprite_setTexture(HideS, HideT, sfTrue);
	sfSprite_setScale(HideS, vector2f(0.6, 0.6));
	sfSprite_setPosition(HideS, vector2f(880, 1170));

	AttackT = sfTexture_createFromFile(TEXTURE_PATH"Attack.png", NULL);
	AttackS = sfSprite_create();
	sfSprite_setTexture(AttackS, AttackT, sfTrue);
	sfSprite_setScale(AttackS, vector2f(0.2, 0.2));
	sfSprite_setPosition(AttackS, vector2f(245, 940));

	TurnT = sfTexture_createFromFile(TEXTURE_PATH"turnback.png", NULL);
	TurnS = sfSprite_create();
	sfSprite_setTexture(TurnS, TurnT, sfTrue);
	sfSprite_setScale(TurnS, vector2f(0.2, 0.2));
	sfSprite_setPosition(TurnS, vector2f(200, 656));

	StopT = sfTexture_createFromFile(TEXTURE_PATH"STOP.png", NULL);
	StopS = sfSprite_create();
	sfSprite_setTexture(StopS, StopT, sfTrue);
	sfSprite_setScale(StopS, vector2f(0.3, 0.3));
	sfSprite_setPosition(StopS, vector2f(300, 552));

	MenuEscT = sfTexture_createFromFile(TEXTURE_PATH"EscapeMenu.png", NULL);
	MenuEscS = sfSprite_create();
	sfSprite_setTexture(MenuEscS, MenuEscT, sfTrue);
	sfSprite_setScale(MenuEscS, vector2f(0.3, 0.3));
	sfSprite_setPosition(MenuEscS, vector2f(1, 10));

	DeathT = sfTexture_createFromFile(TEXTURE_PATH"Death.png", NULL);
	DeathS = sfSprite_create();
	sfSprite_setTexture(DeathS, DeathT, sfTrue);
	sfSprite_setScale(DeathS, vector2f(0.2, 0.2));
	sfSprite_setPosition(DeathS, vector2f(310, 756));

	SignT = sfTexture_createFromFile(TEXTURE_PATH"Sign.png", NULL);
	SignS = sfSprite_create();
	sfSprite_setTexture(SignS, SignT, sfTrue);
	sfSprite_setScale(SignS, vector2f(0.3, 0.3));
	sfSprite_setPosition(SignS, vector2f(528, 406));
}

void displayfinalmessage(sfRenderWindow* window)
{

	if ((PosPlayer.x > 285 && PosPlayer.x < 292) && (PosPlayer.y > 552))
	{
		finalmessage = sfTrue;
	}

	if (finalmessage == sfTrue)
	{
		messagetimer += GetDeltaTime();
	}

	if (messagetimer > 0 && messagetimer < 1)
	{
		sfRenderWindow_drawSprite(window, StopS, NULL);
	}
	if (messagetimer > 1 && messagetimer < 2.5)
	{
		sfRenderWindow_drawSprite(window, TurnS, NULL);
	}
	if (messagetimer > 2.5 && messagetimer < 6)
	{
		sfRenderWindow_drawSprite(window, DeathS, NULL);
		
	}
	if (messagetimer >= 3)
	{
		bosstimer += GetDeltaTime();
		

	}
	if (messagetimer > 3 && messagetimer < 7)
	{
		sfRenderWindow_drawSprite(window, AttackS, NULL);
	}
}

void displayEnemy3(sfRenderWindow* window)
{
	
	sfSprite_setTextureRect(DeathskullS, skullrect);
	
	
	if (sfKeyboard_isKeyPressed(sfKeyNum1))
	{
		enemymoving3 = sfTrue;
	}
	if (enemymoving3 == sfTrue )
	{
		animeenemy3 += GetDeltaTime();
		sfRenderWindow_drawSprite(window, RunS2, NULL);
		
	}
	if (animeenemy3 < 0.5 && animeenemy3 > 0)
	{
		enemymovingright3 = sfTrue;
		enemymovingUp3 = sfTrue;
	}

	if (animeenemy3 > 0.5 && animeenemy3 < 1)
	{
		enemymovingright3 = sfFalse;
		sfSprite_setPosition(RunS2, vector2f(-2250, 520));
	}
	if ((posEnemy3.x > 1150 && posEnemy3.x < 1190) && (posEnemy3.y > 163 && posEnemy3.y < 167))
	{
		enemymovingUp3 = sfFalse;
		enemymovingLeft3 = sfTrue;
		
	}
	if ((posEnemy3.x > 986 && posEnemy3.x < 1000) && (posEnemy3.y > 155 && posEnemy3.y < 185))
	{
		
		enemymovingright3 = sfFalse;
		enemymovingLeft3 = sfFalse;
		enemymovingDown3 = sfTrue;
	}
	if ((posEnemy3.x > 985 && posEnemy3.x < 1010) && (posEnemy3.y > 328 && posEnemy3.y < 340))
	{
		enemymovingDown3 = sfFalse;
		enemymovingLeft3 = sfTrue;
	}
	if ((posEnemy3.x > 950 && posEnemy3.x < 960) && (posEnemy3.y > 328 && posEnemy3.y < 340))
	{
		enemymovingDown3 = sfTrue;
		enemymovingLeft3 = sfFalse;
	}
	if ((posEnemy3.x > 952 && posEnemy3.x < 985) && (posEnemy3.y > 746 && posEnemy3.y < 756))
	{
		enemymovingDown3 = sfFalse;
		enemymovingLeft3 = sfTrue;
	}
	if ((posEnemy3.x > 863 && posEnemy3.x < 875) && (posEnemy3.y > 743 && posEnemy3.y < 770))
	{
		enemymovingUp3 = sfTrue;
		enemymovingLeft3 = sfFalse;
	}
	if ((posEnemy3.x > 854 && posEnemy3.x < 885) && (posEnemy3.y > 590 && posEnemy3.y < 596))
	{
		enemymovingUp3 = sfFalse;
		enemymovingLeft3 = sfTrue;
	}
	if ((posEnemy3.x > 798 && posEnemy3.x < 810) && (posEnemy3.y > 575 && posEnemy3.y < 610))
	{
		enemymovingUp3 = sfTrue;
		enemymovingLeft3 = sfFalse;
	}
	if ((posEnemy3.x > 790 && posEnemy3.x < 818) && (posEnemy3.y > 158 && posEnemy3.y < 165))
	{
		enemymovingUp3 = sfFalse;
		enemymovingLeft3 = sfTrue;
	}
	if ((posEnemy3.x > 712 && posEnemy3.x < 731) && (posEnemy3.y > 155 && posEnemy3.y < 177))
	{
		enemymovingUp3 = sfTrue;
		enemymovingLeft3 = sfFalse;
	}
	if ((posEnemy3.x > 712 && posEnemy3.x < 737) && (posEnemy3.y > 47 && posEnemy3.y < 59))
	{
		enemymovingUp3 = sfFalse;
		enemymovingright3 = sfTrue;///////
	}
	if ((posEnemy3.x > 932 && posEnemy3.x < 943) && (posEnemy3.y > 42 && posEnemy3.y < 72))
	{
		enemymovingright3 = sfFalse;
		enemymovingDown3 = sfTrue;
	}
	if ((posEnemy3.x > 927 && posEnemy3.x < 955) && (posEnemy3.y > 160 && posEnemy3.y < 170))
	{
		enemymovingright3 = sfTrue;
		enemymovingDown3 = sfFalse;
	}
	
	if (enemymovingright3 == sfTrue)
	{
		posEnemy3.x += speedEnemy.x * GetDeltaTime();
	}

	if (enemymovingLeft3 == sfTrue)
	{

		posEnemy3.x -= speedEnemy.x * GetDeltaTime();
	}
	if (enemymovingDown3 == sfTrue)
	{
		posEnemy3.y += speedEnemy.y * GetDeltaTime();
	}

	if (enemymovingUp3 == sfTrue)
	{

		posEnemy3.y -= speedEnemy.y * GetDeltaTime();
	}
	
}

void displayEnemy(sfRenderWindow* window)
{
	sfSprite_setTextureRect(EnemyS, scaryman);
	sfSprite_setTextureRect(Enemy2S, scaryman);
	sfSprite_setTextureRect(Enemy3S, scaryman);
	sfSprite_setTextureRect(Boss1S, scaryman);

	animtime2 += GetDeltaTime();
	

	if (animtime2 > 0.12)
	{
		FrameD++;
		if (FrameD > 5) FrameD = 0;
		scaryman.left = FrameD * scaryman.width;
		sfSprite_setTextureRect(EnemyS, scaryman);
		animtime2 = 0.0f;
	}


	sfRenderWindow_drawSprite(window, SignS, NULL);
	sfRenderWindow_drawSprite(window, EnemyS, NULL);
	sfRenderWindow_drawSprite(window, Enemy2S, NULL);
	sfRenderWindow_drawSprite(window, Enemy3S, NULL);
	sfRenderWindow_drawSprite(window, Boss1S, NULL);
	sfRenderWindow_drawSprite(window, WallMessageS, &renderState);
	sfSprite_setPosition(EnemyS, posEnemy);
	sfSprite_setPosition(Enemy2S, posEnemy2);
	sfSprite_setPosition(Enemy3S, posEnemy3);

	if (Circle_Collision(vector2f(PosPlayer.x+2, PosPlayer.y), vector2f(posboss1.x,posboss1.y), 5, 5 ) && bosstimer > 0.2 && bossmove1 == sfFalse)
	{
		sfSprite_setPosition(Boss1S, vector2f(190,1050));
		sfSound_play(OuchSound);
		bossmove1 = sfTrue;
		
		bosstimer = 0;
	}
	
	if (Circle_Collision(vector2f(PosPlayer.x+2, PosPlayer.y), vector2f(190, 1050), 5, 5) )
	{
		sfSprite_setPosition(Boss1S, vector2f(450, 1050));
		
	
	}
	if (Circle_Collision(vector2f(PosPlayer.x+2, PosPlayer.y), vector2f(450, 1050), 5, 5) && bossmove2 == sfFalse)
	{
		sfSprite_setPosition(Boss1S, vector2f(280, 1150));
		sfSound_play(OuchSound);
		bossmove2 = sfTrue;
	}
	if (Circle_Collision(vector2f(PosPlayer.x+2, PosPlayer.y), vector2f(280, 1150), 5, 5) && bossmove2 == sfTrue)
	{
		state = END;
		
	}
	if (state == END)
	{
		sfRenderWindow_drawSprite(window, VictoryS, NULL);
		sfRenderWindow_drawSprite(window, ThankS, NULL);
		sfSound_stop(FinalSectionSound);
		
	}
	
	

	if ((PosPlayer.x > 400 && PosPlayer.x < 450) && (PosPlayer.y > 600 && PosPlayer.y < 639) && enemymoving == sfFalse)
	{
		sfSound_play(EnemySound);
		sfSound_play(ChaseSound);
		
		enemymoving = sfTrue;
		enemymovingUp = sfTrue;
	}
	if ((PosPlayer.x > 900 && PosPlayer.x < 940) && (PosPlayer.y > 1110 && PosPlayer.y < 1160) && enemymoving2 == sfFalse)
	{

		sfSound_play(EnemySound);
		sfSound_play(ChaseSound);
		enemymoving2 = sfTrue;
		

	}
	if ((PosPlayer.x > 1150 && PosPlayer.x < 1190) && (PosPlayer.y > 300 && PosPlayer.y < 321) && enemymoving3 == sfFalse)
	{
		
		sfSound_play(EnemySound);
		sfSound_play(ChaseSound);
		enemymoving3 = sfTrue;

	}
	if (enemymoving == sfTrue)
	{

		sfRenderWindow_drawSprite(window, RunS, NULL);



		animerun += GetDeltaTime();
		animeenemy += GetDeltaTime();
	}
	if (enemymoving2 == sfTrue)
	{
		sfRenderWindow_drawSprite(window, HideS, NULL);
		animehide += GetDeltaTime();
	}
	if (posEnemy2.x >= 1149 && enemymoving2 == sfTrue)
	{
		enemymovingLeft2 = sfTrue;
		enemymovingright2 = sfFalse;
	}
	if (posEnemy2.x <= 660 && enemymoving2 == sfTrue)
	{
		enemymovingLeft2 = sfFalse;
		enemymovingright2 = sfTrue;
	}
	if (animeenemy > 3)
	{
		enemymovingright = sfTrue;

	}
	if (animeenemy > 4)
	{
		enemymovingright = sfFalse;

	}
	if (animeenemy > 6)
	{
		enemymovingLeft = sfTrue;
		enemymovingUp = sfFalse;
	}
	if (animeenemy > 8)
	{
		
		activate = sfTrue;

		posEnemy.y = -3300;
		
	}
	if (enemymovingright == sfTrue)
	{
		posEnemy.x += speedEnemy.x * GetDeltaTime();
	}
	if (enemymovingright2 == sfTrue)
	{
		posEnemy2.x += speedEnemy2.x * GetDeltaTime();
	}

	if (enemymovingLeft == sfTrue)
	{

		posEnemy.x -= speedEnemy.x * GetDeltaTime();
	}
	if (enemymovingLeft2 == sfTrue)
	{
		posEnemy2.x -= speedEnemy2.x * GetDeltaTime();
	}
	if (enemymovingUp == sfTrue)
	{
		posEnemy.y -= speedEnemy.y * GetDeltaTime();

	}

	if (animerun > 1.5)
	{
		sfSprite_setPosition(RunS, vector2f(-2250, 520));
	}
	if (animehide > 1.5)
	{
		sfSprite_setPosition(HideS, vector2f(-2250, 520));
	}

	
	
}
void viewfinal()
{
	if ((PosPlayer.x > 837 && PosPlayer.x < 866) && (PosPlayer.y > 442 && PosPlayer.y < 460))
	{
		PosPlayer.x = 100;
		PosPlayer.y = 800;

		sfSprite_setPosition(PlayerSprite, vector2f(20, 520));

		//	sfView_reset(viewGame, FlRect(500.0f, 150.0f, 200.0f, 150.0f));
			//sfRenderWindow_setView(window, viewGame);		
		sfSound_play(FinalSectionSound);
		sfSound_stop(FirstSectionSound);
		sfSound_stop(FirstSectionSound2);
	}
}



void updateEnemy(sfRenderWindow* window)
{
	//printf("%f\n\n", PosPlayer.x);
	//printf("\n%f", PosPlayer.y);
	keytimer2 += GetDeltaTime();

	if (Circle_Collision(vector2f(posEnemy.x, posEnemy.y), vector2f(PosPlayer.x, PosPlayer.y), 20, 20) || sfKeyboard_isKeyPressed(sfKeyNumpad0) && keytimer2 > 0.2)
	{
		Deathbool = sfTrue;
		state = DEATH;
		sfView_reset(viewMenu, FlRect(200.0f, 150.0f, 400.0f, 300.0f));
		sfView_setCenter(viewMenu, vector2f(50, 50));
		sfRenderWindow_setView(window, viewMenu);
		//sfView_zoom(viewMenu, 1);
		
		
		keytimer2 = 0;
	}
	if (Circle_Collision(vector2f(posEnemy2.x, posEnemy2.y), vector2f(PosPlayer.x, PosPlayer.y), 20, 20) || sfKeyboard_isKeyPressed(sfKeyNumpad0) && keytimer2 > 0.2)
	{
		Deathbool = sfTrue;
		state = DEATH;
		sfView_reset(viewMenu, FlRect(200.0f, 150.0f, 400.0f, 300.0f));
		sfView_setCenter(viewMenu, vector2f(50, 50));
		sfRenderWindow_setView(window, viewMenu);
		keytimer2 = 0;
	}
	if (Circle_Collision(vector2f(posEnemy3.x, posEnemy3.y), vector2f(PosPlayer.x, PosPlayer.y), 20, 20) || sfKeyboard_isKeyPressed(sfKeyNumpad0) && keytimer2 > 0.2)
	{
		Deathbool = sfTrue;
		state = DEATH;
		sfView_reset(viewMenu, FlRect(200.0f, 150.0f, 400.0f, 300.0f));
		sfView_setCenter(viewMenu, vector2f(50, 50));
		sfRenderWindow_setView(window, viewMenu);
		keytimer2 = 0;
	}
}
void displaydeath(sfRenderWindow* window)
{
	
	

	skulltimer += GetDeltaTime();
	
	
	
		sfRenderWindow_drawSprite(window, DeathscreenS, NULL);
		sfRenderWindow_drawSprite(window, DeathskullS, NULL);
		sfRenderWindow_drawSprite(window, MenuEscS, NULL);

		if (skulltimer > 0.8)
		{
			FrameL++;
			if (FrameL > 4) FrameL = 0;
			skullrect.left = FrameL * skullrect.width;

			sfSprite_setTextureRect(DeathskullS, skullrect);
			skulltimer = 0.0f;
		}

		if (sfKeyboard_isKeyPressed(sfKeyEscape) && skulltimer > 0.2)
		{
			sfWindow_close(window);
			
		}
	
}