//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++



class node{
    public:
    node*child[3]={NULL};
    int first;
};
class Solution{   
public:

    void insert(int val,node*root){
        node*res=root;
        for(int i=21;i>=0;i--){
            int cnt=0;
            if((val^(1<<i))>=val)cnt=1;
            if(res->child[cnt]==NULL){
               res->child[cnt]=new node();
            }
            res=res->child[cnt];
        }
    }
    
    
    int cal(int val,node*root){
        node*res=root;
        int total=0;
        for(int i=21;i>=0;i--){
            int cnt=0;
            if((val^(1<<i))>=val) cnt=1;
            int find=0;
            if(cnt==0) find=1;
            if(res->child[find]==NULL){
                if(res->child[cnt]==NULL){
                    return total;
                }
                else{
                    res=res->child[cnt];
                }
            }
            else{
                total=(total^(1<<i));
                res=res->child[find];
                
            }
        }
        return total;
    }
    int maxSubarrayXOR(int N, int arr[]){ 
         node*root=new node();
         vector<int>v;
         int  total=0;
         int mx=0;
         v.push_back(0);
         for(int i=0;i<N;i++){
             total=(total^(arr[i]));
             v.push_back(total);
         }
         
         int id=N-1;
         for(int i=N;i>0;i--){
             int val=v[i];
             insert(val,root);
             
             int find=v[id];
             int ans=cal(find,root);
             mx=max(mx,(ans));
             id-=1;
             
         }
                  return mx;
         }

};
 

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends