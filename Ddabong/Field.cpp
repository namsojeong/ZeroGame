#include "Field.h"

// Title 출력
void PrintTitle()
{
	cout << "#######  #######  ##  ###  #######  #######  ###### " << endl;
	cout << "##         ###    ### ###  ##   ##  ##       ##  ## " << endl;
	cout << "##         ###    #######  ##       ##       ##  ## " << endl;
	cout << "#######    ###    ## ####  ## ####  #######  #######" << endl;
	cout << "###        ###    ##  ###  ##  ###  ###      ###  ###" << endl;
	cout << "###        ###    ##  ###  ##  ###  ###      ###  ###" << endl;
	cout << "###      #######  ##  ###  #######  #######  ###  ###" << endl << endl;
}
// Fail 띄우기
void PrintHorror()
{
	gotoxy(55, 10);
	cout << ".　n Λ＿Λ" << endl;
	gotoxy(55, 11);
	cout << " (ﾖ(´･ω･｀) 따봉!!" << endl;
	gotoxy(55, 12);
	cout << "≡　y　 と丿" << endl;
	gotoxy(55, 13);
	cout << "≡（_ﾉ　ノ" << endl;
	gotoxy(55, 14);
	cout << "≡(ノ´" << endl << endl;
}

// Map 출력 1:벽 2:빈공간 3:하트 4:빈하트 5:손톱 6:채워진손톤
void HeartMap(char map[HEIGHT][WEIGHT], PPLAYER player, PAI ai)
{
	gotoxy(65, 15);
	cout << ai->aiHeart;
	gotoxy(65, 28);
	cout << player->pHeart;
}
void PrintFingers(char map[HEIGHT][WEIGHT], PPLAYER player, PAI ai)
{
	switch (ai->aiUpSelect)
	{
	case 0:
		strcpy_s(map[4], "62222222122112212222222222AI222222222222622");
		strcpy_s(map[5], "6222222212211221222222222222222222222226222");
		strcpy_s(map[6], "6222222221111112222222222222222222222226222");
		strcpy_s(map[7], "6222222222222222222222222222222222222226222");
		strcpy_s(map[8], "6222222222222222222222222222222222222226222");
		strcpy_s(map[9], "6222222222222222222222222222222222222226222");

		break;
	case 1:
		strcpy_s(map[4], "62222222122112212222222222AI222222222222622");
		strcpy_s(map[5], "6222222212211221222222222222222222222226222");
		strcpy_s(map[6], "6222222221111221222222222222222222222226222");
		strcpy_s(map[7], "6222222222221212222222222222222222222226222");
		strcpy_s(map[8], "6222222222221512222222222222222222222226222");
		strcpy_s(map[9], "6222222222222122222222222222222222222226222");
		break;
	case 2:
		strcpy_s(map[4], "62222222122112212222222222AI222222222222622");
		strcpy_s(map[5], "6222222212211221222222222222222222222226222");
		strcpy_s(map[6], "6222222221211221222222222222222222222226222");
		strcpy_s(map[7], "6222222221211212222222222222222222222226222");
		strcpy_s(map[8], "6222222221511512222222222222222222222226222");
		strcpy_s(map[9], "6222222222122122222222222222222222222226222");
		break;
	}

	switch (player->pUpSelect)
	{
	case 0:
		strcpy_s(map[15], "6222222222222222222222222222222222222226222");
		strcpy_s(map[16], "6222222222222222222222222222222222222226222");
		strcpy_s(map[17], "622222222222222222222222PLAYER2222222222226");
		strcpy_s(map[18], "6222222221111112222222222222222222222226222");
		strcpy_s(map[19], "6222222212211221222222222222222222222226222");
		strcpy_s(map[20], "6222222212211221222222222222222222222226222");
		break;
	case 1:
		strcpy_s(map[15], "6222222222122222222222222222222222222226222");
		strcpy_s(map[16], "6222222221512222222222222222222222222226222");
		strcpy_s(map[17], "622222222121222222222222PLAYER2222222222226");
		strcpy_s(map[18], "6222222221211112222222222222222222222226222");
		strcpy_s(map[19], "6222222212211221222222222222222222222226222");
		strcpy_s(map[20], "6222222212211221222222222222222222222226222");
		break;
	case 2:
		strcpy_s(map[15], "6222222222122122222222222222222222222226222");
		strcpy_s(map[16], "6222222221511512222222222222222222222226222");
		strcpy_s(map[17], "622222222121121222222222PLAYER2222222222226");
		strcpy_s(map[18], "6222222221211221222222222222222222222226222");
		strcpy_s(map[19], "6222222212211221222222222222222222222226222");
		strcpy_s(map[20], "6222222212211221222222222222222222222226222");
		break;
	}
}
void PrintNum(PGAME game, PPLAYER player, PAI ai)
{
	// 키 설명
	cout << "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□" << endl;
	cout << "■									      ■" << endl;
	cout << "■						   			      ■" << endl;
	if (game->isPlayerTurn)
		cout << "■				내가 예측한 개수: " << player->pSelect << "		 	      ■" << endl;
	else
		cout << "■				상대 예측한 개수: " << ai->aiSelect << "			      ■" << endl;
	cout << "■				내 손가락 개수 : " << player->pUpSelect << "			      ■" << endl;
	cout << "■				상대 손가락 개수 : " << ai->aiUpSelect << "			      ■" << endl;
	cout << "■									      ■" << endl;
	cout << "■				ESC : 종료				      ■" << endl;
	cout << "■									      ■" << endl;
	cout << "■									      ■" << endl;
	cout << "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□" << endl;
	game->isPlayerTurn = !game->isPlayerTurn;

}

void SetMap(char map[HEIGHT][WEIGHT])
{
	strcpy_s(map[0], "6666666666666666666666666666666666666666222");
	strcpy_s(map[1], "6222222222222222222222222222222222222226222");
	strcpy_s(map[2], "6222222222222222222222222222222222222226222");
	strcpy_s(map[3], "6222222222222222222222222222222222222226222");
	strcpy_s(map[4], "62222222122112212222222222AI222222222222622");
	strcpy_s(map[5], "6222222212211221222222222222222222222226222");
	strcpy_s(map[6], "6222222221211221222222222222222222222226222");
	strcpy_s(map[7], "6222222221211212222222222222222222222226222");
	strcpy_s(map[8], "6222222221511512222222222222222222222226222");
	strcpy_s(map[9], "6222222222122122222222222222222222222226222");
	strcpy_s(map[10], "6222222222222222222222222222222222222226222");
	strcpy_s(map[11], "6222222222222222222222222222222222222226222");
	strcpy_s(map[12], "6222222222222222222222222222222222222226222");
	strcpy_s(map[13], "6222222222222222222222222222222222222226222");
	strcpy_s(map[14], "6222222222222222222222222222222222222226222");
	strcpy_s(map[15], "6222222222122122222222222222222222222226222");
	strcpy_s(map[16], "6222222221511512222222222222222222222226222");
	strcpy_s(map[17], "622222222121121222222222PLAYER2222222222226");
	strcpy_s(map[18], "6222222221211221222222222222222222222226222");
	strcpy_s(map[19], "6222222212211221222222222222222222222226222");
	strcpy_s(map[20], "6222222212211221222222222222222222222226222");
	strcpy_s(map[21], "6222222222222222222222222222222222222226222");
	strcpy_s(map[22], "6222222222222222222222222222222222222226222");
	strcpy_s(map[23], "6222222222222222222222222222222222222226222");
	strcpy_s(map[24], "6666666666666666666666666666666666666666222");
}
void OutputMap(char map[HEIGHT][WEIGHT], PAI ai)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WEIGHT; j++)
		{
			SetColor(DEFAULT, BCOLOR);
			switch (map[i][j])
			{
			case '1':
				if (ai->isSeal && i < 15)SetColor(DARKGRAY, BCOLOR);
				else if (ai->isHeal && i > 14)SetColor(GREEN, BCOLOR);
				cout << "■";
				break;
			case '2':
				cout << "  ";
				break;
			case '3':
				cout << "";
				break;
			case '5':
				if (ai->isHeal && i > 14)SetColor(GREEN, BCOLOR);
				cout << "◇";
				break;
			case '6':
				SetColor(CYAN, BCOLOR);
				cout << "●";
				break;
			default:
				cout << map[i][j];
				break;
			}
			if (j > 41)
			{
				SetColor(DEFAULT, BCOLOR);
				if (i == 6) cout << ".　n Λ＿Λ";
				if (i == 7) cout << " (ﾖ(´･ω･｀) 따봉!!";
				if (i == 8) cout << " ≡　y　 と丿";
				if (i == 9) cout << " ≡（_ﾉ　ノ";
				if (i == 10)cout << " ≡(ノ´";
				break;
			}
		}
		cout << endl;
	}
}

// 판단
void NumJudgment(PGAME game, PPLAYER player, PAI ai)
{
	int totalF = ai->aiUpSelect + player->pUpSelect;

	if (game->isPlayerTurn)
	{
		if (player->pSelect == totalF)
		{
			game->isWin = true;
			game->isAIWin = false;
			if (totalF == 0 && player->pSelect == 0)
			{
				ai->aiHeart -= 5;
			}
			else
			{
				ai->aiHeart -= totalF;
			}
		}
	}
	else
	{
		if (ai->aiSelect == totalF)
		{
			game->isWin = false;
			game->isAIWin = true;
		}
		if (totalF == 0 && ai->aiSelect == 0)
		{
			player->pHeart -= 5;
		}
		else if (ai->aiSelect == totalF)
		{
			player->pHeart -= totalF;
		}
	}
}

// AI 랜덤 숫자
void RandomAINum(PGAME game, PAI ai)
{
	if (ai->isSeal)
	{
		ai->aiUpSelect = rand() % 1;
	}
	else
	{
		ai->aiUpSelect = rand() % 2;
	}
	ai->aiSelect = rand() % 4;
}
// 플레이어 선택
void InputPlayer(PGAME game, PPLAYER player, PAI ai, PDRAGON dragon)
{
	while (true)
	{
		gotoxy(0, 37);
		cout << "ㅡ 아이템 ㅡ" << endl;
		cout << "0:사용X 1:봉인(손가락 갯수의 반을 올리지 못함) 2:회복(HP +2) 3:미래예측(확률적으로 상대가 낼 숫자를 알 수 있음)" << endl;
		cout << "남은 갯수 -  봉인 : " << player->sealCnt << "  회복 : " << player->hpCnt << "  미래 예측 : " << player->futureCnt << endl;
		char ch = _getch();
		bool isA = (ch - '0' == 1 && player->sealCnt < 1) || (ch - '0' == 2 && player->hpCnt < 1) || (ch - '0' == 3 && player->futureCnt < 1);
		if (ch - '0' <= 3 && ch - '0' >= 0 && !isA)
		{
			ItemSelect(game, player, ai, dragon, ch - '0');
			break;
		}
		else
		{
			SetColor(RED, BCOLOR);
			continue;
		}
	}
	while (true)
	{
		gotoxy(0, 42);
		cout << "올릴 손가락 개수를 입력하세요 (0 ~ 2) : ";
		char ch = _getch();
		player->pUpSelect = ch - '0';
		if (player->pUpSelect <= 2 && player->pUpSelect >= 0)
		{
			//SetColor(DEFAULT, BCOLOR);
			cout << player->pUpSelect << "	";
			break;
		}
		else
		{
			SetColor(RED, BCOLOR);
			continue;
		}
	}
	if (game->isPlayerTurn)
	{
		int temp;
		if (game->isDragon)
		{
			temp = 7;
		}
		else
		{
			temp = 4;
		}
		while (true)
		{
			gotoxy(0, 44);
			cout << "몇 개의 손가락이 올라갈 것 같나요? (0 ~ " << temp << ") : ";
			char ch = _getch();
			player->pSelect = ch - '0';
			if (player->pSelect <= temp && player->pSelect >= 0)
			{
				SetColor(DEFAULT, BCOLOR);
				cout << player->pSelect << "	";
				break;
			}
			else
			{
				SetColor(RED, BCOLOR);
				continue;
			}
		}
	}
}
// 리셋
void ResetGame(PGAME game, char map[HEIGHT][WEIGHT], PPLAYER player, PAI ai)
{
	game->isPlayerTurn = false;
	game->isAIWin = false;
	game->isWin = false;
	player->pHeart = 10;
	ai->aiHeart = 10;
	player->isItem = false;
	ai->isFuture = false;
	ai->isSeal = false;
	ai->isHeal = false;
	ai->aiFinger = 2;
	SetMap(map);
}


//아이템
void ItemSelect(PGAME game, PPLAYER player, PAI ai, PDRAGON dragon, int item)
{
	if (item == 0)
	{
		player->isItem = false;
		return;
	}
	else {
		PlayingItemEffect();
		if (item == 1)
		{
			if (player->sealCnt > 0)
			{
				player->sealCnt--;
				SealItem(game, ai, dragon);
			}
		}
		else if (item == 2)
		{
			if (player->hpCnt > 0)
			{
				ai->isHeal = true;
				dragon->isHeal = true;
				player->hpCnt--;
				player->pHeart += 2;
			}
		}
		else if (item == 3)
		{
			if (player->futureCnt > 0)
			{
				player->futureCnt--;
				FutureItem(game, ai, dragon);
			}
		}
	}
	player->isItem = true;
}
// 손가락 봉인 아이템
void SealItem(PGAME game, PAI ai, PDRAGON dragon)
{
	ai->isSeal = true;
	dragon->isSeal = true;
}
// 미래 예측 아이템
void FutureItem(PGAME game, PAI ai, PDRAGON dragon)
{
	int percent = rand() % 100 + 1;
	gotoxy(5, 33);
	if (percent <= 30)
	{
		ai->isFuture = true;
		dragon->isFuture = true;
		if (game->isDragon)
		{
			if (game->isPlayerTurn)
			{
				gotoxy(5, 32);
				cout << "드래곤이 올릴 숫자는...." << endl;
				gotoxy(5, 33);
				cout << dragon->dUpSelect << "입니다....!" << endl;
			}
			else
			{
				gotoxy(5, 32);
				cout << "드래곤이 부를 숫자는...." << endl;
				gotoxy(5, 33);
				cout << dragon->dSelect << "입니다....!" << endl;
			}
		}
		else
		{
			if (game->isPlayerTurn)
			{
				gotoxy(5, 32);
				cout << "AI가 올릴 숫자는...." << endl;
				gotoxy(5, 33);
				cout << ai->aiUpSelect << "입니다....!" << endl;
			}
			else
			{
				gotoxy(5, 32);
				cout << "AI가 부를 숫자는...." << endl;
				gotoxy(5, 33);
				cout << ai->aiSelect << "입니다....!" << endl;
			}
		}

	}
	else
	{
		cout << "미래를 예측하지 못했습니다...!" << endl;
		ai->isFuture = false;
		dragon->isFuture = false;
	}
	Sleep(3000);
}


//드래곤
void PrintDragonFingers(char map[DHEIGHT][DWEIGHT], PPLAYER player, PDRAGON dragon)
{
	switch (dragon->dUpSelect)
	{
	case 0:
		strcpy_s(map[4], "62222221221122112211221121222DRAGON22222226");
		strcpy_s(map[5], "6222222122112211221122112122222222222226222");
		strcpy_s(map[6], "6222222211212211221122111222222222222226222");
		strcpy_s(map[7], "6222222222221122112211222222222222222226222");
		strcpy_s(map[8], "6222222222222222222222222222222222222226222");
		strcpy_s(map[9], "6222222222222222222222222222222222222226222");
		break;
	case 1:
		strcpy_s(map[4], "62222221221122112211221121222DRAGON22222226");
		strcpy_s(map[5], "6222222122112211221122112122222222222226222");
		strcpy_s(map[6], "6222222212112211221122112122222222222226222");
		strcpy_s(map[7], "6222222212121122112211221222222222222226222");
		strcpy_s(map[8], "6222222215122222222222222222222222222226222");
		strcpy_s(map[9], "6222222221222222222222222222222222222226222");
		break;
	case 2:
		strcpy_s(map[4], "62222221221122112211221121222DRAGON22222226");
		strcpy_s(map[5], "6222222122112211221122112122222222222226222");
		strcpy_s(map[6], "6222222212112211221122112122222222222226222");
		strcpy_s(map[7], "6222222212112122112211211222222222222226222");
		strcpy_s(map[8], "6222222215115122222222222222222222222226222");
		strcpy_s(map[9], "6222222221221222222222222222222222222226222");
		break;
	case 3:
		strcpy_s(map[4], "62222221221122112211221121222DRAGON22222226");
		strcpy_s(map[5], "6222222122112211221122112122222222222226222");
		strcpy_s(map[6], "6222222212112211221122112122222222222226222");
		strcpy_s(map[7], "6222222212112121212211211222222222222226222");
		strcpy_s(map[8], "6222222215115121512222222222222222222226222");
		strcpy_s(map[9], "6222222221221222122222222222222222222226222");
		break;
	case 4:
		strcpy_s(map[4], "62222221221122112211221121222DRAGON22222226");
		strcpy_s(map[5], "6222222122112211221122112122222222222226222");
		strcpy_s(map[6], "6222222212112211221121211222222222222226222");
		strcpy_s(map[7], "6222222212112121211121222222222222222226222");
		strcpy_s(map[8], "6222222215115121512151222222222222222226222");
		strcpy_s(map[9], "6222222221221222122212222222222222222226222");
		break;
	case 5:
		strcpy_s(map[4], "62222221221122112211221121222DRAGON22222226");
		strcpy_s(map[5], "6222222122112211221122112122222222222226222");
		strcpy_s(map[6], "6222222212112211221121212122222222222226222");
		strcpy_s(map[7], "6222222212112121211121212122222222222226222");
		strcpy_s(map[8], "6222222215115121512151215122222222222226222");
		strcpy_s(map[9], "6222222221221222122212221222222222222226222");
		break;
	}

	switch (player->pUpSelect)
	{
	case 0:
		strcpy_s(map[15], "622222222222222222222222222222222222226222");
		strcpy_s(map[16], "622222222222222222222222222222222222226222");
		strcpy_s(map[17], "622222222222222222222222PLAYER222222222226");
		strcpy_s(map[18], "622222222111111222222222222222222222226222");
		strcpy_s(map[19], "622222221221122122222222222222222222226222");
		strcpy_s(map[20], "622222221221122122222222222222222222226222");
		break;
	case 1:
		strcpy_s(map[15], "6222222222122222222222222222222222222226222");
		strcpy_s(map[16], "6222222221512222222222222222222222222226222");
		strcpy_s(map[17], "622222222121222222222222PLAYER2222222222226");
		strcpy_s(map[18], "6222222221211112222222222222222222222226222");
		strcpy_s(map[19], "6222222212211221222222222222222222222226222");
		strcpy_s(map[20], "6222222212211221222222222222222222222226222");
		break;
	case 2:
		strcpy_s(map[15], "6222222222122122222222222222222222222226222");
		strcpy_s(map[16], "6222222221511512222222222222222222222226222");
		strcpy_s(map[17], "622222222121121222222222222PLAYER2222222226");
		strcpy_s(map[18], "6222222221211221222222222222222222222226222");
		strcpy_s(map[19], "6222222212211221222222222222222222222226222");
		strcpy_s(map[20], "6222222212211221222222222222222222222226222");
		break;
	}
}
void PrintDragonNum(PGAME game, PPLAYER player, PDRAGON dragon)
{
	SetColor(DEFAULT, BCOLOR);
	cout << "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□" << endl;
	cout << "■										■" << endl;
	cout << "■										■" << endl;
	if (game->isPlayerTurn)
		cout << "■				내가 예측한 개수: " << player->pSelect << "				■" << endl;
	else
		cout << "■				드래곤이 예측한 개수: " << dragon->dSelect << "				■" << endl;
	cout << "■				내 손가락 개수 : " << player->pUpSelect << "				■" << endl;
	cout << "■ 				드래곤 손가락 개수  : " << dragon->dUpSelect << "				■" << endl;
	cout << "■										■" << endl;
	cout << "■				ESC : 종료					■" << endl;
	cout << "■										■" << endl;
	cout << "■										■" << endl;
	cout << "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□" << endl;
	game->isPlayerTurn = !game->isPlayerTurn;
}

void NumDragonJudgment(PGAME game, PPLAYER player, PDRAGON dragon)
{
	int totalF = dragon->dUpSelect + player->pUpSelect;

	if (game->isPlayerTurn)
	{
		if (player->pSelect == totalF)
		{
			game->isWin = true;
			if (totalF == 0)
			{
				PlayingCorrectEffect();
				dragon->dHeart -= 10;
			}
			else
			dragon->dHeart -= totalF;
		}
	}
	else
	{
		if (dragon->dSelect == totalF)
		{
			game->isAIWin = true;
			if (totalF == 0)
			{
				PlayingOutEffect();
				player->pHeart -= 5;
			}
			else
			player->pHeart -= totalF;
		}
	}
}
void RandomDragonNum(PDRAGON dragon)
{
	if (dragon->isSeal)
	{
		dragon->dUpSelect = rand() % 1;
	}
	else
	{
		dragon->dUpSelect = rand() % 5;
	}
	dragon->dSelect = rand() % 7;
}

void SetDragonMap(char map[DHEIGHT][DWEIGHT])
{
	strcpy_s(map[0], "6666666666666666666666666666666666666666222");
	strcpy_s(map[1], "6222222222222222222222222222222222222226222");
	strcpy_s(map[2], "6222222222222222222222222222222222222226222");
	strcpy_s(map[3], "6222222222222222222222222222222222222226222");
	strcpy_s(map[4], "62222221221122112211221121222DRAGON22222226");
	strcpy_s(map[5], "6222222122112211221122112122222222222226222");
	strcpy_s(map[6], "6222222212112211221121212122222222222226222");
	strcpy_s(map[7], "6222222212112121211121212122222222222226222");
	strcpy_s(map[8], "6222222215115121512151215122222222222226222");
	strcpy_s(map[9], "6222222221221222122212221222222222222226222");
	strcpy_s(map[10], "6222222222222222222222222222222222222226222");
	strcpy_s(map[11], "6222222222222222222222222222222222222226222");
	strcpy_s(map[12], "6222222222222222222222222222222222222226222");
	strcpy_s(map[13], "6222222222222222222222222222222222222226222");
	strcpy_s(map[14], "6222222222222222222222222222222222222226222");
	strcpy_s(map[15], "6222222222122122222222222222222222222226222");
	strcpy_s(map[16], "6222222221511512222222222222222222222226222");
	strcpy_s(map[17], "622222222121121222222222222PLAYER2222222226");
	strcpy_s(map[18], "6222222221211221222222222222222222222226222");
	strcpy_s(map[19], "6222222212211221222222222222222222222226222");
	strcpy_s(map[20], "6222222212211221222222222222222222222226222");
	strcpy_s(map[21], "6222222222222222222222222222222222222226222");
	strcpy_s(map[22], "6222222222222222222222222222222222222226222");
	strcpy_s(map[23], "6222222222222222222222222222222222222226222");
	strcpy_s(map[24], "6666666666666666666666666666666666666666222");
}
void OutputDragonMap(char map[DHEIGHT][DWEIGHT], PDRAGON dragon)
{
	for (int i = 0; i < DHEIGHT; i++)
	{
		for (int j = 0; j < DWEIGHT; j++)
		{
				SetColor(DEFAULT, BCOLOR);
			switch (map[i][j])
			{
			case '1':
				if (dragon->isSeal && i < 15)SetColor(DARKGRAY, BCOLOR);
				else if (dragon->isHeal && i > 14)SetColor(GREEN, BCOLOR);
				cout << "■";
				break;
			case '2':
				cout << "  ";
				break;
			case '3':
				cout << "";
				break;
			case '5':
				cout << "◇";
				break;
			case '6':
				SetColor(CYAN, BCOLOR);
				cout << "◆";
				break;
			default:
				cout << map[i][j];
				break;
			}
			if (j > 41)
			{
				SetColor(DEFAULT, BCOLOR);
				if (i == 6) cout << ".　n Λ＿Λ";
				if (i == 7) cout << " (ﾖ(´･ω･｀) 따봉!!";
				if (i == 8) cout << " ≡　y　 と丿";
				if (i == 9) cout << " ≡（_ﾉ　ノ";
				if (i == 10)cout << " ≡(ノ´";
				break;
			}
		}
		cout << endl;
	}
}
void DragonHeartMap(char map[DHEIGHT][DWEIGHT], PPLAYER player, PDRAGON dragon)
{
	gotoxy(65, 14);
	cout << dragon->dHeart;
	gotoxy(65, 27);
	cout << player->pHeart;
}

