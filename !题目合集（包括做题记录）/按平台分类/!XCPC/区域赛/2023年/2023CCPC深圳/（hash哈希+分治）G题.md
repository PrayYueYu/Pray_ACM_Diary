# 基因相似序列

## Link

[基因相似序列](https://cpc.csgrandeur.cn/csgoj/problemset/problem?pid=1243)

## Description

**【题目背景】**

生物的遗传物质存在个体间或种群水平的差异，这样的差异被称为遗传变异。突变及基因重组等因素都会导致遗传变异。尽管亲代在将其遗传信息传递给子代时会发生遗传变异，但是这些遗传变异仅占遗传物质的一小部分，通常亲代和子代之间的遗传物质非常相似。遗传变异会在生物繁殖的过程中不断累积。通过比较不同生物的基因特征及基因组结构，可以大致确定生物之间的亲缘关系，并建立系统进化树。在比较过程中，可能有一些遗传物质的子序列完全相同或相似，我们称这种序列为保守序列。

假设现在已经测定了若干以 DNA 为遗传物质的生物的 DNA 碱基序列，希望通过比较这些基序列推测生物之间的亲缘关系。为了简化比较，先将碱基序列划分为若干个保守序列片段。考虑到 DNA 序列可能发生缺失、插入等影响片段数量的遗传变异，将划分得到的片段对齐至 M 个片段，并使用小写字母来表示对齐后的每一个片段。

**【题目描述】**

已知一棵包含了 N 个生物的系统进化树，这些生物的 DNA 序列对应的对齐至 M 个片段的序列可以用仅含小写字母的字符串表示为 s1,…,sN。在这棵系统进化树上，如果两个生物对应的序列最多只有 K 处对应位置上的片段不相同（即对应字母不同），就称这两个生物的亲缘关系相近。

现有 Q 个尚未确定亲缘关系的生物，对齐得到序列分别为 t1,…,tQ。为了确定这些生物在系统进化树上的位置，请对 Q 个生物分别求出，原树中有多少个生物与其亲缘关系相近。

## Input

输入的第一行包含四个正整数 N,Q,M,K，分别表示系统进化树上的生物数量、待确定亲缘关系的生物数量、对齐后的序列长度和比较序列时容许的最大差异数。保证 1≤N,Q≤300，1≤M≤60,000，1≤K≤10。

接下来 N 行，每行输入一个长度恰好为 M，仅包含小写字母的字符串 si，表示系统进化树上的每个生物对应的模板序列。

接下来 Q 行，每行输入一个长度恰好为 M，仅包含小写字母的字符串 tj，表示待确定亲缘关系的每个生物对应的查询序列。

保证输入的两个字符串均仅包含小写字母。

## Output

输出共 Q 行，其中第 j 行输出一个非负整数，表示在系统进化树上与第 j 个待确定的生物亲缘关系相近的生物数量。

## Solution

暴力时间复杂度为$O(N*M*Q)$一定会TLE

那么考虑别的算法，是否能用$Hash$呢？

考虑到$k$比较小，用$Hash+$分治可以大幅度优化时间复杂度

首先要简单筛掉一定不符合条件的，判断每个字母数量差的绝对值的和，如果大于$k$则一定不行（防止全是不匹配的，有可能会被卡，最坏情况一次分治时间复杂度为$O(2*M)$，筛掉不符合的情况能优化，当然也不一定卡这个）

## Code

```c++
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 3e2+10, M = 1e9 + 7, Px = 1331;
int n, m, q, k, nowd, nums[N][50], numt[50];
string s[N];
ll ha[N][60010], P[60010];
ll read() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

ll Hash(int t, int l, int r) {
	ll ans = 0;
	ans =  (ha[t][l - 1] * P[r - l + 1]) % M;
	ans = (ha[t][r] - ans + M) % M;
	return ans;
} //求Hash值

void Ask(int x, int l, int r) { //分治：区间判断
	if(nowd > k) return; //优化：一定不满足则直接退出
	ll hx = Hash(x, l, r); 
	ll hy = Hash(0, l, r);
	if(hx == hy) return; //相等则直接返回
	if(l == r) { 
		if(hx != hy) nowd++; //找到不同的那一个，nowd+1
		return;
	}
	int mid = (l + r) >> 1;
	int sum = 0;
	ll hx1 = Hash(x, l, mid);
	ll hx2 = Hash(x, mid + 1, r);
	ll hy1 = Hash(0, l, mid);
	ll hy2 = Hash(0, mid + 1, r);
    //区间判断，相同则不需要继续搜索
	if(hx1 != hy1) Ask(x, l, mid); 
	if(hx2 != hy2) Ask(x, mid + 1, r);
	return;
}

int main() {
	n = read(), q = read(), m = read(), k = read();
	P[0] = 1;
	for(int i = 1; i <= m + 2; i++) {
		P[i] = P[i - 1] * Px;
		P[i] %= M;
	}
	for(int i = 1; i <= n; i++) {
		getline(cin, s[i]);
		for(int j = 0; j < m; j++){
			nums[i][s[i][j] - 'a']++;
            //hash
			if(!j) ha[i][j] = s[i][j] - 'a';
			else ha[i][j] = (ha[i][j - 1] * Px + s[i][j] - 'a') % M;
		}
	}
	for(int i = 1; i <= q; i++) {
		string t; getline(cin, t);
		int ans = 0; 
		//ha[0][x]表示字符串t的hash
		for(int j = 0; j <= 'z' - 'a'; j++) numt[j] = 0;
		for(int j = 0 ; j < m; j++) {
			numt[t[j] - 'a']++;
			if(!j) ha[0][j] = t[j] - 'a';
			else ha[0][j] = (ha[0][j - 1] * Px + t[j] - 'a') % M;
		}
		for(int j = 1; j <= n; j++) {
			int num = 0; nowd = 0;
			for(int p = 0; p <= 'z' - 'a'; p++) {
				num += abs(numt[p] - nums[j][p]);
			}
			if(num > 2 * k) continue; //如果一定不行则不管
			Ask(j, 0, m - 1);
			if(nowd <= k) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
```

