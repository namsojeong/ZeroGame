#include"Console.h"

char map[HEIGHT][WEIGHT];
char dragonMap[DHEIGHT][DWEIGHT];

enum ITEM
{
	SEAL = 1,
	HEAL = 2,
	FUTURE = 3
};

int main()
{
	srand((unsigned int)time(NULL));
	Cursorhide();
	system("mode con cols=120 lines=80 | title 따봉    (°∀°)b");


	PLAYER tPlayer;
	AI tAI;
	GAME tGame;
	DRAGON tDragon;

	tGame.isDragon = false;
	tPlayer.futureCnt = 5;
	tPlayer.hpCnt = 3;
	tPlayer.sealCnt = 3;

	// 시나리오
	{
		SetColor(WHITE, BCOLOR);
		gotoxy(10, 5);
		cout << "어느 날... 예쁘기로 소문난 손가락 공주가 실종되었다..." << endl;
		Sleep(3000);
		gotoxy(10, 7);
		cout << "옆 동네에 사는 드래곤이 잡아갔다는 소문이 돈다." << endl;
		Sleep(3000);
		gotoxy(10, 9);
		cout << "그 드래곤을 잡고 공주를 구하려는 여러 기사들이 나타난다." << endl;
		Sleep(3000);
		gotoxy(10, 11);
		cout << "그 기사들끼리 싸워 이긴 한 사람만이 공주를 구하러 갈 수 있다." << endl;
		Sleep(3000);
		gotoxy(10, 13);
		cout << "과연 기사들 중 1위를 차지하고 드래곤에게서 구해낼 수 있을 것인가...!" << endl;
		Sleep(3000);
	}

	system("cls");
	PlayingBGM();
	SetColor(CYAN, BCOLOR);
	gotoxy(0, 10);
	PrintTitle();
	//PrintHorror();
	gotoxy(20, 19);
	cout << "- S T A R T - " << endl;
	gotoxy(15, 20);
	cout << "아무키나 눌러 시작하세요." << endl;
	char ch = _getch();

	for (int i = 1; i <= 1; i++)
	{
		SetColor(DEFAULT, BCOLOR);

		// 처음 리셋
		{
			ResetGame(&tGame, map, &tPlayer, &tAI);
			tGame.round = i;
		}

		while (true)
		{
			// UI 출력
			{
				system("cls");
				SetColor(DEFAULT, BCOLOR);
				gotoxy(0, 1);
				PrintTitle();
				SetColor(DEFAULT, BCOLOR);
				cout << "\n - " << tGame.round << "번째 판 -" << endl;
				gotoxy(0, 11);
				OutputMap(map, &tAI);
				HeartMap(map, &tPlayer, &tAI);
			}

			SetColor(DEFAULT, BCOLOR);
			// 숫자 선택
			{
				RandomAINum(&tGame, &tAI);
				InputPlayer(&tGame, &tPlayer, &tAI, &tDragon);
			}

			// 판단
			{
				NumJudgment(&tGame, &tPlayer, &tAI);
			}

			// 결과 출력
			{
				if (tGame.isAIWin)
					SetColor(RED, BCOLOR);
				if(tGame.isWin)
					SetColor(YELLOW, BCOLOR);


				system("cls");
				gotoxy(0, 1);
				PrintTitle();
				gotoxy(0, 11);
				PrintFingers(map, &tPlayer, &tAI);
				OutputMap(map, &tAI);
				HeartMap(map, &tPlayer, &tAI);
				gotoxy(0, 35);
				PrintNum(&tGame, &tPlayer, &tAI);
				if (tGame.isAIWin)
				{
					tGame.isAIWin = false;
					PlayingOutEffect();
					gotoxy(10, 13);
					cout << "공격 성공이다....!";
					gotoxy(10, 25);
					cout << "윽 이걸 간파당하다니";
				}
				if (tGame.isWin)
				{
					tGame.isWin = false;
					PlayingCorrectEffect();
					gotoxy(10, 13);
					cout << "으악..! 당했다..!";
					gotoxy(10, 25);
					cout << "ㅎㅎ 공격 성공이다";
				}
				Sleep(1000);
			}

			gotoxy(0, 46);

			SetColor(DEFAULT, BCOLOR);
			// 끝났는지 판단
			{
				if (tPlayer.pHeart < 1)
				{
					cout << "상대가 너무 강했습니다..!" << endl;
					cout << "아무키를 눌러 새로운 경기에 도전하세요 (ESC == 게임종료)";
					break;
				}
				else if (tAI.aiHeart < 1)
				{
					cout << "굉장히 강하군요..!" << endl;
					cout << "아무키를 눌러 다음 경기로 넘어가세요 (ESC == 게임종료)";
					break;
				}
				else
				{
					if (tPlayer.isItem)
					{
						cout << "아이템이 사용되었습니다" << endl;
						tPlayer.isItem = false;
						tAI.isFuture = false;
						tAI.isSeal = false;
						tAI.isHeal = false;
					}
					cout << "아무키를 눌러 다음 턴으로 넘어가세요 (ESC == 게임종료)";
				}
			}

			// '넘어가기' 입력받기
			{
				char cInput = _getch();
				// 종료
				if (GetAsyncKeyState(VK_ESCAPE) & 0X8000)
				{
					cout << "게임 종료" << endl;
					return 0;
				}
				else
				{
					continue;
				}
			}
		}
	}


	// 리셋
	{
		tGame.isPlayerTurn = false;
		tPlayer.pHeart = 10;
		tDragon.dHeart = 20;
		tPlayer.isItem = false;
		tDragon.isFuture = false;
		tDragon.isSeal = false;
		tDragon.isHeal = false;
		tGame.isDragon = true;
		tGame.isWin = false;
		tGame.isAIWin = false;
		SetDragonMap(dragonMap);
	}

	// 보스 드래곤

	while (true)
	{
		// UI 출력
		{
			system("cls");
			PrintTitle();
			SetColor(WHITE, BCOLOR);
			cout << "드래곤 VS PLAYER";
			gotoxy(0, 10);
			OutputDragonMap(dragonMap, &tDragon);
			DragonHeartMap(dragonMap, &tPlayer, &tDragon);
		}

		// 숫자 선택
		{
			RandomDragonNum(&tDragon);
			InputPlayer(&tGame, &tPlayer, &tAI, &tDragon);
		}

		// 판단
		{
			NumDragonJudgment(&tGame, &tPlayer, &tDragon);
		}

		//결과 출력
		{
			system("cls");
			PrintTitle();
			PrintDragonFingers(dragonMap, &tPlayer, &tDragon);
			OutputDragonMap(dragonMap, &tDragon);
			DragonHeartMap(dragonMap, &tPlayer, &tDragon);
			gotoxy(0, 35);
			PrintDragonNum(&tGame, &tPlayer, &tDragon);
			if (tGame.isAIWin)
			{
				tGame.isAIWin = false;
				PlayingOutEffect();
				gotoxy(10, 11);
				cout << "공격 성공이다....!";
				gotoxy(10, 22);
				cout << "윽 이걸 간파당하다니";
			}
			if (tGame.isWin)
			{
				tGame.isWin = false;
				PlayingCorrectEffect();
				gotoxy(10, 11);
				cout << "으악..! 당했다..!";
				gotoxy(10, 22);
				cout << "ㅎㅎ 공격 성공이다";
			}
			Sleep(1000);
		}

		gotoxy(0, 46);

		// 끝났는지 판단
		{
			if (tPlayer.pHeart < 1)
			{
				cout << "드래곤이 너무 강했습니다..!" << endl;
				cout << "다음에 다시 도전하세요!!!!" << endl;
				break;
			}
			else if (tDragon.dHeart < 1)
			{
				cout << "굉장히 강하군요..!" << endl;
				cout << "드래곤을 물리쳤습니다!!!!" << endl;
				break;
			}
			else
			{
				if (tPlayer.isItem)
				{
					cout << "아이템이 사용되었습니다" << endl;
					tPlayer.isItem = false;
					tDragon.isFuture = false;
					tDragon.isSeal = false;
					tDragon.isHeal = false;
				}
				cout << "아무키를 눌러 다음 턴으로 넘어가세요 (ESC == 게임종료)";
			}
		}

		// 넘어가기 입력받기
		{
			char cInput = _getch();
			// 종료
			if (GetAsyncKeyState(VK_ESCAPE) & 0X8000)
			{
				cout << "게임 종료" << endl;
				exit(0);
			}
		}
	}

	return 0;
}
