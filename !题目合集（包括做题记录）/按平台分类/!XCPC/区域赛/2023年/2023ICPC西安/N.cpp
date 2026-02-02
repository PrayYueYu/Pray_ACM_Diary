#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e6 + 100;
string s, s1, s2, s3;
char sx;
int to[N];
int read() {
	int x;
	scanf("%lld", &x);
	return x;
}
int calc(int l, int r, int d, int x, int t) {
	if(l > r && d > 0) return 0;
	if(l < r && d < 0) return 0;
	int fi = l, dx = d;
	if(l > r) {
		swap(l, r);
		d = -d;
	}
	int len = r - l;
	if(len % d == 0) len = len / d;
	else len = len / d + 1;
	
	if(t == 1) return len * x;
	int la = (fi + dx * (len - 1));
	int sum = ((fi + la) * len) / 2;
	return sum;
}
signed main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	getline(cin, s);
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	cin >> s;
	to[s1[4]] = 1;
	to[s2[4]] = 2;
	char ad = s[5];
	int l = 0, r = 0, d = 0, f = 0;
	int f1 = 1, f2 = 1, f3 = 1;
	for(int i = 0; i < s1.size(); i++) {
		if(s1[i] >= '0' && s1[i] <= '9') {
			if(!f) {
				l = l * 10 + s1[i] - '0';
			}
			else if(f == 1){
				r = r * 10 + s1[i] - '0';
			}
			else d = d * 10 + s1[i] - '0'; 
		}
		if(s1[i] == '-') {
			if(f == 0) f1 = -1;
			if(f == 1) f2 = -1;
			if(f == 2) f3 = -1;
		}
		if(s1[i] == ',') f++;
	}
	if(!d && f == 1) {
		d = 1;
	}
	int ans = 0;
	l *= f1, r *= f2, d *= f3;
	if(d > 0) {
		for(int i = l; i < r; i += d) {
			int a = 0, b = 0, c = 0;
			f = 0;
			int fx = false;
			f1 = f2 = f3 = 1;
			for(int j = 0; j < s2.size(); j++) {
				if(s2[j] >= '0' && s2[j] <= '9') {
					if(!f) {
						a = a * 10 + s2[j] - '0';
					}
					else if(f == 1) {
						b = b * 10 + s2[j] - '0';
					}
					else {
						c = c * 10 + s2[j] - '0';
						fx = true;
					}
				}
				if(s2[j] == '-') {
					if(f == 0) f1 = -1;
					if(f == 1) f2 = -1;
					if(f == 2) f3 = -1;
				}
				if(s2[j] == ',') f++;
			}
			if(!a) a = i;
			if(!b) b = i;
			if(!c && f == 1) c = 1;
			if(!c && f == 2 && !fx) c = i;
			if(!c && f == 2 && fx) c = 0;
			a *= f1, b *= f2, c *= f3;
			if(to[ad] == 1) {
				ans += calc(a, b, c, i, 1);
				continue;
			}
			else ans += calc(a, b, c, 0, 2);
		}
	}
	else {
		for(int i = l; i > r; i += d) {
			int a = 0, b = 0, c = 0;
			f = 0;
			int fx = false;
			f1 = f2 = f3 = 1;
			for(int j = 0; j < s2.size(); j++) {
				if(s2[j] >= '0' && s2[j] <= '9') {
					if(!f) {
						a = a * 10 + s2[j] - '0';
					}
					else if(f == 1) {
						b = b * 10 + s2[j] - '0';
					}
					else {
						c = c * 10 + s2[j] - '0';
						fx = true;
					}
				}
				if(s2[j] == '-') {
					if(f == 0) f1 = -1;
					if(f == 1) f2 = -1;
					if(f == 2) f3 = -1;
				}
				if(s2[j] == ',') f++;
			}
			if(!a) a = i;
			if(!b) b = i;
			if(!c && f == 1) c = 1;
			if(!c && f == 2 && !fx) c = i;
			if(!c && f == 2 && fx) c = 0;
			a *= f1, b *= f2, c *= f3;
			if(to[ad] == 1) {
				ans += calc(a, b, c, i, 1);
				continue;
			}
			else ans += calc(a, b, c, 0, 2);
		}		
	}
	cout << ans;
	return 0;
} 
/*
*/
