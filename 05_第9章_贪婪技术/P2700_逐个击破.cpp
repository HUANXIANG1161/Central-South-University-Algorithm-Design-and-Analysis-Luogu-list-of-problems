// ======================================================================
// 洛谷 P2700  逐个击破
// 难度: 普及+/提高-    (题单顺序 67/69)
// 题目: https://www.luogu.com.cn/problem/P2700
// 记录: https://www.luogu.com.cn/record/282045768
// 结果: Accepted · 100 分 · 144 ms · 2564 KB · 提交于 2026-06-16 13:41
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目背景】
// 三大战役的平津战场上，傅作义集团在以北平、天津为中心，东起唐山西至张家口的铁路线上摆起了一字长蛇阵，并企图在溃败时从海上南逃或向西逃窜。为了就地歼敌不让其逃走，指挥官制定了先切断敌人东西两头退路然后再逐个歼灭敌人的战略方针。秉承伟大军事家的战略思想，作为一个有智慧的军长你，遇到了一个类似的战场局面。
//
// 【题目描述】
// 现在有 $N$ 个城市，其中 $K$ 个被敌方军团占领了，$N$ 个城市间有 $N-1$ 条公路相连，破坏其中某条公路的代价是已知的，现在，告诉你 $K$ 个敌方军团所在的城市，以及所有公路破坏的代价，请你算出花费最少的代价将这 $K$ 个敌方军团互相隔离开，以便第二步逐个击破敌人。
//
// 【输入格式】
// 第一行包含两个正整数 $N$ 和 $K$。
// 
// 第二行包含 $K$ 个整数，表示哪些城市被敌军占领。
// 
// 接下来 $N-1$ 行，每行包含三个非负整数 $a,b,c$，表示从 $a$ 城市到 $b$ 城市有一条公路，以及破坏的代价 $c$。城市的编号从 $0$ 开始。
//
// 【输出格式】
// 输出一行一个整数，表示最少花费的代价。
//
// 【样例 #1】
// 输入:
// 5 3
// 1 2 4
// 1 0 4
// 1 3 8
// 2 1 1
// 2 4 3
// 输出:
// 4
//
// 【提示】
// 对于 $10\%$ 的数据，$N\le 10$。
// 
// 对于 $100\%$ 的数据，$2\le N\le10^5$，$2\le K\le N$，$1\le c\le 10^6$。
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

struct edge
{
    int x, y;
    double dis;
};

int n, k;
edge a[100010];
int f[100010];
bool enemy[100010];
int cnt;

bool cmp(edge x,edge y)
{
    return x.dis > y.dis;
}

int find(int x)
{
    if (f[x] == x)return x;
    else
    {
        f[x] = find(f[x]);
        return f[x];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int tmp;
        cin >> tmp;
        enemy[tmp] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        f[i] = i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[cnt].x >> a[cnt].y >> a[cnt].dis;
        cnt++;
    }

    sort(a, a + cnt, cmp);
    ll ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int fa1 = find(a[i].x);
        int fa2 = find(a[i].y);
        if (fa1 == fa2)continue;

        if (enemy[fa1] && enemy[fa2])
        {
            ans += a[i].dis;
        }

        else
        {
            f[fa2] = fa1;
            enemy[fa1] = enemy[fa1] || enemy[fa2];
        }
    }

    cout << ans;
    return 0;
}
