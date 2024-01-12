//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    queue<int> modifyQueue(queue<int> q, int k) {
         vector<int> element;
       
        for(int i=0;i<k;i++){
            element.push_back(q.front());
            q.pop();
        }
        for(int i=k-1;i>=0;i--){
            q.push(element[i]);
        }
        for(int i=k;i<q.size();i++){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        
        return q;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends