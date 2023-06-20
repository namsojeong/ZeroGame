#pragma once
#include"Console.h"

const int HEIGHT = 25;
const int WEIGHT = 44;

const int DHEIGHT = 25;
const int DWEIGHT = 44;

// �÷��̾�
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

// ��� AI
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

// �巡��
typedef struct _dragon
{
	int dHeart;
	int dSelect;
	int dUpSelect;
	bool isSeal;
	bool isFuture;
	bool isHeal;
}DRAGON, * PDRAGON;

// ���ӸŴ���
typedef struct _Game
{
	bool isPlayerTurn;
	bool isDragon;
	bool isWin;
	bool isAIWin;
	int round;
}GAME, * PGAME;

// Title ���
void PrintTitle();
// Fail ����
void PrintHorror();

// Map
void SetMap(char map[HEIGHT][WEIGHT]);
void OutputMap(char map[HEIGHT][WEIGHT], PAI ai);
void HeartMap(char map[HEIGHT][WEIGHT], PPLAYER player, PAI ai);

// UI ���
void PrintFingers(char map[HEIGHT][WEIGHT], PPLAYER player, PAI ai);
void PrintNum(PGAME game, PPLAYER player, PAI ai);

// ����
void ResetGame(PGAME game, char map[HEIGHT][WEIGHT], PPLAYER player, PAI ai);
// �Ǵ�
void NumJudgment(PGAME game, PPLAYER player, PAI ai);

// ���� ����
void RandomAINum(PGAME game, PAI ai);
void InputPlayer(PGAME game, PPLAYER player, PAI ai, PDRAGON dragon);

// ������
void ItemSelect(PGAME game, PPLAYER player, PAI ai, PDRAGON dragon, int item);
void SealItem(PGAME game, PAI ai, PDRAGON dragon);
void FutureItem(PGAME game, PAI ai, PDRAGON dragon);


// �巡��

// MAP
void SetDragonMap(char map[DHEIGHT][DWEIGHT]);
void OutputDragonMap(char map[DHEIGHT][DWEIGHT], PDRAGON dragon);
void DragonHeartMap(char map[DHEIGHT][DWEIGHT], PPLAYER player, PDRAGON dragon);

// UI ���
void PrintDragonFingers(char map[DHEIGHT][DWEIGHT], PPLAYER player, PDRAGON dragon);
void PrintDragonNum(PGAME game, PPLAYER player, PDRAGON dragon);

// �Ǵ� + ���� ����
void NumDragonJudgment(PGAME game, PPLAYER player, PDRAGON dragon);
void RandomDragonNum(PDRAGON dragon);
