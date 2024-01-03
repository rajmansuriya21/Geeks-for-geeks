//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int smallestSubstring(string S) {
    int n = S.length();
    
    int count[3] = {0}; // To store the count of 0, 1, and 2 in the current window
    int start = 0; // Start index of the window
    int minLength = INT_MAX; // Initialize the minimum length to a large value
    
    for (int end = 0; end < n; ++end) {
        // Update count for the current character in the window
        count[S[end] - '0']++;
        
        // Try to minimize the window by moving the start index
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            // Update minLength
            minLength = min(minLength, end - start + 1);
            
            // Move the start index and update count accordingly
            count[S[start] - '0']--;
            start++;
        }
    }
    
    // If minLength is still INT_MAX, no valid substring found
    return (minLength == INT_MAX) ? -1 : minLength;
 }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends