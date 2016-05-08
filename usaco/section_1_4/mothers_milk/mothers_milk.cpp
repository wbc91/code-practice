/*
ID: 08300242
LANG: C++
TASK: milk3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LITER 20

int stat[250000];
int output[25];
int maxA,maxB,maxC;
FILE*fin, *fout;

void poor(int A, int B, int C) {
	int statFlag = A*10000+B*100+C;
	if(stat[statFlag]) {
		return;
	}

	stat[statFlag] = 1;
	if (A == 0) {
		output[C] = 1;
	}

	if (A!=0) {
		if (A+B <= maxB) {
			poor(0, A+B, C);
		}
		else {
			poor(A+B-maxB, maxB, C);
		}

		if (A+C <= maxC) {
			poor(0, B, A+C);
		}
		else {
			poor(A+C-maxC, B, maxC);
		}
	}

	if (B!=0) {
		if (B+A <= maxA) {
			poor(B+A, 0, C);
		}
		else {
			poor(maxA, B+A-maxA, C);
		}

		if (B+C <= maxC) {
			poor(A, 0, B+C);
		}

		else {
			poor(A, B+C-maxC, maxC);
		}
	}

	if (C != 0) {
		if (C+A <= maxA) {
			poor(C+A, B, 0);
		}
		else {
			poor(maxA, B, C+A-maxA);
		}

		if (C+B <= maxB) {
			poor(A, C+B, 0);
		}
		else {
			poor(A, maxB, C+B-maxB);
		}
	}

}

int main(void) {
	fin = fopen("milk3.in", "r");
	fout = fopen("milk3.out", "w");
	int sortedOutput[25];
	memset(stat, 0, sizeof(stat));
	memset(output, 0, sizeof(output));
	memset(sortedOutput, 0, sizeof(sortedOutput));
	fscanf(fin, "%d %d %d", &maxA, &maxB, &maxC);
	poor(0,0,maxC);
	
	int sortedOutputIndex = 0;
	for (int i = 0; i <= MAX_LITER; i++) {
		if (output[i] == 1) {
			sortedOutput[sortedOutputIndex++] = i;
		}
	}

	for (int i = 0; i < sortedOutputIndex; i++) {
		if (i == sortedOutputIndex-1) {
			fprintf(fout, "%d", sortedOutput[i]);
		}
		else {
			fprintf(fout, "%d ", sortedOutput[i]);
		}
	}
	fprintf(fout, "\n");
	fclose(fin);
	fclose(fout);
}