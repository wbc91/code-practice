/*
ID: 08300242
LANG: C++
TASK: frac1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE*fin, *fout;
int N;
int fractionCount = 0;
typedef struct Fraction {
    Fraction();
    int up;
    int down;
}Fraction;
Fraction fracs[14400];

Fraction::Fraction():up(0), down(0){}

int gcd(int m, int n) {
    if (m < n) {
        int tmp = m;
        m = n;
        n = tmp;
    }
    int c = m%n;
    while(c) {
        m = n;
        n = c;
        c = m%n;
    }
    return n;
}

void dfs(int n) {
    if (n == 1) {
        Fraction f;
        f.up = 0;
        f.down = 1;
        fracs[fractionCount++] = f;
        f.up = 1;
        fracs[fractionCount++] = f;
        return;
    }
    else {
        dfs(n-1);
        for (int i = 1; i < n; i++) {
            if (gcd(i,n) > 1) {
                continue;
            }
            Fraction f;
            f.up = i;
            f.down = n;
            for(int j = fractionCount-1; j >= 0; j--) {
                if ((float)fracs[j].up/(float)fracs[j].down > (float)f.up/(float)f.down) {
                    Fraction ftmp = fracs[j];
                    fracs[j] = f;
                    fracs[j+1] = ftmp;
                }
                else break;
            }
            ++fractionCount;
        }
    }
}

int main(void) {
    fin = fopen("frac1.in","r");
    fout = fopen("frac1.out", "w");
    memset(fracs, 0, sizeof(fracs));
    fscanf(fin, "%d", &N);
    dfs(N);
    for (int i = 0; i < fractionCount; i++) {
        fprintf(fout, "%d/%d\n", fracs[i].up, fracs[i].down);
    }
}