//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	string FirstNonRepeating(string A){
            int size = A.length();
            unordered_map<char, int> mp;
            queue<char> q;
            string res ="";
            for(int i =0;i<size;i++){
                char ch = A[i];
                mp[ch]++;
                q.push(ch);
                
                while(!q.empty()){
                    if(mp[q.front()] > 1){
                        q.pop();
                    }
                    else{
                        res.push_back(q.front());
                        break;
                    }
                }
                
                if(q.empty()){
                    res.push_back('#');
                }
                
                
            }
            
            return res;
        }



};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends