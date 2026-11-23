// ======================================================================
// 洛谷 P1226  【模板】快速幂
// 难度: 普及-    (题单顺序 27/69)
// 题目: https://www.luogu.com.cn/problem/P1226
// 记录: https://www.luogu.com.cn/record/281508927
// 结果: Accepted · 100 分 · 32 ms · 1064 KB · 提交于 2026-06-12 01:36
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 给你三个整数 $a,b,p$，求 $a^b \bmod p$。
//
// 【输入格式】
// 输入只有一行三个整数，分别代表 $a,b,p$。
// 
//
// 【输出格式】
// 输出一行一个字符串 `a^b mod p=s`，其中 $a,b,p$ 分别为题目给定的值， $s$ 为运算结果。
//
// 【样例 #1】
// 输入:
// 2 10 9
// 
// 输出:
// 2^10 mod 9=7
// 
//
// 【提示】
// **样例解释**
// 
// $2^{10} = 1024$，$1024 \bmod 9 = 7$。
// 
// **数据规模与约定**
// 
// 对于 $100\%$ 的数据，保证 $0\le a,b < 2^{31}$，$a+b>0$，$2 \leq p \lt 2^{31}$。
//
// ---------------------------- 代码 ----------------------------

#include<iostream>
using namespace std;
typedef long long ll;

ll quick_power(ll a, ll b, ll mod)
{
    if (b == 0) return 1 % mod;
    if (b == 1) return a % mod;
    ll res = quick_power(a, b / 2, mod);
    res = res * res % mod;
    if (b & 1)
        res = res * a % mod;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, p;
    cin >> a >> b >> p;
    ll ans = quick_power(a % p, b, p);
    cout << a << "^" << b << " mod " << p << "=" << ans;
    return 0;
}
