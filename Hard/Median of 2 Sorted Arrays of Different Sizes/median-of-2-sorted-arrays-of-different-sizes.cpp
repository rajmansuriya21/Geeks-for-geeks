//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {   
        vector<int>answer;  
        int m = array1.size(), n = array2.size();
        int i = 0, j = 0;
        while(i<m && j<n){
            if(array1[i] < array2[j]){
                answer.push_back(array1[i++]);  
            }
            else{
                answer.push_back(array2[j++]);
            }
        }
        while(i<m){
            answer.push_back(array1[i++]);
        }
        while(j<n){
            answer.push_back(array2[j++]);
        }
        int Size = m+n;
        if(Size % 2 == 1 ){
            return answer[Size/2];
        }
        else{
            int ans1 = answer[Size/2];
            int ans2 = answer[Size/2 - 1];
            return (ans1+ans2)/2.0;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends