#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e6 + 10, INF = 1e13 + 7, M = 1e15;
ll sx, sy, tx, ty, ans[N], las[N];
char cans[100] = {' ', 'W', 'S', 'A', 'D'};
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
//ÉÏÏÂ×óÓÒ£º1234 

int main() {
	//freopen("1.in", "r", stdin);
	int T = read();
	while(T--) {
		sx = read(), sy = read();
		tx = read(), ty = read();
		ll x = read(), y = read();
		ll tox = tx, toy = ty, yx = y;
		ll num1 = 0, num2 = 0;
		ll checkx = sx, checky = sy, checkd = x;
		while(true) {
			if(yx % 2 == 0) {
				las[++num2] = 1;
				toy--;
				yx /= 2;
			}
			else {
				las[++num2] = 4;
				tox--;
				yx--;
			}
			if(!yx) break;
		}
		ll nowx = sx, nowy = sy, nowd = x;
		while(true) {
			if(nowd) {
				ans[++num1] = 2;
				nowy--;
				nowd /= 2;
			}
			else break;
		}
		while(true) {
			if(nowy < toy + 50 && nowy < 3e3) {
				ans[++num1] = 1;
				nowy++;
			}
			else break;
		}
		while(true) {
			if(nowx < tox) {
				ans[++num1] = 4;
				nowx++;
			}
			else if(nowx > tox) {
				ans[++num1] = 3;
				nowx--;
			}
			else break;
		}
		
		while(true) {
			if(nowy > toy) {
				ans[++num1] = 2;
				nowy--;
			}
			else break;
		}//cout << num1 + num2 << endl;
		ll F = true;
		for(int i = 1; i <= num1; i++) {
			cout << cans[ans[i]];
			if(ans[i] == 1) checky++, checkd *= 2;
			if(ans[i] == 2) checky--, checkd /= 2;
			if(ans[i] == 3) checkx--, checkd--;
			if(ans[i] == 4) checkx++, checkd++;
			if(checkx < -1000 || checkx > 3e3) F = -1;
			if(checky < -1000 || checky > 3e3) F = -2;
			if(checkd > 1e9) F = -3;
		}
	//	cout << checkd << " ";
		for(int i = num2; i >= 1; i--) {
			cout << cans[las[i]];
			if(las[i] == 1) checky++, checkd *= 2;
			if(las[i] == 2) checky--, checkd /= 2;
			if(las[i] == 3) checkx--, checkd--;
			if(las[i] == 4) checkx++, checkd++;
			if(checkx < -1000 || checkx > 3e3) F = -4;
			if(checky < -1000 || checky > 3e3) F = -5;
			if(checkd > 1e9) F = -6;
		}
	//	cout << checkx << " " << checky << " " << checkd;
	//	cout << tx << " " << ty << " " << y << " " << num1 + num2 << endl;
	/*	if(F && checkx == tx && checky == ty && checkd == y && num1 + num2 <= 5e3) {
			cout << "Yes";
		}
		else cout << "No " << F;*/
		cout << endl;
	}
	return 0;
}
/*

*/
