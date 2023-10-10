#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void insert(int data)
    {
        Node *new_node = new Node(data);
        if (head == nullptr)
        { // the first element of the list.
            head = new_node;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                // reached the end of the list.
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int remove(int data)
    {
        Node *current = head;
        Node *previous = nullptr;

        while (current->data != data)
        {
            previous = current;
            current = current->next;
        }
        if (previous != nullptr)
        {
            previous->next = current->next;
        }
        else
        {
            head = current->next;
        }
        delete current;
    }
    void remove_duplicates()
    {
        unordered_map<int, int> map;
        Node *previous = nullptr;
        Node *current = head;
        while (current != nullptr) // time_complexity - O(L) space_complexity - O(L) = L = Size of the linkedlist.
        {
            if (map.find(current->data) != map.end()) // data_found.
            {
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
            else
            { // data_not_found.
                map[current->data]++;
                previous = current;
                current = current->next;
            }
        }
    }
    int kth_last_element(int k)
    {
        Node *fast = head;
        Node *slow = head;
        for (int i = 0; i <= k; i++)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
    void partition(int X)
    {
        Node *beforeStart = nullptr;
        Node *beforeEnd = nullptr;
        Node *afterStart = nullptr;
        Node *afterEnd = nullptr;
        Node *current = head;
        while (current->next != nullptr)
        {
            Node *new_node = new Node(current->data);
            if (current->data <= X)
            {
                if (beforeStart == nullptr)
                {
                    beforeStart = new_node;
                    beforeEnd = beforeStart;
                }
                else
                {
                    beforeEnd->next = new_node;
                    beforeEnd = new_node;
                }
            }
            else
            {
                if (afterStart == nullptr)
                {
                    afterStart = new_node;
                    afterEnd = afterStart;
                }
                else
                {
                    afterEnd->next = new_node;
                    afterEnd = new_node;
                }
            }
            current = current->next;
        }

        beforeEnd->next = afterStart;

        head = beforeStart;
    }
    bool intersection(Node *l1, Node *l2)
    {

        while (l1->next != nullptr || l2->next != nullptr)
        {

            if (l1->next == l2->next)
            {
                return true;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return false;
    }
};

int main()
{
<<<<<<< HEAD
    // int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 29, 34, 21, 98, 87, 76, 65, 54, 43, 32, 21, 13, 14}; // Use square brackets for array initialization
    // for (int i = 0; i <= sizeof(arr) / sizeof(arr[0]); i++) // Use sizeof to get the size of the array
    // {
    //     list->insert(arr[i]);
    // }
    // list->display();
    // list->remove(12);
    // list->display();
    // list->remove_duplicates();
    // list->display();
    // cout << "Kth to last: " << list->kth_last_element(3);
    // list->partition(54);
    // list->display();

    LinkedList *list = new LinkedList();

    Node *list_one = new Node(3);
    list_one->next = new Node(1);
    list_one->next->next = new Node(5);
    list_one->next->next->next = new Node(9);
    list_one->next->next->next->next = new Node(7);

    Node *list_two = new Node(4);
    list_two->next = new Node(6);
    list_two->next->next = new Node(list_one->next->next->data);
    list_two->next->next->next = new Node(2);
    list_two->next->next->next->next = new Node(1);

    // LinkedList *res = list->sum_list(list_one, list_two);
    // res->display();
    cout << list->intersection(list_one, list_two);
=======
    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 29, 34, 21, 98, 87, 76, 65, 54, 43, 32, 21, 13, 14}; // Use square brackets for array initialization
    LinkedList *list = new LinkedList();
    for (int i = 0; i <= sizeof(arr) / sizeof(arr[0]); i++) // Use sizeof to get the size of the array
    {
        list->insert(arr[i]);
    }
    // list->display();
    // list->remove(12);
    list->display();
    // list->remove_duplicates();
    // list->display();
    // cout << "Kth to last: " << list->kth_last_element(3);
    list->partition(54);
    list->display();
>>>>>>> de953fa (Day 5 - 100 Days of DSA)

    return 0;
}