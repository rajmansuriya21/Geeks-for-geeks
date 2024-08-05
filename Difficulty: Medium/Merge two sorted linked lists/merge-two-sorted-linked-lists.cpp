//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}


// } Driver Code Ends


/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to merge two sorted linked list.
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2)  
{  
    
    
    Node* newnode = new Node(0);// parameterised constructor cannot be an empty value 
    Node* head = newnode;
    Node* tail = newnode;
    newnode->next=nullptr;
    
    Node* c1 =  head1;
    Node* c2 = head2;
    
    
    
    while(c1!=nullptr && c2!=nullptr){ //loop terminates as soon as one pointer reaches null t and f == f
        if (c1->data <= c2->data){
            tail->next=c1;
            //tail->next->data=c1->data;// useless
            //tail aage badana padega kyuki agar tail aage nahi movr karaoge toh tail->next ki node ki value hamesha
            //rahegi aur static rahega tail
            c1=c1->next;
            }
            // agar lag rha hai ki saare equal wale case cover ho rhe ki nhi tension mat lp
            //woh bhi cover ho rhe hai 
            //for eg 2 10 30 40 , 2 10 30 40 
            
        else if (c1->data > c2->data){
            tail->next=c2;
            c2=c2->next;
        }
        tail=tail->next;
        }
        
        
        if(c1!=nullptr){
            tail->next=c1; //relink the bachi hui ll after loop sorted
        }
        
        if(c2!=nullptr){
            tail->next=c2;
        }
    
    
    head=newnode->next;
    delete newnode;// garbage value ko hatao 
    return head;
    
    

}


};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends