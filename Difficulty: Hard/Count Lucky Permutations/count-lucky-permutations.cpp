//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    vector<vector<int>> E;

    long long func(long long i, long long n, long long val, long long prev,
                   vector<int>& arr, vector<vector<long long>>& dp) {
        if (i == n) return 1;
        long long ans = 0;
        if (dp[prev][val] != -1) return dp[prev][val];
        for (long long j = 0; j < n; j++) {
            if (!(val & (1 << j)) && (prev == 0 || E[arr[j]][prev])) {
                ans += func(i + 1, n, val | (1 << j), arr[j], arr, dp);
            }
        }
        return dp[prev][val] = ans;
    }

public:
    long long luckyPermutations(long long N, long long M, vector<int> &arr,
                                vector<vector<int>> &graph) {
        E = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
        vector<vector<long long>> dp(N + 1, vector<long long>((1 << N) + 1, -1ll));
        for (auto &x : graph) {
            E[x[0]][x[1]] = 1;
            E[x[1]][x[0]] = 1;
        }
        return func(0, N, 0, 0, arr, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    }
}

// } Driver Code Ends