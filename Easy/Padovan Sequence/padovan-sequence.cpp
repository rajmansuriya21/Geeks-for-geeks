//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
     int mod = 1e9+7;
    int a = 1, b= 1 , c = 1;
    for(int i=3; i<=n; i++){
        int ans = (a+b) % mod;
        a = b, b = c, c = ans;
    }
    return c;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends