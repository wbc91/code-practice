/*
ID: 08300242
LANG: C++
TASK: barn1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Margin Margin;
struct Margin{
	int pre_index;
	int next_index;
	int distance;
};

int marginCmp(const void *va , const void *vb) {
	return ((Margin*)vb)->distance - ((Margin*)va)->distance;
}

int cmp(const void *va, const void *vb) {
	return *(int*)va - *(int*)vb;
}

Margin margin[200];

int main(void) {
    FILE *fin, *fout;
    fin = fopen("barn1.in", "r");
    fout = fopen("barn1.out", "w");

    int M, S, C;
    int tmp = 0;
    int stall[200];
    memset(stall, 0, sizeof(stall));

    fscanf(fin, "%d %d %d", &M, &S, &C);
    for(int i = 0; i < C; i++) {
    	fscanf(fin, "%d", &tmp);
    	stall[i] = tmp;
    }
    qsort(stall, C, sizeof(stall[0]), cmp);

    for(int i = 0; i < C; i++) {
    	if(i != 0) {
    		margin[i-1].pre_index = i-1;
    		margin[i-1].next_index = i;
    		margin[i-1].distance = stall[i]-stall[i-1];
    	}
    }

    qsort(margin, C-1, sizeof(margin[0]), marginCmp);
    int tmpMargins[110];
    int tmpMarginIndex = 0;
    int result = 0;
    tmpMargins[tmpMarginIndex] = stall[0];

    int iter_num = M<C?M-1:C-1;
    for(int i = 0; i < iter_num; i++) {
    	tmpMarginIndex++;
    	tmpMargins[tmpMarginIndex] = stall[margin[i].pre_index];
    	printf("%d\n", stall[margin[i].pre_index]);
    	tmpMarginIndex++;
    	tmpMargins[tmpMarginIndex] = stall[margin[i].next_index];
    	printf("%d\n", stall[margin[i].next_index]);
    }
    tmpMarginIndex++;
    tmpMargins[tmpMarginIndex] = stall[C-1];

    qsort(tmpMargins, tmpMarginIndex+1, sizeof(tmpMargins[0]), cmp);

    for(int i = 0; i <= tmpMarginIndex; i++) {
    	if(i % 2 != 0) {
    		result += tmpMargins[i]-tmpMargins[i-1]+1;
    	}
    }

    fprintf(fout, "%d\n", result);

}
