//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    string longestPalin(string S) {
        int start = 0, maxLength = 1, len = S.length();
        
        // Helper function to expand around center for odd length palindromes
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < len && S[left] == S[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < len; ++i) {
            // Expand around center for odd length palindromes
            expandAroundCenter(i, i);
            
            // Expand around center for even length palindromes
            expandAroundCenter(i, i + 1);
        }

        return S.substr(start, maxLength);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends