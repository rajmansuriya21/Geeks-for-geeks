//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   int check(vector<vector<int>> &mat,int r,int mid)
    {
        int count=0;
            for(int i=0;i<r;i++)
            {
                count+=lower_bound(mat[i].begin(), mat[i].end(), mid)-mat[i].begin();
            }
            return count;
    }

    int median(vector<vector<int>> &mat, int r, int c){
                  
        int low=0,high=INT_MAX;
        int split=((r*c)+1)/2;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int val=check(mat,r,mid);
            if(val<split)
            low=mid+1;
            else
            high=mid-1;
        }
        return high;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends