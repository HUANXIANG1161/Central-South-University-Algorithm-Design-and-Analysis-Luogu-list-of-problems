// ======================================================================
// 洛谷 P12890  [蓝桥杯 2025 国 Java B] 道具摆放
// 难度: 普及+/提高-    (题单顺序 26/69)
// 题目: https://www.luogu.com.cn/problem/P12890
// 记录: https://www.luogu.com.cn/record/282110944
// 结果: Accepted · 100 分 · 851 ms · 1376 KB · 提交于 2026-06-17 09:07
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 小蓝是社区剧团的道具员，他负责管理一排编号为 $1$ 到 $N$ 的道具箱。平常，这些道具箱会按编号升序排列在舞台上。
// 
// 今天晚上有一场重要的演出，演出开始前，导演小李递给小蓝一份清单，上面写着他想要的道具箱排列顺序：$P_1, P_2, \ldots, P_N$。导演希望小蓝在演出过程中将这排箱子调整成这个顺序。由于舞台空间狭小，每次调整只能交换相邻两个箱子的位置。且每完成一次交换，舞台灯光就会闪烁一次作为提示。
// 
// 灯光系统有个特别的节奏设定：每进行 $M$ 次闪烁，灯光就会切换一种模式。为了配合这种节奏，导演强调：必须在某次灯光切换模式的那一瞬间完成所有调整工作。这意味着，小蓝完成调整所需的交换次数必须是 $M$ 的整数倍。
// 
// 现在，请你帮小蓝计算一下，他最少需要多少次交换操作才能按照导演的要求完成调整。如果无论如何都无法满足要求，则输出 $-1$。
// 
//
// 【输入格式】
// 第一行包含两个整数 $N$ 和 $M$，分别表示道具箱的数量和灯光模式切换的周期。
// 
// 第二行包含 $N$ 个整数 $P_1, P_2, \ldots, P_N$，表示导演想要的道具箱排列顺序。
//
// 【输出格式】
// 输出一个整数，表示最少需要的操作次数。如果无法满足导演的要求，则输出 $-1$。
//
// 【样例 #1】
// 输入:
// 3 2
// 3 1 2
// 输出:
// 2
//
// 【样例 #2】
// 输入:
// 3 3
// 1 2 3
// 输出:
// 0
//
// 【样例 #3】
// 输入:
// 3 2
// 1 3 2
// 输出:
// -1
//
// 【提示】
// **【评测用例规模与约定】**
// 
// 对于 $50\%$ 的评测用例，$1 \leq N, M \leq 10^2$，$1 \leq P_i \leq N$，$P_1, P_2, \ldots, P_N$ 互不相同。
// 
// 对于 $100\%$ 的评测用例，$1 \leq N \leq 10^5$，$1 \leq M \leq 10^9$，$1 \leq P_i \leq N$，$P_1, P_2, \ldots, P_N$ 互不相同。
// 
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define ll long long
using namespace std;

int n;
ll m;
int a[100010];
int b[100010];
ll flip = 0;


void m_sort(int left, int right, int mid)
{
    int lh = left, rh = mid + 1,cnt=left;

    while (lh <= mid && rh <= right)
    {
        if (a[lh]  <= a[rh])
        {
            b[cnt++] = a[lh++];
        }
        else
        {
            b[cnt++] = a[rh++];
            flip += mid - lh + 1;
        }
    }
    while (lh <= mid)
    {
        b[cnt++] = a[lh++];
    }
    while (rh <= right)
    {
        b[cnt++] = a[rh++];
    }

    for (int i = left; i <= right; i++)
    {
        a[i] = b[i];
    }
}

void merge_sort(int left, int right)
{
    if (left == right)return;

    int mid = (left + right) / 2;

    merge_sort(left, mid);
    merge_sort(mid + 1, right);
    m_sort(left, right, mid);
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <=n; i++)
    {
        cin >> a[i];
    }

    merge_sort(1, n);


    if (flip == 0)
    {
        cout << 0;
        return 0;
    }


    if (flip % 2 == 1 && m % 2 == 0)cout << -1;
    else/*((flip%2==0&&m%2==0)||(flip%2==1&&m%2==1))*/
    {
        for (int i = 0;; i++)
        {
            if (m*i>=flip&& ((flip % 2 == 0 && m*i% 2 == 0) || (flip % 2 == 1 && m*i % 2 == 1)))
            {
                cout << m * i;
                break;
            }
        }
    }
    //else
    //{
    //    for (int i = 0;; i++)
    //    {
    //        if (m * i >= flip)
    //        {
    //            cout << m * (i+1);
    //            break;
    //        }
    //    }
    //}

    return 0;
}
