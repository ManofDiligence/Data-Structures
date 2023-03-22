#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n = 3;
vector<int> permutation;
bool chosen[3];
void search()
{
    if(permutation.size()==n)
    {
        // process permutation
        cout<<"(";
        for(int i=0; i<permutation.size(); i++)
        {
            if(i==permutation.size()-1)
                cout<<permutation[i];
            else cout<<permutation[i]<<",";
        }
        cout<<")";
        cout<<endl;
    }
    else{
        for(int i=0; i<n; i++)
        {
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

void iterative()
{
    int n = 3;
    vector <int> permutation;
    for(int i=0; i<n; i++)
        permutation.push_back(i);
    do{
        // process permutation
        cout<<"(";
        for(int i=0; i<permutation.size(); i++)
        {
            if(i==permutation.size()-1)
                cout<<permutation[i];
            else cout<<permutation[i]<<",";
        }
        cout<<")";
        cout<<endl;
    }while(next_permutation(permutation.begin(), permutation.end()));
}
int main()
{
    //search();
    iterative();
    return 0;
}