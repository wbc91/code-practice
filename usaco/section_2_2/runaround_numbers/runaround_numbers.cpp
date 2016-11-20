/*
ID: 08300242
LANG: C++
TASK: runround
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long M;
int array[10];
int state[10];
int visited[10];

bool isRunAround(unsigned long N) {
	memset(array, 0, sizeof(array));
	memset(state, 0, sizeof(state));
	memset(visited, 0, sizeof(visited));
	unsigned long tmp = N;
	int index = 0;
	while(tmp) {
		array[index] = tmp % 10;
		tmp /= 10;
		if (!array[index]){
			return false;
		}
		if (visited[array[index]]) {
			return false;
		}
		visited[array[index]] = 1;
		index++;
	}

	for (int i = index-1; i >= index/2; i--) {
		int tmpi = array[i];
		array[i] = array[index-1-i];
		array[index-1-i] = tmpi;
	}

	int pivot = 0;
	state[pivot] = 1;
	bool flag = true;
	while(true) {
		pivot+=array[pivot]%index;
		pivot = pivot % index;
		if(state[pivot]) {
			if (pivot) {
				flag = false;
				break;
			}
			for (int i=0; i < index; i++) {
				if (!state[i]) {
					flag = false;
					break;
				}
			}
			break;
		}
		else {
			state[pivot] = 1;
		}
	}

	return flag;
}

int main(void) {
	FILE*fin, *fout;
	fin = fopen("runround.in", "r");
	fout = fopen("runround.out", "w");
	fscanf(fin, "%lu", &M);
	while(true) {
		++M;
		if (isRunAround(M)) {
			fprintf(fout, "%lu\n", M);
			break;
		}
	}


}