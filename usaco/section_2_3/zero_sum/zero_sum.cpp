/*
ID: 08300242
LANG: C++
TASK: zerosum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int state[65536];

FILE*fin, *fout;

void calc(int opNum) {
	char operators[10];
	int opIndex = N-1;
	while(opNum) {
		switch(opNum%4) {
			case 1: {
				operators[opIndex] = ' ';
				break;
			}
			case 2: {
				operators[opIndex] = '+';
				break;
			}
			case 3: {
				operators[opIndex] = '-';
				break;
			}
		}
		opNum/=4;
		--opIndex;
	}	
	int sum = 0;
	int preDir = 0; //0:+, 1:-
	int tmpSum = 1;
	for (int i = 2; i <= N; i++) {
		switch(operators[i-1]) {
			case '+' : {
				if (!preDir)
					sum += tmpSum;
				else 
					sum -= tmpSum;
				preDir = 0;
				tmpSum = i;
				break;
			}
			case '-' : {
				if (!preDir)
					sum += tmpSum;
				else 
					sum -= tmpSum;
				preDir = 1;
				tmpSum = i;
				break;
			}
			case ' ' : {
				tmpSum = tmpSum*10+i;
				break;
			}
		}
	}
	if (!preDir)
		sum += tmpSum;
	else 
		sum -= tmpSum;

	if (sum == 0) {
		for (int i = 1; i < N; i++) {
			fprintf(fout, "%d%c", i, operators[i]);
		}
		fprintf(fout, "%d\n", N);	
	}
}

int main(void) {
	fin = fopen("zerosum.in", "r");
	fout = fopen("zerosum.out", "w");
	fscanf(fin, "%d", &N);
	state[0] = 1;
	int minIndex = 0;
	int maxIndex = 0;
	for (int i = 2; i <= N; i++) {
		for (int index = minIndex; index <= maxIndex; index++) {
			if (state[index]) {
				for (int j = 1; j < 4; j++) {
					state[index*4+j]=1;

					if (i == N) {
						calc(index*4+j);
					}
				}	
			}
		}
		minIndex = minIndex*4+1;
		maxIndex = maxIndex*4+3;
	}
}