//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int x=__builtin_popcount(a);
        int y=__builtin_popcount(b);
        if(x==y)return a;
        int n=max(a,b);
        for(int i=1;i<=n;i++){
            if(y==__builtin_popcount(a^i))return a^i;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends