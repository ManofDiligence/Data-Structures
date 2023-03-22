#include <iostream>
#include <vector>
using namespace std;
int n=3;
vector<int> subset;
// method 1: recursive search
void search(int k)
{
    if(k==n)
    {
        // process subset
        cout<<"{";
        for(int i=0; i<subset.size(); i++)
            cout<<subset[i];
        cout<<"}, ";
        return; 
    }
    else{
        search(k+1);
        subset.push_back(k);
        search(k+1);
        subset.pop_back();
    }
    
}
// method 2: exploit the bit representation of integers
void bit()
{
int n1 = 5;
// the following code is find the subsets between 0 to 31[(2^5) -1]
vector<int> subset1;
for(int b=0; b<(1<<n1); b++)
{
    vector<int> subset1;
    for(int i=0; i<n1; i++)
    {
        if(b&(1<<i)) subset1.push_back(i);
    }
    cout<< b<<": ";
    for(int j=0; j<subset1.size(); j++)
        cout<<subset1[j]<<",";
    cout<<endl;
}
}

int main()
{
    search(0);
    //bit();
    return 0;
}