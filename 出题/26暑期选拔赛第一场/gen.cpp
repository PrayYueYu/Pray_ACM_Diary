#include <bits/stdc++.h>
#include <getopt.h>
using namespace std;

long long total_cells = 0;   // 全局累计已生成的格子数

// ---------- 生成有解地图 ----------
void generate_yes_case(int n, int m, vector<string>& now, vector<string>& past,
                       mt19937& rng, double extra_empty_prob = 0.25) {
    now.assign(n, string(m, '#'));
    past.assign(n, string(m, '#'));

    // 起点终点强制空地
    now[0][0] = past[0][0] = '.';
    now[n-1][m-1] = past[n-1][m-1] = '.';

    // 构造只向右/下的单调路径
    vector<pair<int,int>> path;
    path.emplace_back(0, 0);
    int x = 0, y = 0;
    while (x < n-1 || y < m-1) {
        if (x == n-1) ++y;
        else if (y == m-1) ++x;
        else {
            if (rng() % 2 == 0) ++y;
            else ++x;
        }
        path.emplace_back(x, y);
    }

    // 按步数奇偶性分别标记到“现在”或“过去”层
    for (int i = 0; i < (int)path.size(); ++i) {
        int r = path[i].first, c = path[i].second;
        if (i % 2 == 0) now[r][c] = '.';
        else past[r][c] = '.';
    }

    // 随机额外空地
    uniform_real_distribution<double> prob(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (now[i][j] == '#' && prob(rng) < extra_empty_prob)
                now[i][j] = '.';
            if (past[i][j] == '#' && prob(rng) < extra_empty_prob)
                past[i][j] = '.';
        }
    }
    // 再次确保起点终点为空（防止随机覆盖）
    now[0][0] = past[0][0] = '.';
    now[n-1][m-1] = past[n-1][m-1] = '.';
}

// ---------- 生成随机（大概率无解）地图 ----------
void generate_random_case(int n, int m, vector<string>& now, vector<string>& past,
                          mt19937& rng, double empty_prob = 0.25) {
    now.assign(n, string(m, '#'));
    past.assign(n, string(m, '#'));
    uniform_real_distribution<double> prob(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (prob(rng) < empty_prob) now[i][j] = '.';
            if (prob(rng) < empty_prob) past[i][j] = '.';
        }
    }
    now[0][0] = past[0][0] = '.';
    now[n-1][m-1] = past[n-1][m-1] = '.';
}

// ---------- 输出一组数据 ----------
void print_case(int n, int m, const vector<string>& now, const vector<string>& past) {
    cout << n << ' ' << m << '\n';
    for (const auto& row : now) cout << row << '\n';
    for (const auto& row : past) cout << row << '\n';
}

// ---------- 主函数 ----------
int main(int argc, char* argv[]) {
	for(int tt = 1; tt <= 20; tt++) {
		total_cells = 0; 
		std::string s = std::to_string(tt) + ".in";
		freopen(s.c_str(), "w", stdout);
	    // 默认参数
	    int min_n = 1, max_n = 20;
	    int min_m = 1, max_m = 20;
	    int maxnm = -1;          // -1 表示未设置，不额外限制
	    int limitT = 0;          // 0 表示无限制
	    int T = -1;              // 最终组数（初始 -1，之后赋值）
	    int seed = (int)chrono::steady_clock::now().time_since_epoch().count();
	    string type = "mixed";
	
	    // 命令行参数解析
	    static struct option long_options[] = {
	        {"min_n",  required_argument, 0, 'a'},
	        {"max_n",  required_argument, 0, 'b'},
	        {"min_m",  required_argument, 0, 'c'},
	        {"max_m",  required_argument, 0, 'd'},
	        {"maxnm",  required_argument, 0, 'e'},
	        {"limitT", required_argument, 0, 'f'},
	        {"seed",   required_argument, 0, 's'},
	        {"type",   required_argument, 0, 't'},
	        {0, 0, 0, 0}
	    };
	    int opt;
	    while ((opt = getopt_long(argc, argv, "a:b:c:d:e:f:s:t:", long_options, nullptr)) != -1) {
	        switch (opt) {
	            case 'a': min_n = stoi(optarg); break;
	            case 'b': max_n = stoi(optarg); break;
	            case 'c': min_m = stoi(optarg); break;
	            case 'd': max_m = stoi(optarg); break;
	            case 'e': maxnm = stoi(optarg); break;
	            case 'f': limitT = stoi(optarg); break;
	            case 's': seed = stoi(optarg); break;
	            case 't': type = optarg; break;
	            default:
	                cerr << "Usage: " << argv[0] << " [options]\n"
	                     << "  --min_n, --max_n   : range of n (default 5 20)\n"
	                     << "  --min_m, --max_m   : range of m (default 5 20)\n"
	                     << "  --maxnm            : global max for both n and m (optional, default -1 means no extra limit)\n"
	                     << "  --limitT           : max number of test cases (0 = unlimited, default 0)\n"
	                     << "  --seed             : random seed (default time)\n"
	                     << "  --type             : yes / no / mixed (default mixed)\n";
	                return 1;
	        }
	    }
	
	    // 应用 maxnm 限制（仅当 >0 时）
	    if (maxnm > 0) {
	        max_n = min(max_n, maxnm);
	        max_m = min(max_m, maxnm);
	        if (min_n > max_n) min_n = max_n;
	        if (min_m > max_m) min_m = max_m;
	    }
	
	    // 确保范围合法
	    if (min_n > max_n) swap(min_n, max_n);
	    if (min_m > max_m) swap(min_m, max_m);
	    if (min_n < 1) min_n = 1;
	    if (min_m < 1) min_m = 1;
	
	    // 若最小尺寸乘积 > 1e6，无法生成任何合法数据
	    if (1LL * min_n * min_m > 1000000) {
	        cerr << "Error: minimum cell product (" << min_n << "*" << min_m << "=" 
	             << 1LL*min_n*min_m << ") exceeds 1e6 limit. Please reduce ranges.\n";
	        return 1;
	    }
	
	    mt19937 rng(seed);
	    uniform_int_distribution<int> dist_n(min_n, max_n);
	    uniform_int_distribution<int> dist_m(min_m, max_m);
	
	    // 估算平均格子数
	    double avg_n = (min_n + max_n) / 2.0;
	    double avg_m = (min_m + max_m) / 2.0;
	    double avg_cells = avg_n * avg_m;
	    if (avg_cells < 1) avg_cells = 1;
	
	    // 计算最大可能组数（留 5% 余量）
	    int est = (int)(0.95 * 1000000 / avg_cells);
	    if (est < 1) est = 1;
	    if (limitT > 0) est = min(est, limitT);
	
	    // 生成尺寸列表
	    vector<pair<int,int>> dims;
	    long long sum = 0;
	    for (int i = 0; i < est; ++i) {
	        int n = dist_n(rng);
	        int m = dist_m(rng);
	        dims.emplace_back(n, m);
	        sum += 1LL * n * m;
	    }
	
	    // 若超出 1e6，从末尾删除直到满足
	    while (sum > 1000000 && !dims.empty()) {
	        sum -= 1LL * dims.back().first * dims.back().second;
	        dims.pop_back();
	    }
	
	    // 如果 dims 为空（极端情况），强行生成一组最小尺寸
	    if (dims.empty()) {
	        dims.emplace_back(min_n, min_m);
	        sum = 1LL * min_n * min_m;
	    }
	
	    // 赋值 T（不再重新声明）
	    T = (int)dims.size();
	
	    // 输出统计信息到 stderr
	    cerr << "Generating " << T << " cases with n in [" << min_n << "," << max_n
	         << "], m in [" << min_m << "," << max_m << "], type=" << type
	         << ", total cells=" << sum << "\n";
	
	    // 输出总组数
	    cout << T << '\n';
	
	    int yes_count = 0, no_count = 0;
	    uniform_real_distribution<double> type_prob(0.0, 1.0);
	
	    for (int i = 0; i < T; ++i) {
	        int n = dims[i].first;
	        int m = dims[i].second;
	        vector<string> now, past;
	
	        bool is_yes;
	        if (type == "yes") is_yes = true;
	        else if (type == "no") is_yes = false;
	        else { // mixed: 每个独立随机
	            is_yes = (type_prob(rng) < 0.5);
	        }
	
	        if (is_yes) {
	            generate_yes_case(n, m, now, past, rng);
	            ++yes_count;
	        } else {
	            generate_random_case(n, m, now, past, rng);
	            ++no_count;
	        }
	        print_case(n, m, now, past);
	        total_cells += 1LL * n * m;
	    }
	
	    // 最终统计
	    cerr << "YES=" << yes_count << ", NO=" << no_count
	         << ", total cells=" << total_cells << "\n";
	}

    return 0;
}
