//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int dp[101][101][101];
    int fn(int i,int rem,int sum)
    {
        if(sum<0 || rem==0)
            return 0;
        
        if(i==0 && sum==0)
            return 1;
        
        if(i == 0 && sum != 0)
            return 0;

        if(dp[i][sum][rem]!=-1) return dp[i][sum][rem];

        return dp[i][sum][rem]=fn(i,rem-1,sum)+fn(i-1,rem,sum-rem);
    }
    
    int countWaystoDivide(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return fn(k,n,n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends