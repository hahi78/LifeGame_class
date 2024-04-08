//======================================
//	ユーティリティ
//======================================
#include "Utility.h" // eKey
#include <stdlib.h> // srand()
#include <time.h>  // time()
#include <windows.h> // GetStdHandle(),SetConsoleMode()
#include <stdio.h> // printf()
#include <conio.h> // _getch()

// 乱数初期化
void InitRand()
{
	srand((unsigned int)time(NULL));
}

// キー入力を待つ
void WaitKey()
{
	_getch();
}

// キー取得
eKey GetKey()
{
	int key=_getch();
	if (key == 0xe0) {
		int key2 = _getch();
		key = 0xe000 + key2;
	}
	return (eKey)key;
}

bool s_modeSet = false;

void ClearScreen()
{
#if false
	// cmd.exe を呼び出して cls を行う
	system("cls");
#else
	// 画面モードを切り替えてエスケープシーケンスが使えるようにする
	if (s_modeSet == false) {
		s_modeSet = true;
		HANDLE h = GetStdHandle(-11);
		SetConsoleMode(h, 0x07);
	}
	printf("\x1b[2J"	// 画面クリア
		"\x1b[0;0H");	// カーソルを0,0に
#endif
}

void Sleep_mSec(int mSec)
{
	Sleep(mSec);
}