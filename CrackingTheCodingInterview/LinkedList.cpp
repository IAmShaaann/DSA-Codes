#include <bits/stdc++.h>
using namespace std;
// A Linked List Node
class Node
{
  public:
    int data;        // data field
    Node* next;     // pointer to the next node
}; 

Node* newNode(int key, Node* next)
{
    // allocate a new node in a heap and set its data
    Node* node = new Node;
    node->data = key;
 
    // set the `.next` pointer of the new node to point to the current
    // first node of the list.
    node->next = next;
 
    return node;
}
 
// Function for linked list implementation from a given set of keys
Node* constructList(vector<int> const &keys)
{
    Node* head, *node = nullptr;
 
    // start from the end of the array
    for (int i = keys.size() - 1; i >= 0; i--)
    {
        node = newNode(keys[i], node);
        head = node;
    }
 
    return head;
}

// Naive Method:
// Node* linkedListNaive()
// {
//     // construct three linked list nodes
//     Node* first = newNode(1);
//     Node* second = newNode(2);
//     Node* third = newNode(3);
 
//     // rearrange the pointers to construct a list
//     Node* head = first;
//     first->next = second;
//     second->next = third;
 
//     // return a pointer to the first node in the list
//     return head;
// }
 

void printList(Node* head)
{
    Node* current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << " NULL " << endl;

}
int kthToLast(Node* head, int k){
    int count = 0;
    Node* current = head;
    while(current){
        cout<<"Current: "<<current->data<<endl;
        count++;
        current = current->next;
    }
    cout<<"Size: "<<count<<endl;
    int kthElement = count - k;
    current = head;
    while(kthElement--){
        current = current->next;
    } 
    cout<<"Kth to last element: "<<current ->data<<endl;
    return current->data;
}
int main()

{
    Node* head = new Node();;
    vector<int> arr = {10,22,33,55,44,66,77,88,99,44};
    head = constructList(arr);
    printList(head);
    int res = kthToLast(head, 2);
    cout<<"Kth to last element is: "<<res;


    

    return 0;
}