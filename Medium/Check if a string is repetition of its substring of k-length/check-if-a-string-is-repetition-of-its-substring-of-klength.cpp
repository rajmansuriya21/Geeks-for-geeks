//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n%k != 0)
	        return 0;
	       
	    set<string> st;
	    int i = 0;
	    
	    while(i < n) {
	        int j = i+k;
	        string temp = "";
	        for(int indx=i; indx<j; indx++) {
	            temp += s[indx];
	        }
	        st.insert(temp);
	        if(st.size() > 2)
	            return 0;
	            
	       i += k;
	    }
	    if(st.size() == 2 or st.size() == 1)
	        return 1;
	   
	    return 0;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends