#include<bits/stdc++.h>
#define int long long
using namespace std;
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
struct S {
	int x, y, d;
} s[500];
int read() {
	int x;
	std::cin >> x;
	return x;
}
int vis[500], to[500], n;
void solve() {
	n = read();
	for(int i = 1; i <= n; i++) {
		int x = read(), y = read(), d = read();
		s[i].x = x, s[i].y = y, s[i].d = d;
		vis[i] = false;
		to[i] = -1;
	}
	int n1 = 0, n2 = 0, m = 0;
	for(int i = 1; i <= n; i++) {
		int flag = true;
		for(int j = 1; j <= n; j++) {
			if(s[i].d == s[j].d) {
				if(!s[i].d) {
					if(s[i].x == s[j].x && s[i].y < s[j].y) {
						flag = false;
						break;
					}
				}
				else if(s[i].d == 2) {
					if(s[i].x == s[j].x && s[i].y > s[j].y) {
						flag = false;
						break;
					}
				}
				else if(s[i].d == 1) {
					if(s[i].y == s[j].y && s[i].x < s[j].x) {
						flag = false;
						break;
					}
				}
				else {
					if(s[i].y == s[j].y && s[i].x > s[j].x) {
						flag = false;
						break;
					}
				}
			}
		}
		if(!flag) {
			vis[i] = true;
			continue;
		}
		if(s[i].d % 2 == 0) to[i] = n1++;
		else to[i] = n2++;
	}
    BipartiteGraph gr(n1 + 3, n2 + 3);//注意这里是0-base
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		if(s[i].d % 2 != 0) continue;
		for(int j = 1; j <= n; j++) {
			if(vis[j]) continue;
			if((s[i].d % 2) == (s[j].d % 2)) continue;
			if(s[i].d == 0 && s[j].d == 1) {
				if(s[j].x <= s[i].x && s[j].y >= s[i].y) {
					gr.add_edge(to[i], to[j]);
					m++;
				}
			}
			if(s[i].d == 0 && s[j].d == 3) {
				if(s[j].x >= s[i].x && s[j].y >= s[i].y) {
					gr.add_edge(to[i], to[j]);
					m++;
				}
			}
			if(s[i].d == 2 && s[j].d == 1) {
				if(s[j].x <= s[i].x && s[j].y <= s[i].y) {
					gr.add_edge(to[i], to[j]);
					m++;
				}
			}
			if(s[i].d == 2 && s[j].d == 3) {
				if(s[j].x >= s[i].x && s[j].y <= s[i].y) {
					gr.add_edge(to[i], to[j]);
					m++;
				}
			}
		}
	}
    auto res = gr.hopcroft_karp_maximum_matching();
    std::cout << n1 + n2 - res.size() << '\n';//最大匹配数
}
signed main() {
    int T = read();
    while(T--) {
    	solve();
//    	init();
	}
    return 0;
}
