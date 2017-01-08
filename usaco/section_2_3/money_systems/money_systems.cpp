/*
ID: 08300242
LANG: C++
TASK: money
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int V,N;
int cs[26];
long long state[26][10010];
FILE*fin, *fout;

long long dfs(int nodeIndex, int sum) {
	if (state[nodeIndex][sum]) {
		return state[nodeIndex][sum];
	}
	long long result = 0;
	int node = cs[nodeIndex];
	if (nodeIndex == 0) {
		if (sum % node == 0){
			++result;
		}
		state[nodeIndex][sum] = result;
		return result;
	} else if (nodeIndex > 0 && sum == 0) {
		++result;
		state[nodeIndex][sum] = result;
		return result;
	}

	int count = sum/node;
	for (int i = 0; i <= count; i++) {
		result += dfs(nodeIndex-1, sum-i*node);
	}

	state[nodeIndex][sum] = result;
	return result;
}

int comp(const void*a, const void*b) {
	return *(int*)a-*(int*)b;
}

int main(void) {
	fin = fopen("money.in", "r");
	fout = fopen("money.out", "w");
	fscanf(fin, "%d %d", &V,&N);
	for (int i = 0; i < V; i++) {
		fscanf(fin, "%d", &cs[i]);
	}
	for (int i = 0; i <= V; i++) 
		for (int j = 0; j < N; j++)
			state[i][j] = 0;
	qsort(cs, V, sizeof(int), comp);	
	
	fprintf(fout, "%lld\n", dfs(V-1, N));

}