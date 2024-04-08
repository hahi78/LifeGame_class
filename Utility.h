#pragma once
//======================================
//	ユーティリティ
//======================================

enum eKey {
	ARROW_U = 0xe048,
	ARROW_L = 0xe04b,
	ARROW_D = 0xe050,
	ARROW_R = 0xe04d,
	DECIDE = 0x0d,
};
// 乱数初期化
void InitRand();
// キー入力を待つ
void WaitKey();
// キー取得
eKey GetKey();
// 画面クリア
void ClearScreen();
// ミリ秒スリープ
void Sleep_mSec(int mSec);
