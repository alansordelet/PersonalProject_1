#pragma once

#include "SFML/Graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include"Player.h"
#include"Menu.h"
#include"Enemy.h"

#include"SFML/Audio.h"

#ifndef WIN32
#include <sys/types.h>
#endif

#define TEXTURE_PATH "../Ressources/Textures/"
#define FONT_PATH "../Ressources/Fonts/"
#define MUSIC_PATH "../Ressources/Musics/"
#define SFX_PATH "../Ressources/SFX/"
#define PARTICLES_PATH "../Ressources/Textures/Particles/"




sfView* viewEditor;
sfView* viewMiniMap;
sfView* viewGame;
sfView* viewMenu;
sfVector2f viewGamePosition;

sfVector2i PlayerS;
sfVector2i PlayerS2;
enum State { LOADING, INTRO, MENU, GAME, EDITOR, OPTIONS, DEATH, END }state;

enum StateEdit { COUCHESOL, COUCHEDEHORS, HITBOX }stateEdit;

typedef enum Direction { UP, LEFT, DOWN, RIGHT, IDLE }Direction;

float Keytimer;
typedef struct vector4f vector4f;
struct vector4f
{
	float r;
	float g;
	float b;
	float a;
};



#define MUSIC_PATH "../Ressources/Musics/"
#define SFX_PATH "../Ressources/SFX/"


sfBool collisionMapPlayer(sfFloatRect _PlayerS, Direction _direction, sfVector2f _vitesse);
	

sfClock* sfclock;
sfText* text;
sfFont* font;
sfBool isFullscreen;

sfVector2f vector2f(float _x, float _y);
sfVector2i vector2i(int _x, int _y);
sfVector3f vector3f(float _x, float _y, float _z);
sfFloatRect FlRect(float _left, float _top, float _width, float _height);
sfIntRect IntRect(int _left, int _top, int _width, int _height);
vector4f vec4f_lerp(vector4f v0, vector4f v1, float t);
sfColor color_lerp(sfColor v0, sfColor v1, float t);
void restartClock();
float GetDeltaTime();
sfSprite* CreateSprite(char* _path);
sfText* CreateText(char* _path);
sfBool Circle_Collision(sfVector2f _pos1, sfVector2f _pos2, float _rayon1, float _rayon2);
sfBool Rectangle_Collision(sfFloatRect _box1, sfFloatRect _box2);
int iRand(int _min, int _max);
float FrameRate();
void displayFrameRate(sfRenderWindow* _window, sfText* _text);
void screenshot(sfRenderWindow* _window);
int rand_int2(int _min, int _max);
sfVideoMode mode;
sfBool fullscreen;
sfRenderWindow* window;
double rand_float(float _min, float _max);
sfRenderWindow* 
ToggleFullscreen(sfRenderWindow* _window, sfVideoMode _mode);
