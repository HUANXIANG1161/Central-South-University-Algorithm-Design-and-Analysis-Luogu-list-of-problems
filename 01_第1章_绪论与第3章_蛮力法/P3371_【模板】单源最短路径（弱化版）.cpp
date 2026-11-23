// ======================================================================
// 洛谷 P3371  【模板】单源最短路径（弱化版）
// 难度: 普及    (题单顺序 7/69)
// 题目: https://www.luogu.com.cn/problem/P3371
// 记录: https://www.luogu.com.cn/record/281317735
// 结果: 未通过 · 70 分 · 3786 ms · 7060 KB · 提交于 2026-06-09 20:26
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目背景】
// 本题测试数据为随机数据，在考试中可能会出现构造数据让 SPFA 不通过，如有需要请移步 [P4779](https://www.luogu.com.cn/problem/P4779)。
//
// 【题目描述】
// 如题，给出一个有向图，请输出从某一点出发到所有点的最短路径长度。
//
// 【输入格式】
// 第一行包含三个整数 $n,m,s$，分别表示点的个数、有向边的个数、出发点的编号。
// 
// 接下来 $m$ 行每行包含三个整数 $u,v,w$，表示一条 $u \to v$ 的，长度为 $w$ 的边。
//
// 【输出格式】
// 输出一行 $n$ 个整数，第 $i$ 个表示 $s$ 到第 $i$ 个点的最短路径，若不能到达则输出 $2^{31}-1$。
//
// 【样例 #1】
// 输入:
// 4 6 1
// 1 2 2
// 2 3 2
// 2 4 1
// 1 3 5
// 3 4 3
// 1 4 4
// 输出:
// 0 2 4 3
//
// 【提示】
// 【数据范围】
// 对于 $20\%$ 的数据：$1\le n \le 5$，$1\le m \le 15$；
// 对于 $40\%$ 的数据：$1\le n \le 100$，$1\le m \le 10^4$；
// 对于 $70\%$ 的数据：$1\le n \le 1000$，$1\le m \le 10^5$；
// 对于 $100\%$ 的数据：$1 \le n \le 10^4$，$1\le m \le 5\times 10^5$，$1\le u,v\le n$，$w\ge 0$，$\sum w< 2^{31}$，保证数据随机。
// 
// **Update 2022/07/29：两个点之间可能有多条边，敬请注意。**
// 
// 对于真正 $100\%$ 的数据，请移步 [P4779](https://www.luogu.com.cn/problem/P4779)。请注意，该题与本题数据范围略有不同。
// 
// 
// 样例说明：
// 
// ![](https://cdn.luogu.com.cn/upload/pic/7641.png)
// 
// 图片 1 到 3 和 1 到 4 的文字位置调换
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
int n, m, s;
int dot[MAXN];
vector<pair<int, int>> g[MAXN]; // pair<权值w, 节点v>

inline void dfs(int x, int val) {
    dot[x] = val;
    for (auto &e : g[x]) {
        int w = e.first;
        int v = e.second;
        if (val + w < dot[v]) {
            dfs(v, val + w);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(w, v); // 权值在前，方便排序
    }
    
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    
    for (int i = 1; i <= n; i++) {
        dot[i] = INT_MAX;
    }

    dfs(s, 0);

    for (int i = 1; i <= n; i++) {
        cout << dot[i] << ' ';
    }

    return 0;
}
