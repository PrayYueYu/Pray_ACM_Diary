#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
int maxL[N], maxR[N], a[N][N], visL[N], visR[N];
struct BipartiteGraph {
    int n1, n2;                       // number of vertices in X and Y, resp.
    std::vector<std::vector<int>> g;  // edges from X to Y
    std::vector<int> ma, mb;  // matches from X to Y and from Y to X, resp.
    std::vector<int> dist;    // distance from unsaturated vertices in X.

    BipartiteGraph(int n1, int n2)
      : n1(n1), n2(n2), g(n1), ma(n1, -1), mb(n2, -1) {}

    // Add an edge from u in X to v in Y.
    void add_edge(int u, int v) { g[u].emplace_back(v); }

    // Build the level graph.
    bool bfs() {
    dist.assign(n1, -1);
    std::queue<int> q;
    for (int u = 0; u < n1; ++u) {
      if (ma[u] == -1) {
        dist[u] = 0;
        q.emplace(u);
      }
    }
    // Build the level graph for all reachable vertices.
    bool succ = false;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (mb[v] == -1) {
          succ = true;
        } else if (dist[mb[v]] == -1) {
          dist[mb[v]] = dist[u] + 1;
          q.emplace(mb[v]);
        }
      }
    }
    return succ;
    }

    // Find an augmenting path starting at u.
    bool dfs(int u) {
    for (int v : g[u]) {
      if (mb[v] == -1 || (dist[mb[v]] == dist[u] + 1 && dfs(mb[v]))) {
        ma[u] = v;
        mb[v] = u;
        return true;
      }
    }
    dist[u] = -1;  // Mark this point as inreachable after one visit.
    return false;
    }

    // Hopcroft-Karp maximum matching algorithm.
    std::vector<std::pair<int, int>> hopcroft_karp_maximum_matching() {
    // Build the level graph and then find a blocking flow.
    while (bfs()) {
      for (int u = 0; u < n1; ++u) {
        if (ma[u] == -1) {
          dfs(u);
        }
      }
    }
    // Collect the matched pairs.
    std::vector<std::pair<int, int>> matches;
    matches.reserve(n1);
    for (int u = 0; u < n1; ++u) {
      if (ma[u] != -1) {
        matches.emplace_back(u, ma[u]);
      }
    }
    return matches;
    }
};

signed main() {
    int n1, n2, m = 0, sum = 0, num = 0;
    std::cin >> n1 >> n2;
    BipartiteGraph gr(n1 + 3, n2 + 3);//注意这里是0-base
    //左边编号为0~n1-1
    //右边编号为0~n2-1
    //两边一共m条边
    for(int i = 0; i < n1; i++) {
    	for(int j = 0; j < n2; j++) {
    		std::cin >> a[i][j];
    		sum += a[i][j];
    		if(a[i][j]) num++;
    		maxL[i] = std::max(maxL[i], a[i][j]);
    		maxR[j] = std::max(maxR[j], a[i][j]);
		}
	}
	for(int i = 0; i < n1; i++) {
		for(int j = 0; j < n2; j++) {
			if(maxL[i] == maxR[j] && a[i][j]) {
				m++;
				gr.add_edge(i, j);
			}
		}
	}
    auto res = gr.hopcroft_karp_maximum_matching();
    for (int i = 0; i < res.size(); ++i) {
    	num--;
    	visR[res[i].second] = true;
    	visL[res[i].first] = true;
    	sum -= maxL[res[i].first];
    }
    for(int i = 0; i < n1; i++) {
    	if(visL[i]) continue;
    	if(!maxL[i]) continue;
    	num--;
    	sum -= maxL[i];
	}
	for(int j = 0; j < n2; j++) {
		if(visR[j]) continue;
		if(!maxR[j]) continue;
		num--;
		sum -= maxR[j];
	}
	std::cout << sum - num << '\n';
    return 0;
}
