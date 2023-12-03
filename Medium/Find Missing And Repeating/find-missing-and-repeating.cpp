//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> cntr(n+1,0);
        int B, A;
        
        for(int i = 0; i<n; ++i){
            cntr[arr[i]]++;
            if(cntr[arr[i]] ==2)
                B = arr[i];
        }
        
        for(int i = 1; i<=n; ++i)
            if(cntr[i] == 0)
                A = i;
                
        return {B,A};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends