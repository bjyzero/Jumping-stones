// 二分答案是二分法中最常见也最重要的题型，需要从题目中发现某个单调的函数，然后对其二分
// 常见模型：
// 二分框架 (时间复杂度 O(log m)) + check函数 (时间复杂度 O(n))
// 一般情况下，将 "答案进行二分" ，然后在枚举出某个可能解后判断其是否可以 "更优或者是否合法" ，从而不断逼近最优解
// 二分答案题的特征：如果已知某个答案，"很容易" 判断其是否合法或更优。
// 某些贪心问题，可能可以转换成二分答案的问题

// 当跳跃距离越长时，需要移走的石头数量也越多，于是就产生了单调性
// 我们通过二分最短跳跃距离，在已知 "最短跳跃距离" 的情况下容易 O(n) 计算需要搬走的石头数量，找到分界点即可
//(即在至多搬走 M 块石头的情况下的最远跳跃距离)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e4 + 9;
int a[N];
int L, n, m;

// 该函数 -> 最远跳跃距离为 mid 的情况下，最少需要搬走多少块石头
int check(int mid)
{
    int res = 0, lst = 0; // lst 表示上一个石头的位置
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] - a[lst] < mid)
        {
            res++;
            continue;
        }
        lst = i;
    }
    if (L - a[lst] < mid) // 注意判断
        return m + 1;
    return res;
}

// 列举 出跳跃距离为""时 (mid -> l 和 r 移动的地方)，要移走的石块数量(check())
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> L >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll l = 0, r = L;
    while (l + 1 != r) // 只要不满足这个条件就一直做二分
    {
        ll mid = (l + r) / 2;
        if (check(mid) <= m)
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}