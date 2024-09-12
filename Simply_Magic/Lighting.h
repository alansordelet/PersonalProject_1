#pragma once
#include"tools.h"

sfShader* shader;
sfRenderStates renderState;

void initLight();
void updatelight(sfRenderWindow* window);
void displaylight(sfRenderWindow* window);