// ======================================================================
// 洛谷 P1434  [SHOI2002] 滑雪
// 难度: 普及    (题单顺序 48/69)
// 题目: https://www.luogu.com.cn/problem/P1434
// 记录: https://www.luogu.com.cn/record/282114533
// 结果: Accepted · 100 分 · 43 ms · 832 KB · 提交于 2026-06-17 10:36
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// Michael 喜欢滑雪。这并不奇怪，因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael 想知道在一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子：
// ```plain
// 1   2   3   4   5
// 16  17  18  19  6
// 15  24  25  20  7
// 14  23  22  21  8
// 13  12  11  10  9
// ```
// 一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度会减小。在上面的例子中，一条可行的滑坡为 $24-17-16-1$（从 $24$ 开始，在 $1$ 结束）。当然 $25-24-23-\ldots-3-2-1$ 更长。事实上，这是最长的一条。
//
// 【输入格式】
// 输入的第一行为表示区域的二维数组的行数 $R$ 和列数 $C$。下面是 $R$ 行，每行有 $C$ 个数，代表高度（两个数字之间用 $1$ 个空格间隔）。
//
// 【输出格式】
// 输出区域中最长滑坡的长度。
//
// 【样例 #1】
// 输入:
// 5 5
// 1 2 3 4 5
// 16 17 18 19 6
// 15 24 25 20 7
// 14 23 22 21 8
// 13 12 11 10 9
// 
// 输出:
// 25
//
// 【提示】
// 对于 $100\%$ 的数据，$1\leq R,C\leq 100$。
// 
// 对于任意输入的高度 $h$，满足 $0 \le h \le 10000$，且 $h$ 是整数。
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

int r, c;
int map[110][110];
int dp[110][110];
int x_move[4] = { -1,1,0,0 };
int y_move[4] = { 0,0,1,-1 };

int max_trial(int x, int y)
{
    if (dp[x][y] > 0)return dp[x][y];

    int max_length = 1;
    dp[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        if ((map[x + x_move[i]][y + y_move[i]] < map[x][y]) && !(x + x_move[i] == 0 || x + x_move[i] == r + 1 || y + y_move[i] == 0 || y + y_move[i] == c + 1))
        {
            dp[x][y] = max(dp[x][y], max_trial(x + x_move[i], y + y_move[i]) + 1);
            max_length = max(dp[x][y], max_length);
        }
    }

    return max_length;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r>> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> map[i][j];
        }
    }
    int ans=0;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            ans = max(ans, max_trial(i,j));
        }
    }

    cout << ans;
    return 0;
}
