#pragma once
#include"Console.h"

const int HEIGHT = 25;
const int WEIGHT = 44;

const int DHEIGHT = 25;
const int DWEIGHT = 44;

// 플레이어
typedef struct _player
{
	int pHeart;
	int pSelect;
	int pUpSelect;
	int sealCnt;
	int hpCnt;
	int futureCnt;
	bool isItem;
}PLAYER, * PPLAYER;

// 상대 AI
typedef struct _ai
{
	int aiFinger;
	int aiHeart;
	int aiSelect;
	int aiUpSelect;
	bool isSeal;
	bool isFuture;
	bool isHeal;
}AI, * PAI;

// 드래곤
typedef struct _dragon
{
	int dHeart;
	int dSelect;
	int dUpSelect;
	bool isSeal;
	bool isFuture;
	bool isHeal;
}DRAGON, * PDRAGON;

// 게임매니저
typedef struct _Game
{
	bool isPlayerTurn;
	bool isDragon;
	bool isWin;
	bool isAIWin;
	int round;
}GAME, * PGAME;

// Title 출력
void PrintTitle();
// Fail 띄우기
void PrintHorror();

// Map
void SetMap(char map[HEIGHT][WEIGHT]);
void OutputMap(char map[HEIGHT][WEIGHT], PAI ai);
void HeartMap(char map[HEIGHT][WEIGHT], PPLAYER player, PAI ai);

// UI 출력
void PrintFingers(char map[HEIGHT][WEIGHT], PPLAYER player, PAI ai);
void PrintNum(PGAME game, PPLAYER player, PAI ai);

// 리셋
void ResetGame(PGAME game, char map[HEIGHT][WEIGHT], PPLAYER player, PAI ai);
// 판단
void NumJudgment(PGAME game, PPLAYER player, PAI ai);

// 숫자 선택
void RandomAINum(PGAME game, PAI ai);
void InputPlayer(PGAME game, PPLAYER player, PAI ai, PDRAGON dragon);

// 아이템
void ItemSelect(PGAME game, PPLAYER player, PAI ai, PDRAGON dragon, int item);
void SealItem(PGAME game, PAI ai, PDRAGON dragon);
void FutureItem(PGAME game, PAI ai, PDRAGON dragon);


// 드래곤

// MAP
void SetDragonMap(char map[DHEIGHT][DWEIGHT]);
void OutputDragonMap(char map[DHEIGHT][DWEIGHT], PDRAGON dragon);
void DragonHeartMap(char map[DHEIGHT][DWEIGHT], PPLAYER player, PDRAGON dragon);

// UI 출력
void PrintDragonFingers(char map[DHEIGHT][DWEIGHT], PPLAYER player, PDRAGON dragon);
void PrintDragonNum(PGAME game, PPLAYER player, PDRAGON dragon);

// 판단 + 숫자 선택
void NumDragonJudgment(PGAME game, PPLAYER player, PDRAGON dragon);
void RandomDragonNum(PDRAGON dragon);
