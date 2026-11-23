// ======================================================================
// 洛谷 P1948  [USACO08JAN] Telephone Lines S
// 难度: 普及+/提高-    (题单顺序 68/69)
// 题目: https://www.luogu.com.cn/problem/P1948
// 记录: https://www.luogu.com.cn/record/282108190
// 结果: Accepted · 100 分 · 673 ms · 4620 KB · 提交于 2026-06-17 00:58
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// Farmer John 想在自己的农场架设一条电话线。不幸的是，电话公司并不配合，所以他只能自己承担一部分连接农场与电话系统所需的电缆费用。
// 
// 有 $N$（$1 \le N \le 1{,}000$）根孤立的电线杆散布在农场各处，为方便起见，这些电线杆被编号为 $1 \ldots N$；它们之间没有任何电缆连接。共有 $P$（$1 \le P \le 10{,}000$）对电线杆可以用电缆连接，其余的电线杆对相距太远。
// 
// 第 $i$ 根电缆可以连接两个不同的电线杆 $A_i$ 和 $B_i$，长度为 $L_i$（$1 \le L_i \le 1{,}000{,}000$）单位（输入中不存在重复的 $\{A_i, B_i\}$ 对）。电线杆 $1$ 已经接入电话系统，电线杆 $N$ 位于农场。需要用一条由电缆组成的路径把电线杆 $1$ 和 $N$ 连通，其余的电线杆用或不用都可以。
// 
// 电话公司愿意免费为 Farmer John 提供 $K$（$0 \le K < N$）段电缆。除这 $K$ 段外，他需要的其余电缆按其中最长的长度计费（每对电线杆之间的连接各用一根独立的电缆）；如果他不需要任何额外的电缆，则支付 $0$。
// 
// 求 Farmer John 至少需要支付多少钱。
//
// 【输入格式】
// 第一行输入三个整数 $N,P,K$。
// 
// 接下来 $P$ 行，第 $i$ 行包含三个整数 $A_i,B_i,L_i$。
//
// 【输出格式】
// 一行一个整数，表示 Farmer John 至少要付的金额。如果无法把农场接到电话系统上，输出 `-1`。
//
// 【样例 #1】
// 输入:
// 5 7 1
// 1 2 5
// 3 1 4
// 2 4 8
// 3 2 3
// 5 2 9
// 3 4 7
// 4 5 6
// 
// 输出:
// 4
// 
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
#define INF 0x3f3f3f3f

using namespace std;

int n, p, k;
int neibor[1010][1010];
int d[1010];
bool visit[1010];

bool check(int x)
{
    memset(d, INF, sizeof d);
    memset(visit, 0, sizeof visit);

    d[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        int v = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!visit[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        if (d[v] == INF)break;
        visit[v] = 1;

        for (int z = 1; z <= n; z++)
        {
            if (visit[z])continue;
            if (neibor[v][z] == INF) continue;

            int cost = neibor[v][z] <= x ? 0 : 1;

            d[z] = min(d[z], d[v] + cost);
        }
    }

    return d[n]<=k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            neibor[i][j] = INF;
        }
        d[i] = INF;
    }

    for (int i = 0; i < p; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        neibor[x][y] = neibor[y][x] = v;
    }

    int left = 0, right = 1000000;
    int ans = -1;

    while (left <= right)
    {
        int mid = (left + right)/2;
        
        if (check(mid))
        {
            ans = mid;
            right = mid-1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;


}
