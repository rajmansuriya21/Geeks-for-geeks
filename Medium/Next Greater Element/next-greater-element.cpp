//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
          stack<long long>st;
        vector<long long>ans;
        for(int i = n-1;i>=0;i--){
            if(st.size()==0){
                ans.push_back(-1);
            }else if(st.top() > arr[i]){
                ans.push_back(st.top());
            }else{
                while(st.size()){
                    if(st.top() > arr[i]){
                        ans.push_back(st.top());
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(st.size() == 0){
                    ans.push_back(-1);
                }
            }
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends