//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
    public:
    class Node{
        public:
        int key, val;
        Node *next, *prev;
        Node (int KEY, int VAL) {
            key=KEY; val=VAL;
        }
    };
    int cap;
    unordered_map<int, Node*> mp;
    Node *head=new Node(-1, -1);
    Node *tail=new Node(-1, -1);
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node *newNode) {
        Node *temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node *delNode) {
        Node *delPrev=delNode->prev;
        Node *delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    //Function to return value corresponding to the key.
    int GET(int key) {
        if(mp.find(key) != mp.end()) {
            Node *resNode=mp[key];
            int res=resNode->val;
            
            mp.erase(key);
            deleteNode(resNode);
            
            addNode(resNode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node *existingNode=mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(mp.size() == cap) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key]=head->next;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends