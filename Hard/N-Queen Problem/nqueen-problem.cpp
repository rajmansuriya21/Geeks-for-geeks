//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   vector<vector<int> > ans;
    bool canPlace(vector<vector<int> > &grid, int row, int col, int n){
        for(int i = row-1; i >= 0; i--){
            if(grid[i][col] > 0) return false;
        }
        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(grid[i][j] > 0) return false;
        }
        for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
            if(grid[i][j] > 0) return false;
        }
        return true;
    }
    
    void helper(vector<vector<int> > &grid,  vector<int> v, int row, int n){
        if(row == n){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] > 0) v[i] = grid[i][j];
                }
            }
            ans.push_back(v);
            return;
        }
        
        for(int col = 0; col < n; col++){
            if(canPlace(grid, row, col, n)){
                grid[row][col] += (col+1);
                helper(grid, v, row+1, n);
                grid[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> grid(n, vector<int> (n, 0));
        vector<int> v(n);
        helper(grid, v, 0, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends