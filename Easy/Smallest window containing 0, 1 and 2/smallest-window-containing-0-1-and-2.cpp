//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int smallestSubstring(string S) {
    int n = S.length();
    
    int count[3] = {0};
    int start = 0;
    int minLength = INT_MAX;
    
    for (int end = 0; end < n; ++end) {
        count[S[end] - '0']++;
        
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            minLength = min(minLength, end - start + 1);
            count[S[start] - '0']--;
            start++;
        }
    }
    
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