//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        
       vector<int>v;
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            //int a=0;
            if(arr[i]==arr[i+1] && arr[i+1]!=arr[i+2])
            {
                v.push_back(arr[i]);
            }
        }
        if(v.size()==0)
            v.push_back(-1);
        return v;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends