//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int findCoverage(vector<vector<int>>& matrix) {
        int m = matrix.size();  // number of rows
        int n = matrix[0].size();  // number of columns
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // Check neighbors
                    if (i - 1 >= 0 && matrix[i-1][j] == 1) result++;  // top
                    if (j - 1 >= 0 && matrix[i][j-1] == 1) result++;  // left
                    if (i + 1 < m && matrix[i+1][j] == 1) result++;  // bottom
                    if (j + 1 < n && matrix[i][j+1] == 1) result++;  // right
                }
            }
        }
        return result;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends