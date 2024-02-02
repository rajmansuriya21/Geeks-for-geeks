//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int atoi(string s) {
        int num = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(i == 0 && s[i] == '-')
                continue;
                
            if(s[i] >= '0' && s[i] <= '9')
                num = (num * 10) + (s[i] - '0');
            else {
                return -1;
            }
        }
        
        if(s[0] == '-') {
            num *= -1;
        }
        
        return num;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends