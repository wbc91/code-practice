/*
ID: 08300242
LANG: C++
TASK: preface
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int a[10];

void calc(int start, int pivot) {
	if (pivot < 5) {
		if (pivot == 4) {
			a[start]++;a[start+1]++;
		}
		else {
			a[start]+=pivot;
		}
	}
	else {
		if (pivot == 9) {
			a[start]++; a[start+2]++;
		}
		else {
			a[start+1]++;
			a[start]+=pivot-5;
		}
	}
}

char mapS(int num) {
	char symbol;
	switch(num) {
		case 0: {
			symbol = 'I';
			break;
		}
		case 1: {
			symbol = 'V';
			break;
		}
		case 2: {
			symbol = 'X';
			break;
		}
		case 3: {
			symbol = 'L';
			break;
		}
		case 4: {
			symbol = 'C';
			break;
		}
		case 5: {
			symbol = 'D';
			break;
		}
		case 6: {
			symbol = 'M';
			break;
		}
	}
	return symbol;
}

int main(void) {
	FILE* fin, *fout;
	fin = fopen("preface.in", "r");
	fout = fopen("preface.out", "w");
	memset(a, 0, sizeof(a));
	fscanf(fin, "%d", &N);
	int tmp = 0;
	for (int i = 1; i <= N; i++) {
		int tmpi = i;
		if (tmpi/1000) {
			tmp = tmpi/1000;
			a[6]+=tmp;
			tmpi-=tmp*1000;
		}

		if (tmpi/100) {
			tmp = tmpi/100;
			calc(4, tmp);
			tmpi-=tmp*100;
		}

		if (tmpi/10) {
			tmp = tmpi/10;
			calc(2, tmp);
			tmpi-=tmp*10;
		}

		if (tmpi) {
			calc(0, tmpi);
		}
	}

	for (int i = 0; i <= 6; i++) {
		if (a[i]) {
			fprintf(fout, "%c %d\n", mapS(i), a[i]);
		}
	}
}