#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    set<int> s= {5,4,2,7,8,1};
    cout<<"By increasing order: ";
    for(auto i = s.begin(); i!=s.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    int x = 3;
    auto j = s.lower_bound(x);
    if(j==s.begin())
    {
        cout<<"i am in begin ";
        cout<<*j<<"\n";
    }
    else if(j==s.end())
    {
        cout<<"i am in end ";
        j--;
        cout<<*j<<"\n";
    }
    else {
         cout<<"i am in else ";
        int a = *j; j--;
        int b = *j;
        if(x-b<a-x) cout<< b<<"\n";
        else cout<<a<<"\n";
    }
    
}