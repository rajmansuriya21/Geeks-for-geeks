//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    void solve(int ind, vector<int> arr, vector<vector<int>> &ans, vector<int> &v, int target){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        if(ind == arr.size() || target < 0)  return;
        v.push_back(arr[ind]);
        solve(ind + 1, arr, ans, v, target - arr[ind]);
        v.pop_back();
        while (ind + 1 < arr.size() && arr[ind] == arr[ind + 1]) {
            ++ind;
        }
        solve(ind + 1, arr, ans, v, target);
    }
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> v;
        sort(arr.begin(), arr.end());
        solve(0, arr, ans, v, k);
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends