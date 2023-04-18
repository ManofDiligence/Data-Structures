#include <iostream>
#include <vector>
using namespace std;

vector<int> maxEle(vector<int> arr, int targetSum)
{
    vector<int> v;

    int p1 = 0, p2 = arr.size()-1;
    while(p1<p2)
    {   
        int curSum = arr[p1]+arr[p2];
        if(curSum==targetSum)
        {
            v.push_back(arr[p1]);
            v.push_back(arr[p2]);
            p1++;
            p2--;
        }
        else if(curSum>targetSum)
        {
            p2--;
        }
        else{
            p1++;
        }
    }
    return v;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    vector<int> v = maxEle(arr, 7);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}