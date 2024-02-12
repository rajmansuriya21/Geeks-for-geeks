//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    long long sequence(int n){
        {
    int mod = 1000000007;
    long long ans = 0;
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        long long add = 1;
        for (int j = 0; j < i; j++)
        {
            add = (add * start) % mod;
            start++;
        }
        ans = (ans + add) % mod;
      }
    return ans;
     }
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends