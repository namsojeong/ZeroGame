#include "Console.h"
#include"resource.h"
#pragma comment(lib, "winmm.lib")

// 출력 위치 바꾸기
void gotoxy(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

// 색깔 바꾸기
void SetColor(int color, int bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | color);
}

void Cursorhide()
{
	CONSOLE_CURSOR_INFO cursorinfo;
	cursorinfo.bVisible = false;
	cursorinfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
}

// 풀스크린
void fullscreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

// bgm
MCI_OPEN_PARMS openBGM;
MCI_PLAY_PARMS playBGM;

// effect
MCI_OPEN_PARMS openEffect;
MCI_PLAY_PARMS playEffect;
MCI_OPEN_PARMS openCorrectEffect;
MCI_PLAY_PARMS playCorrectEffect;

MCI_OPEN_PARMS openItemEffect;
MCI_PLAY_PARMS playItemEffect;

UINT dwID;
UINT dwIDOut;
UINT dwIDCor;
UINT dwIDItem;

void PlayingBGM()
{
	openBGM.lpstrElementName = TEXT("jazzyfrenchy.mp3");
	openBGM.lpstrDeviceType = TEXT("mpegvideo");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)& openBGM);
	dwID = openBGM.wDeviceID;
	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT,(DWORD)(LPVOID)&playBGM);
}

void PlayingOutEffect()
{
	mciSendCommand(dwIDOut, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&playEffect);
	openEffect.lpstrElementName = L"synth.wav";
	openEffect.lpstrDeviceType = TEXT("waveaudio");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openEffect);
	dwIDOut = openEffect.wDeviceID;
	mciSendCommand(dwIDOut, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&playEffect);
}

void PlayingCorrectEffect()
{
	mciSendCommand(dwIDCor, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&playCorrectEffect);
	openCorrectEffect.lpstrElementName = L"pickupCoin (1).wav";
	openCorrectEffect.lpstrDeviceType = TEXT("waveaudio");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openCorrectEffect);
	dwIDCor = openCorrectEffect.wDeviceID;
	mciSendCommand(dwIDCor, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&playCorrectEffect);
}

void PlayingItemEffect()
{
	mciSendCommand(dwIDItem, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)&playItemEffect);
	openItemEffect.lpstrElementName = L"powerUp (1).wav";
	openItemEffect.lpstrDeviceType = TEXT("waveaudio");
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openItemEffect);
	dwIDItem = openItemEffect.wDeviceID;
	mciSendCommand(dwIDItem, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&playItemEffect);
}

