#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5;
int n;
char s[N][N];
int read() {
	int x;
	cin >> x;
	return x;
}
string a[N], b[N], sb[N], sa[N];
map<string, int> mp1, mp2;
signed main() {
	n = read();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> s[i][j];
			a[i] += s[i][j];
			b[j] += s[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		mp1[a[i]]++;
		mp2[b[i]]++;
		sa[i] = a[i];
		sb[i] = b[i];
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 'L') sa[i][j] = 'R';
			else sa[i][j] = 'L';
			if(b[i][j] == 'L') sb[i][j] = 'R';
			else sb[i][j] = 'L';
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] == 'L') a[i][j] = 'R';
			else a[i][j] = 'L';
			if(sa[i][j] == 'L') sa[i][j] = 'R';
			else sa[i][j] = 'L';
			if(b[j][i] == 'L') b[j][i] = 'R';
			else b[j][i] = 'L';
			if(sb[j][i] == 'L') sb[j][i] = 'R';
			else sb[j][i] = 'L';
//			if(i == 0 && j == 0) {
//				cout << a[i] << " " << sa[i] << '\n';
//				cout << b[j] << ' ' << sb[j] << '\n';
//			}
			if(mp1[a[i]] + mp1[sa[i]] == n - 1) {
				if(mp2[b[j]] + mp2[sb[j]] == n - 1) {
					cout << i + 1 << " " << j + 1;
					return 0;
				}
			}
			
			if(a[i][j] == 'L') a[i][j] = 'R';
			else a[i][j] = 'L';
			if(sa[i][j] == 'L') sa[i][j] = 'R';
			else sa[i][j] = 'L';
			if(b[j][i] == 'L') b[j][i] = 'R';
			else b[j][i] = 'L';
			if(sb[j][i] == 'L') sb[j][i] = 'R';
			else sb[j][i] = 'L';
		}
	}
	cout << -1;
	return 0;
}
/*
5
RLRLR
LRLLL
LRLLL
LRLLL
RLRRR
*/
