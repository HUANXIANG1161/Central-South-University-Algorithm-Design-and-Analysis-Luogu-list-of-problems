// ======================================================================
// 洛谷 P1219  [USACO1.5] 八皇后 Checker Challenge
// 难度: 普及    (题单顺序 12/69)
// 题目: https://www.luogu.com.cn/problem/P1219
// 记录: https://www.luogu.com.cn/record/282108737
// 结果: Accepted · 100 分 · 351 ms · 1064 KB · 提交于 2026-06-17 02:08
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 一个如下的 $6 \times 6$ 的跳棋棋盘，有六个棋子被放置在棋盘上，使得每行、每列有且只有一个，每条对角线（包括两条主对角线的所有平行线）上至多有一个棋子。
// 
// ![](https://cdn.luogu.com.cn/upload/image_hosting/3h71x0yf.png)
// 
// 上面的布局可以用序列 $2\ 4\ 6\ 1\ 3\ 5$ 来描述，第 $i$ 个数字表示在第 $i$ 行的相应位置有一个棋子，如下：
// 
// ::cute-table{tuack}
// |行号|$1$|$2$|$3$|$4$|$5$|$6$|
// |:-:|:-:|:-:|:-:|:-:|:-:|:-:|
// |列号|$2$|$4$|$6$|$1$|$3$|$5$|
// 
// 这只是棋子放置的一个解。请编一个程序找出所有棋子放置的解。
// 并把它们以上面的序列方法输出，解按字典顺序排列。
// 请输出前 $3$ 个解。最后一行是解的总个数。
//
// 【输入格式】
// 一行一个正整数 $n$，表示棋盘是 $n \times n$ 大小的。
//
// 【输出格式】
// 前三行为前三个解，每个解的两个数字之间用一个空格隔开。第四行只有一个数字，表示解的总数。
//
// 【样例 #1】
// 输入:
// 6
// 
// 输出:
// 2 4 6 1 3 5
// 3 6 2 5 1 4
// 4 1 5 2 6 3
// 4
// 
//
// 【提示】
// ### 数据范围
// 对于 $100\%$ 的数据，$6 \le n \le 13$。
// 
// 题目翻译来自NOCOW。
// 
// USACO Training Section 1.5
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;

bool con[19];
int col[19];
bool main_line[38], unmain_line[38];
int ans = 0;

void dfs(int x)
{
    if (x > n)
    {
        ans++;
        if (ans <= 3)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << col[i] << ' ';
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!con[i] && !main_line[x - i + n] && !unmain_line[x + i + n])
        {
            col[x] = i;
            con[i] =  main_line[x - i + n] = unmain_line[x + i + n] = 1;
            dfs(x + 1);
            con[i] = main_line[x - i + n] = unmain_line[x + i + n] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    dfs(1);

    cout << ans;

    return 0;
}
