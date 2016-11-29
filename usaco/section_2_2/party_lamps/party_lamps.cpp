/*
ID: 08300242
LANG: C++
TASK: lamps
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N,C;
int ons[110];
int offs[110];
int state[110];

void generate(int type) {
	switch(type) {
		case 1: {
			for (int i = 1; i <= N; i++) {
				state[i] ^= 1;
			}
			break;
		}
		case 2: {
			for (int i = 1; i <= N; i++) {
				if (i%2) {
					state[i] ^= 1;
				}
			}
			break;
		}
		case 3: {
			for (int i = 1; i <=N; i++) {
				if (i%2 == 0) {
					state[i] ^= 1;
				}
			}
			break;
		}
		case 4: {
			for (int i = 1; i <= N; i++) {
				if ((i-1)%3 == 0) {
					state[i] ^= 1;
				}
			}
			break;
		}
		case 5: {
			for (int i = 1; i <= N; i++) {
				state[i] ^= 1;
			}
			for (int i = 1; i <= N; i++) {
				if ((i-1)%3 ==0) {
					state[i] ^= 1;
				}
			}
			break;
		}
		case 6: {
			for (int i = 1; i <= N; i++) {
				if (i%2) {
					state[i] ^= 1;
				}
			}
			for (int i = 1; i <= N; i++) {
				if ((i-1)%3 == 0) {
					state[i] ^= 1;
				}
			}
			break;
		}
		case 7: {
			for (int i = 1; i <=N; i++) {
				if (i%2 == 0) {
					state[i] ^= 1;
				}
			}
			for (int i = 1; i <= N; i++) {
				if ((i-1)%3 == 0) {
					state[i] ^= 1;
				}
			}
			break;
		}
		default: break;
	}
}

bool judge() {
	for (int i = 1; i <= N; i++) {
		if (offs[i] && !state[i]) {
			return false;
		}
	}

	for (int i = 1; i<= N; i++) {
		if (ons[i] && state[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	FILE*fin, *fout;
	fin = fopen("lamps.in", "r");
	fout = fopen("lamps.out", "w");
	memset(ons, 0, sizeof(ons));
	memset(offs, 0, sizeof(offs));

	fscanf(fin, "%d", &N);
	fscanf(fin, "%d", &C);

	int tmp = 0;
	while(true) {
		fscanf(fin, "%d", &tmp);
		if (tmp == -1){
			break;
		}
		ons[tmp] = 1;
	}

	while(true) {
		fscanf(fin, "%d", &tmp);
		if (tmp == -1) {
			break;
		}
		offs[tmp] = 1;
	}

	for (int i = 1; i <= N;i++) {
		if (ons[i] && offs[i]) {
			fprintf(fout, "IMPOSSIBLE\n");
			exit(0);
		}
	}

	int count = 0;
	int output[10][110];
	int order[10];
	for (int i = 1; i <= 8; i++) {
		if ((C==2 && i==4) || (C==1&&i>=5) || (C==0 && i<8))continue;
		memset(state, 0, sizeof(state));
		generate(i);
		
		if (judge()) {
			for (int j = 1; j<= N; j++) {
				output[count][j] = 1^state[j];
			}
			order[count] = count;
			bool change = false;
			for (int j = count-1; j >= 0; j--) {
				for (int k = 1; k <= N; k++) {
					if (output[order[count]][k]<output[order[j]][k]) {
						change = true;
						break;
					}
					if (output[order[count]][k]>output[order[j]][k]) {
						change = false;
						break;
					}
				}
				if (!change)  {
					int tmp = order[count];
					for (int l = count; l > j+1; l--) {
						order[l] = order[l-1];
					}
					order[j+1] = tmp;
					break;
				}

				if (change && !j) {
					int tmp = order[count];
					for (int l = count; l > j; l--) {
						order[l] = order[l-1];
					}
					order[j] = tmp;
				} 
			}
			++count;
		}
		
	}
	if (!count) {
		fprintf(fout, "IMPOSSIBLE\n");
		exit(0);
	}

	for (int i = 0; i< count; i++) {
		for (int j = 1; j <= N; j++) {
			fprintf(fout, "%d", output[order[i]][j]);
		}
		fprintf(fout, "\n");
	}

}