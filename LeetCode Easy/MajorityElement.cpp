/*
Question: Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> arr){
    unordered_map<int , int> map;
    for(int i =0;i<arr.size();i++){
        map[arr[i]]++;
    }
    unordered_map<int, int> :: iterator it;
    for(it = map.begin(); it!= map.end();it++){
        if(it->second  >= arr.size() / 2){
            return it->first;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = { 1,2,3,2,3,4,3,3,2};
    cout<<solution(arr);
    return 0;
}