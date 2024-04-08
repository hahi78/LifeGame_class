#pragma once
//========================================
//	ライフゲーム:フィールド
//========================================
#include <stdio.h> // printf

class Field
{
private:
	bool *m_cells[2];
	int m_width;
	int m_height;
	int m_currentIdx;
	bool m_isLoop;  // 左右、上下がループしている
public:
	// コンストラクタ
	Field(int width, int height, bool isLoop);
	// デストラクタ
	~Field();

	// 表示
	void DrawField();
	// シミュレーション１ステップ処理
	void StepSimulation();
	// パターン転送
	void PatternTransfer(int dstX, int dstY, int srcWidth, int srcHeight, bool* pattern);

protected:
	void ClearCells(bool* cells);
	void SetCell(bool* cells, int x, int y, bool isLive);
	bool GetCell(bool* cells, int x, int y);

	int GetLivingCellsCount(bool *cells,int x, int y);
	void DrawField(bool* cells);
	void StepSimulation(bool* srcCells, bool* dstCells);
	void PatternTransfer(bool* cells, int dstX, int dstY, int srcWidth,int srcHeight, bool* pattern);
};