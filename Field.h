#pragma once
//========================================
//	���C�t�Q�[��:�t�B�[���h
//========================================
#include <stdio.h> // printf

class Field
{
private:
	bool *m_cells[2];
	int m_width;
	int m_height;
	int m_currentIdx;
	bool m_isLoop;  // ���E�A�㉺�����[�v���Ă���
public:
	// �R���X�g���N�^
	Field(int width, int height, bool isLoop);
	// �f�X�g���N�^
	~Field();

	// �\��
	void DrawField();
	// �V�~�����[�V�����P�X�e�b�v����
	void StepSimulation();
	// �p�^�[���]��
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