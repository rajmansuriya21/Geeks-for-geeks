//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int start=0, end=0;
        int sum=arr[0];
        vector<int> ans;
        while (start<n && end<n)
        {
            if (sum==s) {
                ans.push_back(start+1);
                ans.push_back(end+1);
                return ans;
            }
            else if (sum>s)
            {
                if (sum==arr[start]) {
                    start++;
                    end++;
                    sum = arr[start];
                    continue;
                }
                sum -= arr[start];
                start++;
            }
            else if (sum<s)
            {
                if (end==n-1) {
                    break;
                }
                end++;
                sum += arr[end];
            }
        }
        ans.push_back(-1);
        return ans;
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends