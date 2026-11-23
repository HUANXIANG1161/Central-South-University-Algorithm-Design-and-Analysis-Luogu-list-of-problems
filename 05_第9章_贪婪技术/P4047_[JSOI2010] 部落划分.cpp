// ======================================================================
// 洛谷 P4047  [JSOI2010] 部落划分
// 难度: 普及+/提高-    (题单顺序 66/69)
// 题目: https://www.luogu.com.cn/problem/P4047
// 记录: https://www.luogu.com.cn/record/282043461
// 结果: Accepted · 100 分 · 108 ms · 8720 KB · 提交于 2026-06-16 13:12
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 聪聪研究发现，荒岛野人总是过着群居的生活，但是，并不是整个荒岛上的所有野人都属于同一个部落，野人们总是拉帮结派形成属于自己的部落，不同的部落之间则经常发生争斗。只是，这一切都成为谜团了——聪聪根本就不知道部落究竟是如何分布的。
// 
// 不过好消息是，聪聪得到了一份荒岛的地图。地图上标注了 $n$ 个野人居住的地点（可以看作是平面上的坐标）。我们知道，同一个部落的野人总是生活在附近。我们把两个部落的距离，定义为部落中距离最近的那两个居住点的距离。聪聪还获得了一个有意义的信息——这些野人总共被分为了 $k$ 个部落！这真是个好消息。聪聪希望从这些信息里挖掘出所有部落的详细信息。他正在尝试这样一种算法：
// 
// 对于任意一种部落划分的方法，都能够求出两个部落之间的距离，聪聪希望求出一种部落划分的方法，使靠得最近的两个部落尽可能远离。
// 
// 例如，下面的左图表示了一个好的划分，而右图则不是。请你编程帮助聪聪解决这个难题。
// 
// 
// ![](https://cdn.luogu.com.cn/upload/pic/30573.png)
//
// 【输入格式】
// 输入文件第一行包含两个整数 $n$ 和 $k$，分别代表了野人居住点的数量和部落的数量。
// 
// 接下来 $n$ 行，每行包含两个整数 $x$，$y$，描述了一个居住点的坐标。
//
// 【输出格式】
// 输出一行一个实数，为最优划分时，最近的两个部落的距离，精确到小数点后两位。
//
// 【样例 #1】
// 输入:
// 4 2
// 0 0
// 0 1
// 1 1
// 1 0
// 
// 输出:
// 1.00
// 
//
// 【样例 #2】
// 输入:
// 9 3
// 2 2
// 2 3
// 3 2
// 3 3
// 3 5
// 3 6
// 4 6
// 6 2
// 6 3
// 输出:
// 2.00
//
// 【提示】
// #### 数据规模与约定
// 
// 对于 $100\%$ 的数据，保证 $2 \leq k \leq n \leq 10^3$，$0 \leq  x, y \leq 10^4$。
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

edge a[1000010];
int x[1010];
int y[1010];
int f[1010];

int n, k;
int cnt=0;

bool cmp(edge x,edge y)
{
    return x.dis < y.dis;
}

int find(int x)
{
    if (f[x] == x)return f[x];
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
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++)
        f[i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            double dis = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            a[cnt].x = i;
            a[cnt].y = j;
            a[cnt].dis = dis;
            cnt++;
        }
    }

    sort(a, a + cnt, cmp);
    int l = 0;

    for (int i = 0; i < cnt; i++)
    {
        int fa1 = find(a[i].x);
        int fa2 = find(a[i].y);
        if (fa1 == fa2)continue;

        f[fa1] = fa2;
        l++;
        if (l == n - k + 1)
        {
            cout <<fixed<<setprecision(2)<< a[i].dis;
            return 0;
        }
    }
    return 1;
}
