// ======================================================================
// 洛谷 P3916  图的遍历
// 难度: 普及    (题单顺序 6/69)
// 题目: https://www.luogu.com.cn/problem/P3916
// 记录: https://www.luogu.com.cn/record/281309275
// 结果: Accepted · 100 分 · 224 ms · 5120 KB · 提交于 2026-06-09 19:27
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 给出 $N$ 个点，$M$ 条边的有向图，对于每个点 $v$，令 $A(v)$ 表示从点 $v$ 出发，能到达的编号最大的点。现在请求出 $A(1),A(2),\dots,A(N)$ 的值。
//
// 【输入格式】
// 第 $1$ 行 $2$ 个整数 $N,M$，表示点数和边数。
// 
// 接下来 $M$ 行，每行 $2$ 个整数 $U_i,V_i$，表示边 $(U_i,V_i)$。点用 $1,2,\dots,N$ 编号。
//
// 【输出格式】
// 一行 $N$ 个整数 $A(1),A(2),\dots,A(N)$。
//
// 【样例 #1】
// 输入:
// 4 3
// 1 2
// 2 4
// 4 3
// 输出:
// 4 4 3 4
//
// 【提示】
// - 对于 $60\%$ 的数据，$1 \leq N,M \leq 10^3$。
// - 对于 $100\%$ 的数据，$1 \leq N,M \leq 10^5$。
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

int n, m;

int dot[100010];
vector<int> g[100010];

void dfs(int n,int maxd) {
    if (dot[n])return;
    dot[n] = maxd;
    for (int i = 0; i < g[n].size(); i++)
    {
        dfs(g[n][i], maxd);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        g[end].push_back(start);
    }
    for (int i = n; i > 0; i--)
    {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dot[i] << ' ';
    }
    return 0;
}
