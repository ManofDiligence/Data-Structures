#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int best;
    // O(n^2)
    /*for(int i=0; i<arr.size(); i++)
    {
        int sum=0;
        for(int j=i; j<arr.size(); j++)
        {
            sum+=arr[j];
            if(sum>best) best = sum;
        }
    }*/
    vector<int> arr {-1,2,4,-3,5,2,-5,2} ;
    // O(n)
    int sum=0;
    int bestSum=0;
    int i=0;
    while(i<arr.size()){   
        sum = max(arr[i], sum+arr[i]);
        bestSum=max(bestSum, sum);
        i++;
    }
    cout<<bestSum;
}