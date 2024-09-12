#include"tools.h"
#include"SFML/Audio.h"

#include "music.h"
#pragma once



sfBool* musicIsPlayed = sfFalse;
sfBool* musicIsPlayed2 = sfFalse;

sfBool* musicIsLooped = sfTrue;
sfBool* SoundisLooped = sfTrue;
sfBool* menumusic;




float timermusic;


void setSFXVolume(float _set)
{
	if (_set > 0 && SFXVolume < 100.0f || _set < 0 && SFXVolume > 0.0f)
	SFXVolume += _set;
}

void setMusicVolume(float _set)
{
	if( _set > 0 && MusicVolume < 100.0f || _set < 0 && MusicVolume > 0.0f )
		MusicVolume += _set;
}

void musicinit()
{
   MusicIntro = sfMusic_createFromFile(MUSIC_PATH"Violin.ogg");
  /* MusicMiniJeux = sfMusic_createFromFile(MUSIC_PATH"87 bpm musique chill piano aigu.ogg");*/
  // MusicJeuHall = sfMusic_createFromFile(MUSIC_PATH"77 bpm musique salon cuisine.ogg");
  // MusicJeusallesecrete = sfMusic_createFromFile(MUSIC_PATH"87 bpm musique chill piano aigu.ogg");
  ///* sfMusic_setLoop(MusicJeuHall, musicIsLooped);
   //sfMusic_setLoop(MusicJeuFacade, musicIsLooped);
   sfMusic_setLoop(MusicIntro, musicIsLooped);
  

   EnemySound = sfSound_create();
   EnemySoundBuffer = sfSoundBuffer_createFromFile(SFX_PATH"EnemySound.wav");
   sfSound_setBuffer(EnemySound, EnemySoundBuffer);

   OuchSound = sfSound_create();
   OuchSoundBuffer = sfSoundBuffer_createFromFile(SFX_PATH"ouch.wav");
   sfSound_setBuffer(OuchSound, OuchSoundBuffer);

   introSound = sfSound_create();
   introSoundBuffer = sfSoundBuffer_createFromFile(SFX_PATH"introsound.wav");
   sfSound_setBuffer(introSound, introSoundBuffer);

   FinalSectionSound = sfSound_create();
   FinalSoundBuffer = sfSoundBuffer_createFromFile(SFX_PATH"FinalSection.wav");
   sfSound_setBuffer(FinalSectionSound, FinalSoundBuffer);

   FirstSectionSound = sfSound_create();
   FirstSectionBuffer = sfSoundBuffer_createFromFile(SFX_PATH"FirstSection.wav");
   sfSound_setBuffer(FirstSectionSound, FirstSectionBuffer);
   sfSound_setLoop(FirstSectionSound, SoundisLooped);

   FirstSectionSound2 = sfSound_create();
   FirstSectionBuffer2 = sfSoundBuffer_createFromFile(SFX_PATH"FirstSectionCopy.wav");
   sfSound_setBuffer(FirstSectionSound2, FirstSectionBuffer2);

   ChaseSound = sfSound_create();
   ChaseSoundBuffer = sfSoundBuffer_createFromFile(SFX_PATH"ChaseSound.wav");
   sfSound_setBuffer(ChaseSound, ChaseSoundBuffer);

 /*  sfMusic_setVolume(MusicIntro, MusicVolume);

   sfSound_setVolume(EnemySound, SFXVolume);
   sfSound_setVolume(introSound, SFXVolume);
   sfSound_setVolume(FirstSectionSound, SFXVolume);
   sfSound_setVolume(FinalSectionSound, SFXVolume);
   sfSound_setVolume(ChaseSound, SFXVolume);
   sfSound_setVolume(FirstSectionSound2, SFXVolume);*/
   


   SFXVolume = 100.0f;
   MusicVolume = 50.0f;
}


void MusicIntroPlay()
{
	if (state == MENU)
	{
		sfMusic_play(MusicIntro);
	}
	else sfMusic_stop(MusicIntro);

	timermusic += GetDeltaTime();

	
	
	//if (state == MENU && musicIsPlayed == sfFalse)
	//{
	//	
	//	sfSound_play(newyorksound);
	//	sfMusic_pause(MusicJeuFacade);

	//	musicIsPlayed == sfFalse;
	//	

	//}
	//
	//
	//if (displayMap == FACADE && musicIsPlayed == sfFalse )
	//{
	//	sfMusic_play(MusicJeuFacade);
	//	
	//	musicIsPlayed = sfTrue;
	//			
	//}
	//if (displayMap == FACADE && musicIsPlayed == sfFalse || musicIsPlayed2 == sfFalse)
	//{
	//	sfMusic_pause(MusicJeuHall);
	//	musicIsPlayed = sfTrue;
	//	
 //   }
	//if (displayMap == FACADE && musicIsPlayed == sfFalse || musicIsPlayed2 == sfFalse )
	//{
	//	
	//	sfMusic_pause(MusicJeusallesecrete);
	//	musicIsPlayed = sfTrue;
	//}
	
	

	//}
	/*sfMusic_setVolume(MusicJeusallesecrete, MusicVolume);

	sfSound_setVolume(newyorksound, SFXVolume);*/
}
