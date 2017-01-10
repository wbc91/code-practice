/*
ID: 08300242
LANG: C++
TASK: concom
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE*fin, *fout;
int control[110][110];
int beencontrol[110][110];
int stocks[110][110];
int showed[110];
int used[110];
int N;

void checkControl(int lc, int rc) {
	if (control[lc][rc])return;
	if (stocks[lc][rc] > 50) {
	    control[lc][rc] = 1;
		beencontrol[rc][lc] = 1;
		for (int j=1; j <= 100; j++) {
			if (j == rc || !showed[j]) continue;
			stocks[lc][j]+=stocks[rc][j];
			checkControl(lc, j);
		}
	}
}

int main(void) {
    fin = fopen("concom.in", "r");
    fout = fopen("concom.out", "w");

    fscanf(fin,"%d",&N);
    for (int i = 0; i < 110; i++) {
		for (int j = 0; j < 110; j++) {
		    control[i][j] = 0;
		    beencontrol[i][j] = 0;
		    stocks[i][j] = 0;
		}
    }
    memset(showed, 0, sizeof(showed));
    for (int i = 0; i < N; i++) {
		int lc,rc,stock;
		fscanf(fin, "%d %d %d", &lc, &rc, &stock);
		showed[lc]=1;
		showed[rc]=1;
		stocks[lc][rc]+=stock;
		
		checkControl(lc, rc);
		for (int j = 1; j <= 100; j++) {
			if (j == lc || !showed[j])continue;
		    if (beencontrol[lc][j]) {
				stocks[j][rc]+=stock;
				checkControl(j, rc);
		    }
		}
    }
    int num = 0;
    for (int i = 1; i <= 100; i++) {
    	if (showed[i]) {
    		used[num++] = i;
    	}
    }
    
    for (int i = 0; i < num; i++) {
		for (int j=0;j < num; j++) {
			if(j == i)continue;
		    if (control[used[i]][used[j]]){
				fprintf(fout, "%d %d\n", used[i], used[j]);
		    }
		}
    }
}
