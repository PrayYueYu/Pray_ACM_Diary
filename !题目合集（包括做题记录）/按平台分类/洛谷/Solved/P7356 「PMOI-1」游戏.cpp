#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5;

int read() {
	int x;
	cin >> x;
	return x;
}
int x, y;
void print(int xx, int yy) {
	cout << xx << ' ' << yy << '\n';
	cout.flush();
}
bool check(int xx, int yy) {
	if(xx == x && yy == y) return true;
	return false;
}
void getxy() {
	x = read(), y = read();
}
void solve() {
	print(0, 3);
	getxy();
	if(check(0, 1)) {
		print(0, 4);
		getxy();
		if(check(0, 2)) print(0, 5);
		else print(0, 2);
	}
	else if(check(0, 4)) {
		print(2, 2);
		getxy();
		if(x == y) {
			print(3, 1);
			getxy();
			if(check(1, 3)) print(4, 0);
			else print(1, 3);
		}
		else {
			print(3, 3);
			getxy();
			if(check(1, 1)) print(4, 4);
			else print(1, 1);
		}
	}
	else if(check(0, 2)) {
		print(2, 2);
		getxy();
		if(x == y) {
			print(3, 2);
			getxy();
			if(check(1, 2)) print(4, 2);
			else print(1, 2);
		}
		else {
			print(3, 3);
			getxy();
			if(check(1, 1)) print(4, 4);
			else print(1, 1);
		}
	}
	else {
		print(0, 2);
		getxy();
		if(check(0, 1)) print(0, 4);
		else print(0, 1);
	}
}
signed main() {
	int T = read();
	while(T--) solve();
	return 0;
}
/*

*/
