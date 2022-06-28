#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    { // Default constructor
        data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    void push(int data);
    void print();
    void remove(int data);
    void removeDuplicates();
};
void LinkedList::push(int data)
{
    Node *newNode = new Node(data);
    // if first node:
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void LinkedList::remove(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int ListLen = 0;

    if (head == NULL)
    {
        cout << "List empty." << endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be
    // deleted is less than the length
    // of the linked list.
    if (ListLen < nodeOffset)
    {
        cout << "Index out of range"
             << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Deleting the head.
    if (nodeOffset == 1)
    {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1)
    {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}
void LinkedList::print()
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "End" << endl;
}

void LinkedList::removeDuplicates ()

{
    cout<<"Called"<<endl;

    unordered_map<int, int> map;
    Node *current = head;
    int index = 0;
    while (current != nullptr)
    {
        cout<<"IN while loop: "<<endl;
        map[current->data]++;
        if (map[current->data] > 1)
        {
            current->next = current->next->next;
            index++;
        }
        current = current->next;
        index++;
    }
    for(auto it: map){
        cout<<it.first<<" "<<it.second<<endl;
    }
    // list->print();
}

int main()
{
    vector<int> arr = {20, 34, 52, 11, 74, 11, 34, 85, 45, 65, 85};
    LinkedList* list;
    for (int i = 0; i < arr.size(); i++)
    {
        list->push(arr[i]);
    }
    list->print();
    list->removeDuplicates();
    return 0;
}