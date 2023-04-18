#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, i=0, x=0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        // 2^7
        bool isFound= false;
        for(x=0; x<(1<<7); x++)
        {
            int sum = 0;
            for(int j=0; j<n; j++)
            {
                // given formula
                int b = a[j]^x;
                // b1 XOR b2 ... bn
                sum^=b;
            }
            if(sum==0)
            {
                isFound = true;
                break;
            }
        }
        if(isFound) cout<<x<<endl;
        else cout<<-1<<endl;
        
    }
    return 0;
}
