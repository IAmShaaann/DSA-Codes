#include <bits/stdc++.h>
using namespace std;
// A Linked List Node
class Node
{
public:
    int data;   // data field
    Node *next; // pointer to the next node
};

Node *newNode(int key, Node *next)
{
    // allocate a new node in a heap and set its data
    Node *node = new Node;
    node->data = key;

    // set the `.next` pointer of the new node to point to the current
    // first node of the list.
    node->next = next;

    return node;
}

// Function for linked list implementation from a given set of keys
Node *constructList(vector<int> const &keys)
{
    Node *head, *node = nullptr;

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

void printList(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << " NULL " << endl;
}

// Question: Given a K return Kth to last element.
int kthToLast(Node *head, int k)
{
    int count = 0;
    Node *current = head;
    while (current)
    {
        cout << "Current: " << current->data << endl;
        count++;
        current = current->next;
    }
    cout << "Size: " << count << endl;
    int kthElement = count - k;
    current = head;
    while (kthElement--)
    {
        current = current->next;
    }
    cout << "Kth to last element: " << current->data << endl;
    return current->data;
}
Node *deleteMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    cout << "Fast Ptr: " << fast->next << endl;

    while (fast == NULL || fast->next == NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
    slow->next = slow->next->next;
    return head;
}

Node *pushStart(Node *head, int data)
{
    Node* node = new Node();
    node->data = data;
    node->next = head;
    // node = head;
    return node;
}

Node *pushEnd(Node *head, int data)
{
    Node* node = new Node();
    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    node->data = data;
    current ->next = node;
    return head;
}

// Node* partition(Node* head, int x){
//     Node* current = head;
//     Node* newList = new Node();
//     while(current!= nullptr){
//         if(current->data >= x){
//             newList = pushEnd(newList, current->data);
//         }else{
//             newList = pushStart(newList, current->data);
//         }
//     }
//     printList(newList); 
//     return newList;
// }
Node* sumList(int Num1, int Num2, Node* head){
    int total = Num1+ Num2;
    vector<int> arr;
    while(total){
        int last = total % 10;
        arr.push_back(last);
        total /= 10;
    }
    reverse(arr.begin() , arr.end());
    head = constructList(arr);
    return head;
}
int main()


{
    Node *head = new Node();
    vector<int> arr = {10, 22, 33, 55, 44, 66, 77, 88, 99, 44};
    head = constructList(arr);
    printList(head);
    // cout<<head->data;
    // int res = kthToLast(head, 2);
    // cout<<"Kth to last element is: "<<res;
    // head = pushStart(head, 69);
    // head = pushEnd(head, 66);

    head = sumList(134, 345, head);
    printList(head);

    return 0;
}