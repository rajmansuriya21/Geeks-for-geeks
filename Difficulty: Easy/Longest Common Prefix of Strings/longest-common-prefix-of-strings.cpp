//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        string str="";
        
        int mini=INT_MAX;
        
        for(auto it:arr){
            if(it.size()<mini){
                str=it;
                mini=it.size();
            }
        }
        
        for(auto it:arr){
            for(int i=0;i<mini;i++){
                if(it[i]!=str[i]){
                    mini=i;
                    break;
                }
            }
        }
        
        if(mini==0)return "-1";
        
        return str.substr(0,mini);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends