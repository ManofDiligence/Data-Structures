#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
f(n)的函數參數會不斷變化，所以你把參數 n 想做一個狀態，
這個狀態 n 是由狀態 n - 1 和狀態 n - 2 轉移（相加）而來，這就叫狀態轉移，僅此而已。
*/

// brute force method (recur) 
// time complexity - O(2^n)
// space complexity - O(1)
// 千萬不要看不起暴力解，動態規劃問題最困難的就是寫出這個暴力解，即狀態轉移方程。
int fib0(int n)
{
    // base case
    if(n==1||n==2) return 1;
    return fib0(n-1)+fib0(n-2);
}

// memoization method (recur) -> avoid doing duplicate things
// time and space complexity - O(n)
int dp(vector<int>& memo, int );

int fib1(int n)
{
    //int *memo = new int[n+1];
    
    vector<int> memo(n+1, -1);
    return dp(memo, n);
}

int dp(vector<int>& memo, int n)
{
    // base case
    if(n==0||n==1) return n;
    if(memo[n]!=-1) return memo[n];
    memo[n] = dp(memo, n-1) + dp(memo, n-2);
    return memo[n];
}

// dp array (loop) 
// time and space complexity - O(n)
int fib2(int n)
{
    int *dp = new int[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
// 根據斐波那契數列的狀態轉移方程，
// 當前狀態 n 只和之前的 n-1, n-2 兩個狀態有關，
// 其實並不需要那麼長的一個DP table 來存儲所有的狀態，只要想辦法存儲之前的兩個狀態就行了。
// 可以進一步優化，把空間複雜度降為O(1)。這也就是我們最常見的計算斐波那契數的算法：
// time complexity - O(n)
// space complexity - O(1)
int fib3(int n)
{
    // base case
    if(n==0||n==1) return n;

    // dp1 = dp[n-1]
    // dp2 = dp[n-2]
    int dp2 = 0, dp1 = 1;
    for(int i=2; i<=n; i++)
    {
        int dpi = dp1 + dp2;
        dp2 = dp1;
        dp1 = dpi;
    }

    return dp1;

}

int main()
{

    cout<<fib3(5);

    return 0;
}