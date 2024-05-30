//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> a, int n) {
        long long int asum = 1ll*n * (n + 1) / 2;
        long long int asumsqr = 1ll*n * (n + 1) * (2 * n + 1) / 6;
    
        long long int sum = 0, sumsqr = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            sumsqr += 1ll*a[i] * a[i];
        }
    
        int sub = sum - asum;//b - a
        int add = (sumsqr - asumsqr) / sub;//b + a
        return {(add + sub) / 2, (add - sub) / 2};
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