// ======================================================================
// 洛谷 P4568  [JLOI2011] 飞行路线
// 难度: 普及+/提高-    (题单顺序 69/69)
// 题目: https://www.luogu.com.cn/problem/P4568
// 记录: https://www.luogu.com.cn/record/282108592
// 结果: Accepted · 100 分 · 448 ms · 54044 KB · 提交于 2026-06-17 01:45
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// Alice 和 Bob 现在要乘飞机旅行，他们选择了一家相对便宜的航空公司。该航空公司一共在 $n$ 个城市设有业务，设这些城市分别标记为 $0$ 到 $n-1$，一共有 $m$ 种航线，每种航线连接两个城市，并且航线有一定的价格。
// 
// Alice 和 Bob 现在要从一个城市沿着航线到达另一个城市，途中可以进行转机。航空公司对他们这次旅行也推出优惠，他们可以免费在最多 $k$ 种航线上搭乘飞机。那么 Alice 和 Bob 这次出行最少花费多少？
//
// 【输入格式】
// 第一行三个整数 $n,m,k$，分别表示城市数，航线数和免费乘坐次数。
// 
// 接下来一行两个整数 $s,t$，分别表示他们出行的起点城市编号和终点城市编号。
// 
// 接下来 $m$ 行，每行三个整数 $a,b,c$，表示存在一种航线，能从城市 $a$ 到达城市 $b$，或从城市 $b$ 到达城市 $a$，价格为 $c$。
//
// 【输出格式】
// 输出一行一个整数，为最少花费。
//
// 【样例 #1】
// 输入:
// 5 6 1
// 0 4
// 0 1 5
// 1 2 5
// 2 3 5
// 3 4 5
// 2 3 3
// 0 2 100
// 输出:
// 8
//
// 【提示】
// #### 数据规模与约定
// 
// 对于 $30\%$ 的数据，$2 \le n \le 50$，$1 \le m \le 300$，$k=0$。
// 
// 对于 $50\%$ 的数据，$2 \le n \le 600$，$1 \le m \le 6\times10^3$，$0 \le k \le 1$。
// 
// 对于 $100\%$ 的数据，$2 \le n \le 10^4$，$1 \le m \le 5\times 10^4$，$0 \le k \le 10$，$0\le s,t,a,b < n$，$a\ne b$，$0\le c\le 10^3$。
// 
// 另外存在一组 hack 数据。
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<ll, int> PLI;
const int MAXN = 10005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

vector<PLI> e[MAXN * 15];
ll dist[MAXN * 15];
int n, m, k, s, t;

// Dijkstra 模板
ll dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<PLI, vector<PLI>, greater<PLI>> heap;
    dist[s] = 0;
    heap.push({ 0, s });

    while (!heap.empty())
    {
        auto now = heap.top();
        heap.pop();
        ll dis_u = now.first;
        int u = now.second;

        if (dis_u > dist[u]) continue;

        for (auto& ed : e[u])
        {
            int v = ed.second;
            ll w = ed.first;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                heap.push({ dist[v], v });
            }
        }
    }

    // 遍历0~k层的终点t，取最小值
    ll ans = INF;
    for (int p = 0; p <= k; p++)
    {
        ans = min(ans, dist[t + p * n]);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    cin >> s >> t;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        for (int p = 0; p <= k; p++)
        {
            int u = a + p * n;
            int v = b + p * n;
            e[u].emplace_back(c, v);
            e[v].emplace_back(c, u);
            if (p < k)
            {
                int u_next = a + (p + 1) * n;
                int v_next = b + (p + 1) * n;
                e[u].emplace_back(0, v_next);
                e[v].emplace_back(0, u_next);
            }
        }
    }

    cout << dijkstra() << endl;
    return 0;
}
