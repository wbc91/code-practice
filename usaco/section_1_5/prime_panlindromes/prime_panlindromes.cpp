/*
ID: 08300242
LANG: C++
TASK: pprime
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int rangeA,rangeB;
int bit[10];

bool isPrime(int number) {
	int tmp = sqrt(number);
	for (int i = 2; i <= tmp; i++) {
		if (number % i == 0){
			return false;
		} 
	}

	return true;
}

bool isPanlindrome(int number) {
	memset(bit, 0, sizeof(bit));
	int bitNum = 0;
	while(number) {
		bit[bitNum++] = number%10;
		number /= 10;
	}

	for (int i = 0; i < bitNum; i++) {
		if (bit[i] != bit[bitNum-1-i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	FILE *fin, *fout;
	fin = fopen("pprime.in", "r");
	fout = fopen("pprime.out", "w");
	fscanf(fin, "%d", &rangeA);
	fscanf(fin, "%d", &rangeB);

	int rangeBtmp = rangeB < 1000000?rangeB:1000000;

	for (int i = rangeA; i <= rangeBtmp; i++) {
		if (i %2 == 0) continue;
		if (isPanlindrome(i) && isPrime(i)) {
			fprintf(fout, "%d\n", i);
		}
	}	
	
	if (rangeB >= 1000000) {
		for (int d1 = 1; d1 <= 9; d1+=2) {
			for(int d2 = 0; d2 <= 9; d2++) {
				for (int d3 = 0; d3 <= 9; d3++) {
					for (int d4 = 0; d4 <= 9; d4++) {
						int panlindrome = 1000000*d1+100000*d2+10000*d3+1000*d4+100*d3+10*d2+d1;
						if (panlindrome>=rangeA && panlindrome <= rangeB && isPrime(panlindrome)) {
							fprintf(fout, "%d\n", panlindrome);
						}
					}
				}
			}
		}
	}
	
}