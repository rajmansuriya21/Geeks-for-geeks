//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++)
        {
            int low = 0;
            int high = n - 1;
            int pair = (arr[i] + x);
            
            while (low <= high) {
                int mid = low + (high - low) / 2;
                // cout << arr[mid] << ' ';
                // Check if x is present at mid
                if (arr[mid] == pair && mid != i)
                    return 1;
        
                // If x greater, ignore left half
                if (arr[mid] < pair)
                    low = mid + 1;
        
                // If x is smaller, ignore right half
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends