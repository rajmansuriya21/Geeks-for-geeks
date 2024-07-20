//{ Driver Code Starts
                               //Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> ans;
    int dif=INT_MAX;
    void help(vector<int>&a,int target_size,int sum1,int sum2,int i,int ele){
        if(ele==target_size){
            if(abs(sum1-sum2)<dif){
                ans[0]={sum1};
                ans[1]={sum2};
                dif=abs(sum1-sum2);
            }
            return;
        }
        if(i==a.size()) return;
        help(a,target_size,sum1,sum2,i+1,ele);
        help(a,target_size,sum1+a[i],sum2-a[i],i+1,ele+1);
    }
    
    vector<vector<int>> minDifference(vector<int>& arr, int n){

        int size=0;
        if(n%2==0) size=n/2;
        else{
            size=(n+1)/2;
        }
        int sum=0;
        ans.push_back({0});
        ans.push_back({0});
        for(int i=0;i<n;i++) sum+=arr[i];
        help(arr,size,0,sum,0,0);
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        vector<vector<int>> ans = obj.minDifference(arr,n);
        
        long long s1=0, s2=0;

        for(int i=0;i<ans[0].size();i++) s1+=ans[0][i];
        for(int i=0;i<ans[1].size();i++) s2+=ans[1][i];
        
        if(s1>s2) swap(s1,s2);

        cout<<s1<<"\n"<<s2<<"\n";
    }
}
                               
// } Driver Code Ends