//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int>& v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root) {
    vector<int> v;
    queue<Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();

        if (n == next_row) {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left) {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right) {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node* createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        unordered_map<int,vector<int>>tree;
        int mainParent=-1;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==-1)mainParent=i;
            else tree[parent[i]].push_back(i);
        }
        
        // cout<<mainParent<<" ";
        Node* root=new Node(mainParent);
        queue<Node*>qu;
        qu.push(root);
         Node* temp=root;
         while(!qu.empty()){
            Node* tp = qu.front();
            qu.pop();
            int lft,rgt;
            if(tree[tp->data].size()==0)lft=-1,rgt=-1;
            else if(tree[tp->data].size()==1)lft=tree[tp->data][0],rgt=-1;
            else{
                if(tree[tp->data][0]<tree[tp->data][1]){
                 lft=tree[tp->data][0];
                 rgt=tree[tp->data][1];
                }
                else{
                lft=tree[tp->data][1];
                 rgt=tree[tp->data][0];
                }
         }
         if(lft!=-1)tp->left=new Node(lft),qu.push(tp->left);
         if(rgt!=-1)tp->right=new Node(rgt),qu.push(tp->right);
    }
        return root;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        Solution ob;

        Node* res = ob.createTree(a);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends