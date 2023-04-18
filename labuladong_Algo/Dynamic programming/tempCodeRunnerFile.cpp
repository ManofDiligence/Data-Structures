#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp(vector<int>& coins, int amount);
int coinChange(vector<int>& coins, int amount)
{
    // base case 
    return dp(coins, amount);
}

int dp(vector<int>& coins, int amount)
{
    if(amount==0) return amount;
    int res = INT_MAX;
    for(int c: coins)
    {
        res = min(res, dp(coins, amount-c)+1);
    }

    return res;

}
int main()
{

    vector<int> coins = {1,2,5};

    cout<<coinChange(coins, 11);
    return 0;
}