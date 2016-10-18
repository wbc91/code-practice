/*
ID: 08300242
LANG: C++
TASK: hamming
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int N,B,D;
int selected[65];
int marked = 0;
FILE*fin, *fout;

int hamDis(int a, int b) {
	int dis = 0;
	int xorsum = a^b;
	while(xorsum) {
		if (xorsum%2) {
			++dis;
		}
		xorsum/=2;
	}
	return dis;
}


int main(void) {
	fin = fopen("hamming.in", "r");
	fout = fopen("hamming.out", "w");
	fscanf(fin, "%d %d %d", &N, &B, &D);
	memset(selected, 0, sizeof(selected));
	int setNum = 1 << B;
	for (int i = 0; i < setNum; i++) {
		if (marked == N)break;
		if (i == 0) {
			selected[marked++] = i;
			continue;
		}
		bool flag = true;
		for (int j = 0; j < marked; j++) {
			if (hamDis(i, selected[j]) < D) {
				flag = false;
				break;
			}
		}
		if (flag) {
			selected[marked++] = i;
		}
	}

	for (int i = 0; i < N; i++) {
		if ((i+1)%10 == 0) {
			fprintf(fout, "%d\n", selected[i]);
		}
		else {
			if (i == N-1) {
				fprintf(fout, "%d", selected[i]);
			}
			else {
				fprintf(fout, "%d ", selected[i]);	
			}
			
		}
	}
	if (N%10) {
		fprintf(fout, "\n");	
	}
	
}