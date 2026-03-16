#include<bits/stdc++.h>
#define int long long
void solve() {
	
}
signed main() {
	int H, h1, h2;
	std::cin >> H >> h1 >> h2;
	std::cout << H << '\n';
	if(H < h1) std::cout << "Bu Kan";
	else if(H < h2) std::cout << "Zhe Gua Bao Shu Ma";
	else std::cout << "Chi Gua";
	return 0;
} 
