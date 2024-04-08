//========================================
//	ライフゲーム:メイン
//========================================
#include "Field.h"
#include "Utility.h"

int main()
{
    const int patternWidth = 10;
    const int patternHeight = 8;

    bool pattern[patternHeight][patternWidth] =
    {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,1,0,1,1,0},
        {0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    const int FIELD_HEIGHT = 12;
    const int FIELD_WIDTH = 12;

    Field* field = new Field(FIELD_WIDTH, FIELD_HEIGHT, true);
    field->PatternTransfer(
        FIELD_WIDTH / 2 - patternWidth / 2,
        FIELD_HEIGHT / 2 - patternHeight / 2,
        patternWidth,
        patternHeight,
        (bool*)pattern);

    while (1) {
        field->DrawField();
        Sleep_mSec( 1000/60 );
        field->StepSimulation();
    }

    delete field;
    return 0;
}