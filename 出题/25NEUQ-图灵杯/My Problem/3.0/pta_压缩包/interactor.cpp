#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
const int N = 1e5 + 100;
long long h[N];
long long gcd(long long a, long long b) {
    while(b) {
		long long t = a % b;
		a = b;
		b = t;
	}
    return a;
}

int main(int argc, char* argv[]) {
	registerInteraction(argc, argv);
	int T = inf.readInt(1, 1000, "T");
	inf.readEoln();
	ofstream oufx(argv[1]);
	if(T == 2) {
		oufx << "\n? 2 2\n\n";
		oufx << "? 3 2\n\n";
		oufx << "! 520\n\n";
		oufx << "? 2 1\n\n";
		oufx << "? 10 6\n\n";
		oufx << "? 7 2\n\n";
		oufx << "! 1314";
		cout << T << '\n';
		cout.flush();
		return 0;
	}
	long long Max = (1ll << 60) - 1ll;
    long long p61 = 1ll << 61ll;
	for(int i = 1; i <= T; i++) {
		h[i] = inf.readLong(1, Max, "h");
		inf.readEoln();
	}
	inf.readEof();
	cout << T << '\n';
	cout.flush();
	int F = 0;
	for(int i = 1; i <= T; i++) {
		long long qMax = (__lg(h[i])) + 4;
		bool found = false;
		while(true) {
			qMax--;
			string Line = ouf.readToken();
			if(Line == "?") {
				long long a = ouf.readLong();
				long long b = ouf.readLong();
				long long g = 0;
				if(a <= 0 || b <= 0 || a >= p61 || b >= p61) {
					if(!F) F = -3;
					g = Max + 1ll;
				}
				else g = gcd(a, h[i] + b);
				cout << g << '\n';
				cout.flush();
			}
			else if(Line == "!"){
				long long a = ouf.readLong();
				if(a <= 0 || a >= p61) {
					if(!F) F = -3;
				}
				if(qMax >= 0 && a == h[i]) {
					found = true;
				}
				else if(qMax < 0 && a == h[i]) {
					if(!F) F = -4;
				}
				else if(!F) F = -2;
				break;
			}
			else {
				quitf(_wa, "Error");
			}
		}
	}
	if(F == -2) quitf(_wa, "h is incorrect");
	else if(F == -3) quitf(_wa, "The number exceeds the range");
	else if(F == -4) quitf(_wa, "Too many inquiries");
	else quitf(_ok, "Found all Heart");
	return 0; 
}

