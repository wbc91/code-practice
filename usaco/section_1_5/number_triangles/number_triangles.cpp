/*
ID: 08300242
LANG: C++
TASK: numtri
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int triangles[500550];
int state[500550];
int R;

int calc(int grade, int index) {
	int global_index = grade*(grade-1)/2+index-1;
	if (state[global_index] != -1) {
		return state[global_index];
	}
	int sum = triangles[global_index];
	if (grade == R) {
		return sum;
	}

	int sum1 = sum + calc(grade+1, index);
	int sum2 = sum + calc(grade+1, index+1);

	sum = sum1>sum2?sum1:sum2;
	state[global_index] = sum;
	return sum;
}

int main(void) {
	FILE *fin, *fout;
	fin = fopen("numtri.in", "r");
	fout = fopen("numtri.out", "w");
	fscanf(fin, "%d", &R);
	memset(triangles, 0, sizeof(triangles));
	for (int i = 0; i < (R+1)*R/2; i++) {
		fscanf(fin, "%d", &triangles[i]);
		state[i] = -1;
	}
	fprintf(fout, "%d\n", calc(1, 1));
	fclose(fin);
	fclose(fout);
}