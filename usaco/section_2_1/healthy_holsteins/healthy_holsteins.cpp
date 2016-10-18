/*
ID: 08300242
LANG: C++
TASK: holstein
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2147483647


FILE*fin, *fout;
int V,G;
int vType[26];
int gType[400];
int vRes[26];
int minPath[26];

int main(void) {
	fin = fopen("holstein.in", "r");
	fout = fopen("holstein.out", "w");
	memset(vType, 0, sizeof(vType));
	memset(gType, 0, sizeof(gType));
	memset(minPath, 0, sizeof(minPath));
	fscanf(fin, "%d", &V);
	for (int i = 0; i < V; i++) {
		fscanf(fin, "%d", &vType[i]);
	}

	fscanf(fin, "%d", &G);

	for (int i = 0; i < G; i++) {
		for (int j = 0; j < V; j++) {
			fscanf(fin, "%d", &gType[i*V+j]);
		}
	}

	int setNum = (1<<G)-1;
	int minScoops = MAXN;
	int minVitamin = MAXN;
	for (int i = 1; i <= setNum;i++) {
		int tmpi = i;
		int scoops = 0;
		int index = 0;
		int *tmpS = new int[G];
		while(tmpi) {
			tmpS[index++] = tmpi%2;
			if (tmpi%2) {
				++scoops;	
			}
			tmpi/=2;
		}
		if(scoops > minScoops) {
			free(tmpS);
			continue;
		}
		memset(vRes, 0, sizeof(vRes));
		for (int j = 0; j < index; j++) {
			if (!tmpS[j]) continue;
			for (int k = 0; k < V; k++) {
				vRes[k] += gType[j*V+k];
			}
		}
		printf("%d %d\n", i, scoops);
		bool flag = true;
		for (int k = 0; k < V; k++) {
			printf("%d %d ", vRes[k], vType[k]);
			if (vRes[k] < vType[k]) {
				flag = false;
				break;
			}
		}
		printf("\n");

		if (flag) {
			int vitamin = 0;
			for (int k = 0; k < V; k++) {
				vitamin+= vRes[k];
			}
			int *path = new int[scoops];
			int pathIndex = 0;
			for (int j = 0; j < index; j++) {
				if (!tmpS[j]) continue;
				path[pathIndex++] = j+1;
			}
			if (scoops < minScoops) {
				minScoops = scoops;
				for (int j = 0; j < minScoops; j++) {
					minPath[j] = path[j];
				}
			}
			else if (vitamin < minVitamin) {
				minVitamin = vitamin;

				for (int j = 0; j < minScoops; j++) {
					minPath[j] = path[j];
				}
			}
			else if (vitamin == minVitamin) {
				bool flag1 = false;
				for (int j = 0; j < minScoops; j++) {
					if (minPath[j] < path[j]) {
						flag1 = true;
					}
				}
				if (flag) {
					for (int j = 0; j < minScoops; j++) {
						minPath[j] = path[j];
					}
				}
			}

			free(path);
		}
		free(tmpS);
	}
	fprintf(fout, "%d ", minScoops);
	for (int i = 0; i < minScoops; i++) {
		if (i == minScoops-1) {
			fprintf(fout, "%d\n", minPath[i]);
		}
		else {
			fprintf(fout, "%d ", minPath[i]);
		}
	}
}