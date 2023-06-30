/*
Question: Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Solution: take 3 pointer 1 for start, 1 for end, 1 for traversal, as there are just 3 types of element, if(arr[traversal] == 0 ){
    swap it with arr[start++], traversal++
}as it will place all the 0s at the start. 
else if(arr[traversal] == 2){
    swap it with arr[end--] 
}as it will place all the 2s at the end. 
else{ for the once we just increment the traversal. }
because, if 2 types of elements are at there correct place then the 3rd will all be at it's correct place.
*/


#include <bits/stdc++.h>
using namespace std;
void solution(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ptr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[ptr] == 0)
        {
            swap(arr[low], arr[ptr]);
            low++;
            ptr++;
        }

        else if (arr[ptr] == 2)
        {
            swap(arr[ptr], arr[high]);
            high--;
        }
        else
        {
            ptr++;
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
}

int main()
{
    vector<int> arr = {1, 0, 2, 0, 1, 2};

    return 0;
}