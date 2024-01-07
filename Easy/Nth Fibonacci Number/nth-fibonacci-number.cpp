//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        int mod=1000000007;
        int c;
        if(n<2){
            return 1;
        }
        int a=0;
        int b=1;
        for(int i=1;i<n;i++){
            c=(a+b)%mod;
            a=b;
            b=c;
        }
        return c%mod;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends