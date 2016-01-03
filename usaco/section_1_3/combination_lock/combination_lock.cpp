/*
ID: 08300242
LANG: C++
TASK: combo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

typedef struct Node
{
	Node(int x, int y, int z);
	int x;
	int y;
	int z;
} Node;

Node::Node(int x, int y, int z):x(x), y(y), z(z){}


bool operator< (const Node& lhs, const Node& rhs) {
	return (lhs.x*1000000+lhs.y*1000+lhs.z) < (rhs.x*1000000+rhs.y*1000+rhs.z);
}

std::set<Node> ansSet;

void addNum(int a, int b, int c, int N) {
	char res [50];
	if (a > N) a = a%N;
	if (b > N) b = b%N;
	if (c > N) c = c%N;
	
	if (a <= 0) {
		if((N+a) <= 0){
			return;
		}
		a = N+a;
	}

	if (b <= 0) {
		if((N+b) <= 0){
			return;
		}
		b = N+b;
	}

	if (c <= 0) {
		if((N+c) <= 0){
			return;
		}
		c = N+c;
	}
	Node nd(a,b,c);
	ansSet.insert(nd);					
}

int main(void) {
	FILE *fin, *fout;
	fin = fopen("combo.in", "r");
	fout = fopen("combo.out", "w");

	int N;
	int f[3];
	int m[3];

	fscanf(fin, "%d", &N);
	for (int i = 0; i < 3; i++) {
		fscanf(fin, "%d", &f[i]);
	}

	for (int i = 0; i < 3; i++) {
		fscanf(fin, "%d", &m[i]);
	}

	for (int i = f[0]-2; i <= f[0]+2; i++) {
		for (int j = f[1]-2; j <= f[1]+2; j++) {
			for (int k = f[2]-2; k <= f[2]+2; k++) {
				addNum(i,j,k,N);
			}
		}
	}

	for (int i = m[0]-2; i <= m[0]+2; i++) {
		for (int j = m[1]-2; j <= m[1]+2; j++) {
			for (int k = m[2]-2; k <= m[2]+2; k++) {
				addNum(i,j,k,N);
			}
		}
	}

	fprintf(fout, "%lu\n", ansSet.size());

}

