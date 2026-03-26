#include<bits/stdc++.h>
#define int long long
const int N = 2e6 + 10, mod = 998244353, INF = 1e18;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void solve() {
	int n = read();
	for(int i = 1; i <= n; i++) {
		std::string s;
		getline(std::cin, s);
		int f1 = 0, f2 = 0;
		for(int j = 0; j < s.size(); j++) {
			if(s[j] == ',') {
				if(s[j - 3] == 'o' && s[j - 2] == 'n' && s[j - 1] == 'g')  f1 = true;
			}
			if(s[j] == '.') {
				if(s[j - 3] == 'o' && s[j - 2] == 'n' && s[j - 1] == 'g')  f2 = true;
			}
		}
		if(f1 * f2) {
			std::string sx = "";
			int cnt = 0;
			for(int j = s.size() - 1; j >= 0; j--) {
				if(s[j] == ' ') {
					cnt++;
					sx += " ";
					continue;
				}
				if(cnt >= 3) sx += s[j];
				else continue;
			}
			reverse(sx.begin(), sx.end());
			for(int j = 0; j < sx.size() - 2; j++) std::cout << sx[j];
			std::cout << "qiao ben zhong.\n";
		}
		else std::cout << "Skipped\n";
	}
}
signed main() {
	int T = 1; 
	while(T--) {
		solve();
//		init();
	}
	return 0;
}
/*
5
xun zhang zhai ju lao diao chong, xiao yue dang lian gua yu gong.
tian sheng wo cai bi you yong, qian jin san jin huan fu lai.
xue zhui rou zhi leng wei rong, an xiao chen jing shu wei long.
zuo ye xing chen zuo ye feng, hua lou xi pan gui tang dong.
ren xian gui hua luo, ye jing chun shan kong.
*/
