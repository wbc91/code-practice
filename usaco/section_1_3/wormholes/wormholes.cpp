/*
ID: 08300242
LANG: C++
TASK: wormhole
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

#define MINVX 1000000001

int N;
int x[20];
int y[20];

int calcPerPartition(int* flag) {
	int group[20];
	int groupMap[20]; // same group
	std::set <int> used_point;
	memset(groupMap, 0, sizeof(groupMap));
	memset(group, 0, sizeof(group));

	for (int i = 0; i < N; i++){
		for (int j = i+1; j > i && j < N; j++) {
			if (flag[i] == flag[j]) {
				group[flag[i]] = i;
				groupMap[i] = j;
				groupMap[j] = i;
			}
		}
	}
	
	for (int i = 1; i <= (N/2); i++) {
		int v1 = group[i];
		int v2 = groupMap[v1];

		for (int index_v = 1; index_v <= 2; index_v++) {
			used_point.clear();
			int cur_index;
			if (index_v == 1) {
				cur_index = v1;
			}
			if (index_v == 2) {
				cur_index = v2;
			}

			used_point.insert(cur_index);
			while(true) {
				int vy = y[cur_index];
				int vx = x[cur_index];
				int next_index = -1;
				int min_vx = MINVX;
				for (int j = 0; j < N; j++) {
					if (j == cur_index) continue;
					if (y[j] == vy && x[j] > vx && x[j] < min_vx) {
						min_vx = x[j];
						next_index = j;
					}
				}
				if (next_index == -1) {
					break;
				}
				next_index = groupMap[next_index];
				std::set<int>::iterator it;
				it = used_point.find(next_index);

				if (it!=used_point.end()) {
					return 1;
				} else {
					used_point.insert(next_index);
					cur_index = next_index;
				}
			}
		}
	}

	return 0;

}

int calcResult(int* flag, int group_num, int start_num) {
	int result = 0;
	bool can_calculate = false;
	for (int i = start_num; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (flag[i] == 0 && flag[j] == 0) {
				can_calculate = true;
				flag[i] = flag[j] = group_num;
				result += calcResult(flag, group_num+1, i+1);
				flag[i] = flag[j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (flag[i] == 0) {
			can_calculate = true;
			break;
		}
	}
	if (!can_calculate) {
		result += calcPerPartition(flag);
	}
	
	return result;
}

int main(void) {
	FILE* fin, *fout;
	fin = fopen("wormhole.in", "r");
	fout = fopen("wormhole.out", "w");

	int flag[20];

	memset(flag, 0, sizeof(flag));

	fscanf(fin, "%d", &N);

	for (int i = 0; i < N; i++) {
		fscanf(fin, "%d", &x[i]);
		fscanf(fin, "%d", &y[i]);
	}

	fprintf(fout, "%d\n", calcResult(flag, 1, 0));
}