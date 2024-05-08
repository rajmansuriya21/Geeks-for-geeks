//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
private:
    int binarySearch(const vector<int>& binaryVector, int target) {
        int left = 0, right = binaryVector.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (binaryVector[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

public:
    vector<int> constructLowerArray(int *arr, int n) {
        vector<int> ans(n), temp(arr, arr + n);
        sort(temp.begin(), temp.end());

        for (int i = 0; i < n; ++i) {
            int index = binarySearch(temp, arr[i]);

            ans[i] = index;
            temp.erase(temp.begin() + index);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends