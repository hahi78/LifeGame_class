//========================================
//	ライフゲーム:フィールド
//========================================
#include "Field.h"
#include "Utility.h"
#include <malloc.h> // malloc(),free()
#include <stdio.h>  // printf()


Field::Field(int width, int height,bool isLoop)
{
	m_width = width;
	m_height = height;
	m_isLoop = isLoop;
	int cellsSize = sizeof(bool) * height * width;
	m_cells[0] = (bool*)malloc(cellsSize);
	m_cells[1] = (bool*)malloc(cellsSize);
	ClearCells(m_cells[0]);
	ClearCells(m_cells[1]);
	m_currentIdx = 0;

}
Field::~Field()
{
	free(m_cells[0]);
	free(m_cells[1]);
}

void Field::ClearCells(bool* cells)
{
	
	for (int i = 0; i < m_width * m_height; i++) {
		cells[i] = false;
	}
}

void Field::DrawField()
{
	DrawField(m_cells[m_currentIdx]);
}

void Field::SetCell(bool* cells, int x, int y,bool isLive)
{
	if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
		int idx = y * m_width + x;
		cells[idx] = isLive;
	}
}

bool Field::GetCell(bool* cells, int x, int y)
{
	if (m_isLoop) {
		if (x < 0 || x >= m_width) {
			x =( x + m_width ) % m_width;
		}
		if (y < 0 || y >= m_height) {
			y = (y + m_height) % m_height;
		}
	}
	else {
		if (x < 0 || x >= m_width || y < 0 || y >= m_height) {
			return false;
		}
	}

	int idx = y * m_width + x;
	return cells[idx];
}

void Field::DrawField(bool* cells)
{
	ClearScreen();

	int x, y;
	for (y = 0; y < m_height; y++) {
		for (x = 0; x < m_width; x++) {
			int idx = y * m_width + x;
			const char *c = GetCell(cells,x,y) ? "*" : " ";
			printf(c);
		}
		printf("\n");
	}
}

int Field::GetLivingCellsCount(bool *cells,int xx, int yy)
{
	int count = 0;
	int x, y;
	for (y = yy - 1; y <= yy + 1; y++) {
		for (x = xx - 1; x <= xx + 1; x++) {
			if (x == xx && y == yy) {
				continue;
			}
			if (GetCell(cells, x, y)) {
				count++;
			}
		}
	}
	return count;
}

void Field::StepSimulation()
{
	bool* srcCells = m_cells[m_currentIdx];
	bool* dstCells = m_cells[m_currentIdx ^ 1];
	StepSimulation(srcCells, dstCells);
	m_currentIdx = m_currentIdx ^ 1; // 0<=>1
}

void Field::StepSimulation(bool* srcCells, bool *dstCells)
{
	int x, y;
	for (y = 0; y < m_height; y++) {
		for (x = 0; x < m_width; x++) {
			bool isLive = false;
			int livingCellCount=GetLivingCellsCount(srcCells, x, y);
			switch (livingCellCount) {
			case 0:
			case 1:
				isLive = false;
				break;
			case 2:
				isLive = GetCell(srcCells, x, y);
				break;
			case 3:
				isLive = true;
				break;
			case 4:
			case 5:
			case 6:
				isLive = false;
				break;
			}
			SetCell(dstCells, x, y, isLive);
		}
	}
}

void Field::PatternTransfer(int dstX, int dstY, int srcWidth, int srcHeight, bool* pattern)
{
	bool* cells = m_cells[m_currentIdx];
	PatternTransfer(cells, dstX, dstY, srcWidth, srcHeight, pattern);
}

void Field::PatternTransfer(bool* cells, int dstX, int dstY, int srcWidth, int srcHeight, bool* pattern)
{
	int x, y;
	for (y = 0; y < srcHeight; y++) {
		for (x = 0; x < srcWidth; x++) {
			bool isLive = pattern[y * srcWidth + x];
			SetCell(cells, dstX + x, dstY + y, isLive);
		}
	}
}