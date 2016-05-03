/*
ID: 08300242
LANG: C++
TASK: ariprog
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 125010

int cmp(const void *va, const void *vb) {
	return *(int*)va - *(int*)vb;
}

int main(void) {
	int M,N;
	FILE*fin, *fout;
	fin = fopen("ariprog.in", "r");
	fout = fopen("ariprog.out", "w");
	fscanf(fin, "%d", &N);
	fscanf(fin, "%d", &M);
	
	int bqArr[MAXN];
	memset(bqArr, 0, sizeof(bqArr));
	int cnt = 0;
	int max = 0;
	for (int i = 0; i <= M; i++) {
		for (int j = i; j <= M; j++) {
			int tmp = i*i+j*j;
			bqArr[tmp]=1;
			cnt++;

			if (tmp > max) {
				max = tmp;
			}
		}
	}

	int a = 0;
	int b = 1;

	bool exists = false;
	while(true) {
		for (int i = 0; i <= max; i++ ){
			if (bqArr[i] != 1) continue;
			a = i;
			bool flag = true;
			for (int j = 0; j < N; j++) {
				if ((a+j*b > max) || bqArr[a+j*b] == 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				exists = true;
				fprintf(fout, "%d %d\n", a,b);
			}

			if (a+b*(N-1) >= max) {
				break;
			}
		}

		if ((N-1)*b >= max) {
			break;
		}
		b++;
		
	}
	if (!exists) {
		fprintf(fout, "NONE\n");
	}
}