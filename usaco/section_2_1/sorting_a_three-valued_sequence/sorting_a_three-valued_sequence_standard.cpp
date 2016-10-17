#include <stdio.h>

int list[1000], N, res, count[3], start[3];
in[3][3]; // this counts the number of "1"s in bucket "2", ...

void readFile() {
    FILE *f; int i;
    f = fopen("sort3.in", "r");
    fscanf(f, "%d", &N);
    for(i = 0; i < N; i++) {
        fscanf(f, "%d", &list[i]);
    }
    fclose(f);
}

void writeFile() {
    FILE *f;
    f = fopen("sort3.out", "w");
    fprintf(f, "%d\n", res);
    fclose(f);
}

void findBuckets() {
    int i;
    for(i = 0; i < N; i++) count[list[i]-1]++;
    start[0] = 0;
    start[1] = count[0];
    start[2] = count[0] + count[1];
}

void findWhere() {
    int i, j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < count[i]; j++) in[list[start[i] + j]-1][i]++;
    }
   }

void sort() {
    int h;
    // 1 <-> 2
    h = in[0][1];
    if(in[1][0] < h) h = in[1][0];
    res += h; in[0][1] -= h; in[1][0] -= h;
    // 3 <-> 2
    h = in[2][1];
    if(in[1][2] < h) h = in[1][2];
    res += h; in[2][1] -= h; in[1][2] -= h;
    // 1 <-> 3
    h = in[0][2];
    if(in[2][0] < h) h = in[2][0];
    res += h; in[0][2] -= h; in[2][0] -= h;

    // Cycles
    res += (in[0][1] + in[0][2]) * 2;
}

void process() {
    findBuckets();
    findWhere();
    sort();
}

int main () {
    readFile();
    process();
    writeFile();
    return 0;
}