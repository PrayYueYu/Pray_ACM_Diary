#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
	int t = atoi(argv[1]);
    int T = 0;           // ื้สý
    //int t=4, T;
    if(t == 1) {
    	T = 1;
    	cout << T << '\n';
    	cout << 21 << '\n';
    	return 0;
	}
	if(t == 2) {
		T = 2;
		cout << T << '\n';
		cout << "1152921504606846975\n1\n";
		return 0;
	}
	if(t == 3) {
		T = 18;
		cout << T << '\n';
		cout << "10\n21\n42\n85\n170\n341\n682\n1365\n2730\n5461\n10922\n";
		cout << "21845\n43690\n87381\n174762\n349525\n699050\n1398101\n";
		return 0;
	}
	if(t == 4) {
		T = 19;
		cout << T << '\n';
		cout << "1\n3\n7\n15\n31\n63\n127\n255\n511\n1023\n2047\n";
		cout << "4095\n8191\n16383\n32767\n65535\n131071\n262143\n";
		cout << "274877906943\n";
		return 0;
	}
	if(t >= 5 && t <= 9) T = 100;
	if(t >= 10) T = 1000;
    cout << T << '\n';                          
    for (int i = 0; i < T; ++i) {                 
        int64_t h = rnd.next(1LL, (1LL << 60) - 1);
		std::cout << h << '\n';
    }
    return 0;
}

