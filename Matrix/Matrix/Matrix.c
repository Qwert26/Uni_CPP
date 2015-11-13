#include <stdio.h>
#include <stdlib.h>
int ** createMatrix(int row,int col) {
	//Als erstes brauchen wir einen Pointer auf ein 1-dimensionales Array von Pointern mit der Laenge von row.
	int** ret = malloc(sizeof(int*)*row);
	if (!ret) {
		return NULL;
	}
	//Als zweites den Platz für die eigentliche Matrix.
	int* matrix = malloc(sizeof(int)*row*col);
	if (!matrix) {
		free(ret);
		return NULL;
	}
	for (int r = 0;r < row;r++) {
		ret[r] = matrix+r*col;
	}
	return ret;
}
void deleteMatrix(int ***matrix) {
	int** pointerArray = *matrix;
	int* beginOfData = *pointerArray;
	free(beginOfData);
	free(pointerArray);
}
int main(int argc, char *argv[]) {
	int rows, cols, i, j;
	int ** m;
	if (argc != 3) {
		printf("Usage: %s <rows> <cols>", argv[0]);
		return EXIT_FAILURE;
	}
	rows = atoi(argv[1]);
	cols = atoi(argv[2]);
	if (rows <= 0 || cols <= 0) {
		printf("rows and cols must be at least 1");
		return EXIT_FAILURE;
	}
	m = createMatrix(rows, cols);
	if (!m) {
		printf("Out of memory\n");
		return EXIT_FAILURE;
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			m[i][j] = i + j;
		}
	}
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	deleteMatrix(&m);
	return EXIT_SUCCESS;
}