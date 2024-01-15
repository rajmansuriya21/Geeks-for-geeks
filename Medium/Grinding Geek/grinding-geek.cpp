//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<int> next(total + 1), curr(total + 1);
        
        for(int i = n - 1; i >= 0; i--) 
        {
            for(int j = 0; j <= total; j++) 
            {
                int notPick = next[j];
                int pick = 0;
                
                if(cost[i] <= j)
                    pick = 1 + next[j - cost[i] + (0.9 * cost[i])];
                
                curr[j] = max(pick, notPick);
            }
            
            next = curr;
        }
        
        return curr[total];
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
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends