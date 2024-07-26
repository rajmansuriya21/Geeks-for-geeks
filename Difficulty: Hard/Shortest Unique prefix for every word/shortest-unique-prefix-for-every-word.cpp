//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Node{
public:
    Node* links[26];
    int cntPrefix = 0;
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(auto i:word){
            if(!node->links[i-'a'])
                node->links[i-'a'] = new Node();
            node = node->links[i-'a'];
            node->cntPrefix++;
        }
    }
    int check(string word){
        Node* node = root;
        for(int i = 0;i < word.size();i++){
            node = node->links[word[i]-'a'];
            if(node->cntPrefix == 1) return i+1;
        }
        return 0;
    }
};
class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n){
        Trie node;
        for(int i = 0;i < n;i++)
            node.insert(arr[i]);
        vector <string> ans;
        for(int i = 0;i < n;i++)
            ans.push_back(arr[i].substr(0,node.check(arr[i])));
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends