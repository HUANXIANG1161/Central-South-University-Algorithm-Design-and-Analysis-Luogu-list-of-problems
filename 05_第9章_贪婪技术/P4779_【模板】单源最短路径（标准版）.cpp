// ======================================================================
// 洛谷 P4779  【模板】单源最短路径（标准版）
// 难度: 普及    (题单顺序 61/69)
// 题目: https://www.luogu.com.cn/problem/P4779
// 记录: https://www.luogu.com.cn/record/282031013
// 结果: Accepted · 100 分 · 413 ms · 11920 KB · 提交于 2026-06-16 04:25
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目背景】
// 2018 年 7 月 19 日，某位同学在 [NOI Day 1 T1 归程](https://www.luogu.com.cn/problem/P4768) 一题里非常熟练地使用了一个广为人知的算法求最短路。
// 
// 然后呢？
// 
// $100 \rightarrow 60$；
// 
// $\text{Ag} \rightarrow \text{Cu}$；
// 
// 最终，他因此没能与理想的大学达成契约。
// 
// 小 F 衷心祝愿大家不再重蹈覆辙。
//
// 【题目描述】
// 给定一个 $n$ 个点，$m$ 条有向边的带非负权图，请你计算从 $s$ 出发，到每个点的距离。
// 
// 数据保证你能从 $s$ 出发到任意点。
//
// 【输入格式】
// 第一行为三个正整数 $n, m, s$。
// 第二行起 $m$ 行，每行三个非负整数 $u_i, v_i, w_i$，表示从 $u_i$ 到 $v_i$ 有一条权值为 $w_i$ 的有向边。
//
// 【输出格式】
// 输出一行 $n$ 个空格分隔的非负整数，表示 $s$ 到每个点的距离。
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
// 样例解释请参考 [数据随机的模板题](https://www.luogu.com.cn/problem/P3371)。
// 
// $1 \leq n \leq 10^5$；
// 
// $1 \leq m \leq 2\times 10^5$；
// 
// $s = 1$；
// 
// $1 \leq u_i, v_i\leq n$；
// 
// $0 \leq w_i \leq 10 ^ 9$,
// 
// $0 \leq \sum w_i \leq 10 ^ 9$。
// 
// 本题数据可能会持续更新，但不会重测，望周知。
// 
// 2018.09.04 数据更新 from @zzq
//
// ---------------------------- 代码 ----------------------------

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include <cmath>
#include<cstring>
#include<queue>
#define ll long long
#define INT_MAX 2147483640
#define INF 0x3f3f3f3f3f3f3f



using namespace std;

vector <pair<int, int>> e[200010];
bool visit[100010];
ll dis[100010];
int n,m,s;
priority_queue<pair<ll, int>,vector<pair<ll,int>>,greater<pair<ll,int>>> g;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n>> m>> s;
	for(int i=0;i<m;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({ w, v});
	}

	for (int i = 1; i <= n; i++)
	{
		dis[i] = INF;
	}

	dis[s] = 0;
	g.push({ 0,s });
	
	while (!g.empty())
	{
		auto t = g.top();
		g.pop();

		ll value = t.first;
		int v = t.second;


		if (visit[v])continue;

		visit[v] = 1;
		for (int k = 0; k < e[v].size(); k++)
		{
			int nxt = e[v][k].second;
			int val = e[v][k].first;

			if (dis[nxt] > dis[v] + val)
			{
				dis[nxt] = dis[v] + val;
				g.push({ dis[nxt],nxt });
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << ' ';
	}

	return 0;
}
