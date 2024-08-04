//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[r][c]=1;
        queue<pair<int,int>> q;
        q.push({r,c});
        
        int n=grid.size(), m=grid[0].size();
        
        while(!q.empty()){
            //extracting elements
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            //traversing the nbhs and mark them if it is a 1
            //delrow = delta row.....nbhrow = neighbour row
            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    int nbhrow = row+delrow;
                    int nbhcol = col + delcol;
                    if(nbhrow>=0 && nbhrow<n && nbhcol>=0 && nbhcol<m && grid[nbhrow][nbhcol]=='1' && !vis[nbhrow][nbhcol]){
                        vis[nbhrow][nbhcol]=1;
                        q.push({nbhrow, nbhcol});
                    }
                }
            }
            
        }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), c=0;
        if(n==0) return 0;
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    c++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends