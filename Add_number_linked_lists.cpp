//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node *head1 = NULL;
        Node *head2 = NULL;
        Node *temp1 = num1;
        Node *temp2 = num2;
        
        while(temp1!=NULL){
            Node *newnode = new Node(temp1->data);
            newnode->next = head1;
            head1 = newnode;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            Node *newnode = new Node(temp2->data);
            newnode->next = head2;
            head2 = newnode;
            temp2 = temp2->next;
        }
        int carry = 0;
        temp1 = head1;
        temp2 = head2;
        int res,s;
        Node *head = NULL;
        while(temp1!=NULL && temp2!=NULL){
            s = temp1->data + temp2->data + carry;
            res = s%10;
            carry = s/10;
            Node *node = new Node(res);
            node->next = head;
            head = node;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL){
            s = temp1->data + carry;
            res = s%10;
            carry = s/10;
            Node *node = new Node(res);
            node->next = head;
            head = node;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            s = temp2->data + carry;
            res = s%10;
            carry = s/10;
            Node *node = new Node(res);
            node->next = head;
            head = node;
            temp2 = temp2->next;
        }
        if(carry!=0){
            Node *node = new Node(carry);
            node->next = head;
            head = node;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
