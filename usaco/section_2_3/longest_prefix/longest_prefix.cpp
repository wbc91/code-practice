/*
ID: 08300242
LANG: C++
TASK: prefix
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
std::string seq;
std::string patterns[210];
int newState[210];
int state[200010];
int main(void) {
	FILE*fin,*fout;
	fin = fopen("prefix.in", "r");
	fout = fopen("prefix.out", "w");
	memset(state, 0, sizeof(state));
	int seqLen = 0;
	int patCnt = 0;

	char str[81];
	fscanf(fin, "%s",str);  
	while (str[0]!='.') {  
	    patterns[patCnt++]=str;   
		fscanf(fin, "%s",str);  
	}  
	while (~fscanf(fin,"%s",str)) seq+=str; 
	seqLen = seq.length();
	std::string tmpSeq;
	int startPos = 0;
	int stateNum = 0;
	int tmpStateNum = 0;
	while(true) {
		for (int i = 0; i < stateNum || (stateNum == 0 && i<=stateNum); i++) {
			if (stateNum) startPos = newState[i];
			for (int j = 0; j < patCnt; j++) {
				std::string pat = patterns[j];
				if (pat.length() > (seqLen-startPos)) continue;
				else if (state[pat.length()+startPos]) continue;
				bool match = true;
				for (int k = 0; k < pat.length(); k++) {
					if (pat[k] != seq[startPos+k]) {
						match = false;
						break;
					}
				}
				if (match) {
					state[pat.length()+startPos] = 1;
					newState[tmpStateNum++] = pat.length()+startPos;
				}
			}
		}
		if (!tmpStateNum)break;
		stateNum = tmpStateNum;
		tmpStateNum = 0;
	}

	for (int i = seqLen; i >= 0; i--) {
		if (state[i] || !i) {
			fprintf(fout, "%d\n", i);
			break;
		}
	}
}