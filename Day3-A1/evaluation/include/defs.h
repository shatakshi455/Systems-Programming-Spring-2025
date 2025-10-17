#include <stdio.h>
#include <stdlib.h>

#ifndef _DEFS_H_
#define _DEFS_H_

#define ROWS	30
#define COLS	30
typedef struct MATRIX {
	int row;
	int col;
	int elem[ROWS][COLS];
} Matrix;
#endif
