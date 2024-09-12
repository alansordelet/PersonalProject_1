#include "tools.h"
#include <windows.h>
#include"SFML/Audio.h"
#include"time.h"
#include"map.h"
#include"Lighting.h"
#include"music.h"







int main()
{

	sfVideoMode mode = { 1000, 800, 32 };
	
	window = sfRenderWindow_create(mode, "Hide and Be Seeked", sfDefaultStyle, NULL);
	sfclock = sfClock_create();
	sfEvent event;

	
	

	viewEditor = sfView_create();
	viewGame = sfView_create();

	viewMenu = sfView_create();

	//sfView_reset(viewMenu, FlRect(200.0f, 150.0f, 400.0f, 300.0f));
	//sfView_zoom(viewMenu, 2);
	//sfView_setViewport(viewMenu, FlRect(0.0, 0.0, 1.0, 1.0));
	//sfView_setCenter(viewMenu, vector2f(1000, 300.0f));

	state = MENU;
	musicinit();
	PlayerInit();
	initEnemy();
	initMap();
	initMapInside();
	initMapHitBox();
	initmenu();
	MusicIntroPlay();
	
	
		initLight();
	
	
	 
	while (sfRenderWindow_isOpen(window))
	{
		restartClock();
		Keytimer += GetDeltaTime();
		// Event
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
			eventMap(event, window);
			
		}

		// Update

		updateMenu(window); 
		if (state == EDITOR)
		{
			
			updateview(window);
			
			
		}
		if (state == GAME)
		{
			sfRenderWindow_setView(window, viewGame);
			updatePlayer(window);
			updateEnemy(window);
			
        }
		if (state == DEATH)
		{
			sfRenderWindow_setView(window, viewMenu);
			updatePlayer(window);
			updateEnemy(window);
			displaydeath(window);
		}
		updatelight(window);
		
		// Display
		sfRenderWindow_clear(window, sfBlack);	

		
		if (state == EDITOR)
		{
			sfRenderWindow_setView(window, viewEditor);
			displayMap(window);
			displayMapExt(window);
			displayMapHitBox(window);
			displayEnemy(window);
			displayEnemy3(window);
			displayPlayer(window);
			displaytexts(window);
			//displaydeath(window);
		}
		
		if (state == GAME)
		{
			sfRenderWindow_setView(window, viewGame);
			
			displayMap(window);
			displayPlayer(window);
			displayMapExt(window);
			displayEnemy(window);
			displayEnemy3(window);
			displayfinalmessage(window);
			//displaylight(window);
			displaytexts(window);
			viewfinal();
		}
		if (state == DEATH)
		{
			sfRenderWindow_setView(window, viewMenu);
			displaydeath(window);
		}
		if (state == END)
		{
			sfRenderWindow_setView(window, viewMenu);
			displayEnemy(window);
		}
		displaymenu(window);

		sfRenderWindow_display(window);

	}
	savemap();
	savemapext();
	saveMapHitBox();
}