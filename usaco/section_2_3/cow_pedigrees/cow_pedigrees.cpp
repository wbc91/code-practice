/*
ID: 08300242
LANG: C++
TASK: nocows
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, K;
int state[110][210];
int chooseNum[200][200];
int nodeChild[2100000];
int fac[300];

#define MODE 9901

int judgeMin(int power, int n) {
	if (power > 8) {
		return n;
	}
	else {
		int num = 1<<power;
		return num < n?num:n;
	}
}

bool judgeChild(int level, int node, int child) {
	if (child == 2) {
		if (node >= 2*level-1) {
			return true;
		}
		else return false;
	}
	else {
		int tmpChild = child/2;
		if (tmpChild%2) tmpChild+=1;
		return judgeChild(level-1, node-child, tmpChild);
	}
}

int choose(int n, int k) {
	if(k > n-k) {
		k = n-k;
	}
	if (chooseNum[n][k]) {
		return chooseNum[n][k];
	}
	memset(fac, 0, sizeof(fac));
	int bit = 1;
	fac[0]=1;
	for (int i=n;i>(n-k);i--){
		int carry = 0;
		for (int j = 0; j <bit; j++) {
			int tmp = fac[j]*i+carry;
			fac[j] = tmp%10;
			carry = tmp/10;
		}
		while(carry) {
			fac[bit++]=carry%10;
			carry/=10;
		}
	}
	while(!fac[bit-1])bit--;
	for (int i=1;i<=k;i++){
		int residue=0;
		for (int j = bit-1; j>=0; j--) {
			residue = residue*10+fac[j];
			if(residue >= i) {
				fac[j]=residue/i;
				residue = residue %i;
			}
			else {
				fac[j] = 0;
			}
		}

		for (int j = bit-1; j>=0&&!fac[j]; j--) {
			bit--;
		}
	}
	int result= 0;
	for (int j = bit-1; j >= 0;j--) {
		result = result*10+fac[j];
		result = result%MODE;
	}
	chooseNum[n][k] = result;
	return result;
}

int main(void) {
	FILE*fin, *fout;
	fin = fopen("nocows.in", "r");
	fout = fopen("nocows.out", "w");
	fscanf(fin, "%d %d", &N, &K);
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			state[i][j] = 0;
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			chooseNum[i][j] = 0;
		}
	}
	//nodeChild[height][node][child]
	memset(nodeChild, 0, sizeof(nodeChild));
	state[2][3] = 1;
	nodeChild[2*20000+2*200+3] = 1;
	for (int i=2;i<K;i++) {
		for (int j=2*i-1; j<=judgeMin(i, N); j+=2) {
			int minK = j-(judgeMin(i-1, j+1)-1);
			if (minK <=2)minK = 2;
			int range = j-(2*(i-1)-1);
			if (range > (1<<(i-1))) 
				range = (1<<(i-1));
			int maxK = minK;
			while(true) {
				if (!judgeChild(i, j, maxK+2)) break;
				maxK += 2;
			}
			for (int k=minK; k <= maxK; k+=2) {
				for (int l=2; l <= N-j; l+=2) {
					int indexBefore = k*20000+i*200+j;
					int indexAfter = l*20000+(i+1)*200+j+l;
					if (l/2 <= k && nodeChild[indexBefore]) {
						int tmpBefore = nodeChild[indexBefore]*choose(k, l/2) %MODE;
						nodeChild[indexAfter] += tmpBefore;
						state[i+1][j+l] += tmpBefore % MODE;
						state[i+1][j+l] = state[i+1][j+l]%MODE;
					}
				}
			}
		}
	}
	fprintf(fout, "%d\n", state[K][N]);
}