/*
ID: 08300242
LANG: C++
TASK: sort3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE*fin, *fout;
int N;
int a[1010];
int a1[1010];

void swap(int &a, int &b) {
	a = a+b;
	b = a-b;
	a = a-b;
}


int main(void) {
	fin = fopen("sort3.in","r");
	fout = fopen("sort3.out", "w");
	memset(a, 0, sizeof(a));
	memset(a1, 0, sizeof(a1));
	fscanf(fin, "%d", &N);
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	for (int i = 0; i < N; i++) {
		fscanf(fin, "%d", &a[i]);
		switch(a[i]) {
			case 1: {
				++count1;
				break;
			}
			case 2: {
				++count2;
				break;
			}
			case 3: {
				++count3;
				break;
			}
			default: break;
		}
	}
	
	for (int i = 0; i < count1; i++) {
		a1[i] = 1;
	}
	for (int i = count1; i < count1+count2; i++) {
		a1[i] = 2;
	}
	for (int i = count1+count2; i < N; i++) {
		a1[i] = 3;
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] != a1[i]) {
			for (int j = i+1; j < N; j++){
				if (a[i] == a1[j] && a[j] == a1[i]) {
					swap(a[i], a[j]);
					++count;
					break;
				}
			}
		}
	}
	
	int bitCount = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] != a1[i]) {
			++bitCount;
		}
	}
	count += bitCount/3*2;
	fprintf(fout, "%d\n", count);
}
