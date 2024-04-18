//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{

public:
    void solve(unordered_map<Node*,Node*>&par,Node* p,Node*root){
        par[root]=p;
        if(root->left) solve(par,root,root->left);
        if(root->right) solve(par,root,root->right);
    }
    Node*fun(Node*root,int t){
        if(root==NULL) return root;
        if(root->data==t) return root;
        Node*l=fun(root->left,t);
        Node*r=fun(root->right,t);
        if(l) return l;
        return r;
    }
    void f1(Node*t,int k,vector<int>&ans){
        if(k<0) return;
        if(k==0){
            ans.push_back(t->data);
            return;
        }
        if(t->left) f1(t->left,k-1,ans);
        if(t->right) f1(t->right,k-1,ans);
    }
    void f2(Node*t,Node*check,int k,vector<int>&ans){
        if(k<0) return;
        if(k==0){
            ans.push_back(t->data);
            return;
        }
        if(t->left&&t->left!=check) f2(t->left,NULL,k-1,ans);
        if(t->right&&t->right!=check) f2(t->right,NULL,k-1,ans);
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        unordered_map<Node*,Node*>par;
        solve(par,NULL,root);
        Node*t=fun(root,target);
        vector<int>ans;
        f1(t,k,ans);
        while(par[t]&&k){
            Node*tem=par[t];
            f2(tem,t,k-1,ans);
            k--;
            t=tem;
        }
        sort(ans.begin(),ans.end());
        return ans;
        // return the sorted vector of all nodes at k dist
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends