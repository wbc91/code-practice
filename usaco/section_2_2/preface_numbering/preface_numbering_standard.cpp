#include <fstream>
using namespace std;
int count[7];
int mult[6] = {5, 2, 5, 2, 5, 2}; // The factors between consecutive roman
				  // numeral letter values.
char roman[] = "IVXLCDM";
int vals[7] = {1, 5, 10, 50, 100, 500, 1000};

int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int n;
    fin >> n;

    for (int i = 1; i <= n; i++) {
	for (int j = 0, temp = i; temp != 0; j++) {
             // If there are more than three of the current letter.
	    if (temp % mult[j] > 3) {
		count[j]++;
                // Checks if it can have a two letter difference
		// (ie. IX instead of IV).
	        if (temp / mult[j] > 0 && i % vals[j + 2] > vals[j + 1]) {
	            count[j + 2]++;
     	            temp -= mult[j];
                } else
		    count[j + 1]++;
	    } else
		count[j] += temp % mult[j];
	    temp /= mult[j];
	}
    }
    for (int i = 0; i < 7; i++)
     if (count[i])
         fout << roman[i] << " " << count[i] << endl;
    return 0;
}
