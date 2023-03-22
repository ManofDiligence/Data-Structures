#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> s={12,34,56,78,910};
    random_shuffle(s.begin(), s.end());
    for(auto x: s)
        cout<<x<<" ";
}