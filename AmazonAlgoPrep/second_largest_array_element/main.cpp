#include <iostream>
using namespace std;
int solution(vector<int> arr)
{

    // Solution - traverse the array. if arr[i] >  current_max => second_largest = current_max and
    // current_max = arr[i] else if(arr[i] >second_largest & != largest){ second_largest = arr[i]}
    int second_largest = 0;
    int largest = 0;
    int smallest = 99999;
    int second_smallest = 99999;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < second_largest and arr[i] != largest)
        {
            second_largest = arr[i];
        }
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }
    }
    cout << "largest: " << largest << " " << second_largest << endl;
    cout << "smallest: " << smallest << " " << second_smallest << endl;

    return largest;
}
int main()
{
    std::vector<int> arr;

    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(5);
    solution(arr);
    return 0;
}