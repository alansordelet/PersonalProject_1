#pragma once
#include"tools.h"

char map[75][75];
int mapext[75][75];
int maphitbox[75][75];

void initMap();
void initMapInside();

void updateview(sfRenderWindow* _window);
void displayMapExt(sfRenderWindow* _window);
void displayMap(sfRenderWindow* _window);
void eventMap(sfEvent event, sfRenderWindow* _window);
void displayMapHitBox(sfRenderWindow* _window);
void initMapHitBox();
void savemap();
void loadmap();
void savemapext();
void LoadMapIn();
void saveMapHitBox();
void loadMapHitBox();
