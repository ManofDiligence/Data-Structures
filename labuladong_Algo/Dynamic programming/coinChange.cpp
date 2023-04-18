#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(vector<int>& coins, int amount);
int dp1(vector<int>& coins, int amount);
int coinChange(vector<int>& coins, int amount)
{
    // base case 
    return dp(coins, amount);
}
// 1. 暴力遞歸 brute force method
// time complexity - O(k^n)
// k = number of coins in given coins array
// n = amount 
int dp(vector<int>& coins, int amount)
{
    if(amount==0) return amount;
    if(amount<0) return -1;
    int res = INT_MAX;
    for(int c: coins)
    {
        int subproblems = dp(coins, amount-c);  
        if(subproblems==-1) continue;
        res = min(res, subproblems+1);
    }
    return res == INT_MAX? -1: res;

}

// 2. memoization method - 帶備忘錄的遞歸
// time complexity - O(k*n)
vector<int> memo;
int dp1(vector<int>& coins, int amount)
{
    if(amount==0) return amount;
    if(amount<0) return -1;
    if(memo[amount]!=-1) return memo[amount];
    int res = INT_MAX;
    for(int c: coins)
    {
        int subproblems = dp(coins, amount-c);
        if(subproblems==-1) continue;
        res = min(res, subproblems+1);
    }
    memo[amount] = res == INT_MAX? -1: res;
    
    return memo[amount];
}
int coinChange1(vector<int>& coins, int amount)
{
    memo = vector<int> (amount+1, -1);
    return dp1(coins, amount);
}

// 3. dp 數組的迭代解法
int coinChange2(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1, amount+1);
    dp[0]=0;
    for(int i=0; i<dp.size(); i++)
    {
        for(int c: coins)
        {
            if(i-c>=0)
            {
                dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
    }
    return dp[amount]==amount+1? -1: dp[amount];
}
int main()
{

    vector<int> coins;
    //[186,419,83,408]
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    cout<<coinChange2(coins, 10);
    return 0;
}