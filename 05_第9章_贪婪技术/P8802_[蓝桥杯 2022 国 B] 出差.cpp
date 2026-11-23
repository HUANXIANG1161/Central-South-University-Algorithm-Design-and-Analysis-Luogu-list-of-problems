// ======================================================================
// 洛谷 P8802  [蓝桥杯 2022 国 B] 出差
// 难度: 普及    (题单顺序 63/69)
// 题目: https://www.luogu.com.cn/problem/P8802
// 记录: https://www.luogu.com.cn/record/282031847
// 结果: Accepted · 100 分 · 79 ms · 5628 KB · 提交于 2026-06-16 08:30
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// $\mathrm{A}$ 国有 $N$ 个城市，编号为 $1 \ldots N$ 小明是编号为 $1$ 的城市中一家公司的员工，今天突然接到了上级通知需要去编号为 $N$ 的城市出差。
// 
// 由于疫情原因，很多直达的交通方式暂时关闭，小明无法乘坐飞机直接从城市 $1$ 到达城市 $N$，需要通过其他城市进行陆路交通中转。小明通过交通信息网，查询到了 $M$ 条城市之间仍然还开通的路线信息以及每一条路线需要花费的时间。
// 
// 同样由于疫情原因，小明到达一个城市后需要隔离观察一段时间才能离开该城市前往其他城市。通过网络，小明也查询到了各个城市的隔离信息。（由于小明之前在城市 $1$，因此可以直接离开城市 $1$，不需要隔离）
// 
// 由于上级要求，小明希望能够尽快赶到城市 $\mathrm{N}$, 因此他求助于你，希望你能帮他规划一条路线，能够在最短时间内到达城市 $N$ 。
//
// 【输入格式】
// 第 $1$ 行：两个正整数 $N, M$，$N$ 表示 A 国的城市数量, $M$ 表示未关闭的路线数量。
// 
// 第 $2$ 行: $N$ 个正整数，第 $i$ 个整数 $C_{i}$ 表示到达编号为 $\mathrm{i}$ 的城市后需要隔离的时间。
// 
// 第 $3 \ldots M+2$ 行: 每行 $3$ 个正整数, $u, v, c$, 表示有一条城市 $u$ 到城市 $v$ 的双向路线仍然开通着，通过该路线的时间为 $c$。
//
// 【输出格式】
// 第 $1$ 行：$1$ 个正整数，表示小明从城市 $1$ 出发到达城市 $N$ 的最短时间。（到达城市 $N$，不需要计算城市 $N$ 的隔离时间）
//
// 【样例 #1】
// 输入:
// 4 4
// 5 7 3 4
// 1 2 4
// 1 3 5
// 2 4 3
// 3 4 5
// 输出:
// 13
//
// 【提示】
// **【样例说明】**
// 
// ![](https://cdn.mathpix.com/cropped/2022_09_29_8ee8d95d6d0319bca20dg-09.jpg?height=464&width=478&top_left_y=1249&top_left_x=309)
// 
// **【评测用例规模与约定】**
// 
// 对于 $100 \%$ 的数据, $1 \leq N \leq 1000,1 \leq M \leq 10000,1 \leq C_{i} \leq 200,1 \leq u, v \leq$ $N, 1 \leq c \leq 1000$
// 
// 
// 蓝桥杯 2022 国赛 B 组 E 题。
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
int n,m,c[100010];
priority_queue<pair<ll, int>,vector<pair<ll,int>>,greater<pair<ll,int>>> g;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n>> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}


	for(int i=0;i<m;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({ w, v});
		e[v].push_back({ w,u });
	}

	for (int i = 1; i <= n; i++)
	{
		dis[i] = INF;
	}

	dis[1] = 0;
	g.push({ 0,1 });
	
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

			if (dis[nxt] > dis[v] + val+c[nxt])
			{
				dis[nxt] = dis[v] + val+ c[nxt];
				g.push({ dis[nxt],nxt });
			}
		}
	}

	cout << dis[n] - c[n];

	return 0;
}
