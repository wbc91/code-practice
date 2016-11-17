/*
ID: 08300242
LANG: C++
TASK: subset
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int state[16000];

int calc(int sum, int pivot) {
	if (state[pivot*400+sum] >= 0) {
		return state[pivot*400+sum];
	}
	int count = 0;
	if (sum == pivot) {
		count = 1;
		state[pivot*400+sum] = count;
		return count;
	}
	int npivot = (sum-pivot) < (pivot-1)?(sum-pivot):(pivot-1);
	int lastIndex = 1;
	for (int i = npivot; i>=1; i--) {
		if (i*(i+1)/2 < sum-pivot) {
			lastIndex = i+1;
			break;
		}
	}
	for (int i = npivot; i>=lastIndex; i--) {
		count += calc(sum-pivot, i);
	}
	state[pivot*400+sum] = count;
	return count;
}
int main(void) {
	FILE*fin, *fout;
	fin = fopen("subset.in", "r");
	fout = fopen("subset.out", "w");
	fscanf(fin, "%d", &N);
	for (int i = 0; i < 16000; i++) {
		state[i] = -1;
	}
	int count = 0;

	int all_sum = N*(N+1)/2;

	if (all_sum % 2 == 0) {
		int sum = all_sum/2;
		count += calc(sum, N);
	}
	fprintf(fout, "%d\n", count);	
}