/*
ID: 08300242
LANG: C++
TASK: crypt1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool judgePrime (int number) {
	if(number == 2 || number == 3 || number == 5 || number == 7) {
		return true;
	}
	return false;
}

bool judgeNumberPrime (int number) {
	bool flag = false;
	while(number) {
		if(judgePrime(number%10)){
			flag = true;
			break;
		}
		number /= 10;
	}
	return flag;
}

bool isInArray (int number, int* array, int N) {
	for (int i = 0; i < N; i++) {
		if(array[i] == number ){
			return true;
		}
	}

	return false;
}

bool isNumberLegal (int number, int* array, int N, int digit) {
	bool flag = true;
	int countBit = 0;
	while(number) {
		countBit++;
		if(!isInArray(number%10, array, N)){
			flag = false;
			break;
		}
		number /= 10;
	}

	if(flag && digit != 0 && countBit != digit) {
		flag = false;
	}

	return flag;
}

int main(void) {
	FILE *fin, *fout;
	fin = fopen("crypt1.in", "r");
	fout = fopen("crypt1.out", "w");
	int N;
	int a[10];
	fscanf(fin, "%d", &N);
	if( N == 0 ){
		fprintf(fout, "%d\n", 0);
		return 0;
	}

	for (int i = 0; i < N; i++) {
		fscanf(fin, "%d", &a[i]);
	}

	int count = 0;
	for (int l1 = 0; l1 < N; l1++) {
		if(a[l1] == 0) {
			continue;
		}
		for (int l2 = 0; l2 < N; l2++) {
			for (int l3 = 0; l3 < N; l3++) {
				for (int l4 = 0; l4 < N; l4++) {
					for (int l5 = 0; l5 < N; l5++) {
						// bool hasPrime = false;
						// if(judgePrime(a[l1]) || judgePrime(a[l2])|| judgePrime(a[l3])|| judgePrime(a[l4])|| judgePrime(a[l5])) {
						// 	hasPrime = true;
						// }

						int num1 = a[l1] * 100 + a[l2] * 10 + a[l3];
						int partial1 = num1*a[l5];

						if(!isNumberLegal(partial1, a, N, 3)) {
							continue;
						}
						// bool showPartial1 = false;
						// bool showPartial2 = false;

						// if(!hasPrime) {
						// 	hasPrime = judgeNumberPrime(partial1);
						// 	// if(hasPrime) showPartial1 = true;
						// }

						int partial2 = num1*a[l4];
						if(!isNumberLegal(partial2, a, N, 3)) {
							continue;
						}

						// if(!hasPrime) {
						// 	hasPrime = judgeNumberPrime(partial2);
						// 	// if(hasPrime) showPartial2 = true;
						// }

						partial2 *= 10;

						int result = partial1 + partial2;

						if(!isNumberLegal(result, a, N, 4)) {
							continue;
						}

						// if(!hasPrime) {
						// 	hasPrime = judgeNumberPrime(result);
						// 	if(!hasPrime) {
						// 		continue;
						// 	}
						// }

						// if(!judgeNumberPrime(result)){
						// 	if(showPartial1) {
						// 		printf("partial1 %d, %d, %d, %d, %d\n", a[l1],a[l2],a[l3],a[l4],a[l5]);	
						// 	}

						// 	if(showPartial2) {
						// 		printf("partial2 %d, %d, %d, %d, %d\n", a[l1],a[l2],a[l3],a[l4],a[l5]);		
						// 	}	
						// }
						
						// printf("%d%d%d%d%d\n", a[l1],a[l2],a[l3],a[l4],a[l5]);
						count++;
					}
				}
			}
		}
	}

	fprintf(fout, "%d\n", count);
	return 0;

}
