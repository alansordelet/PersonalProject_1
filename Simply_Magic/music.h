#pragma once
#include"tools.h"


void musicinit();
void MusicIntroPlay();
void setSFXVolume(float _set);
void setMusicVolume(float _set);
sfMusic* MusicIntro;
sfSound* introSound;
sfSound* FirstSectionSound;
sfSound* FirstSectionSound2;
sfSound* FinalSectionSound;
sfSound* EnemySound;
sfSound* ChaseSound;
sfSound* OuchSound;

sfSoundBuffer* OuchSoundBuffer;
sfSoundBuffer* introSoundBuffer;
sfSoundBuffer* FirstSectionBuffer;
sfSoundBuffer* FirstSectionBuffer2;
sfSoundBuffer* EnemySoundBuffer;
sfSoundBuffer* ChaseSoundBuffer;
sfSoundBuffer* FinalSoundBuffer;

float SFXVolume;
float MusicVolume;