#pragma once
#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include <random>
#include <string.h>
#include <tchar.h>
#include <mmsystem.h>
#include <Digitalv.h>

#include"resource.h"
#include"Field.h"

using namespace std;

// »ö±ò
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

#define BCOLOR 0 // ¹è°æ »ö±ò
#define DEFAULT 15 // ±ÛÀÚ »ö±ò

#define FINGER 4
#define DFINGER 5



void gotoxy(int x, int y);
void fullscreen();
void SetColor(int color, int bgColor);
void Cursorhide();

void PlayingBGM();
void PlayingOutEffect();
void PlayingCorrectEffect();
void PlayingItemEffect();