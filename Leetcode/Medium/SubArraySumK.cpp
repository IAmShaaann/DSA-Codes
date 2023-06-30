/*
Question: Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/


#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> arr, int k){
    
    unordered_map<int,int> map;
    int sum = 0;
    int count = 0;
    map[sum] = 1;
    
    if(arr.size() == 1 and arr[0] == k){
        return 1;
    }

    for(int i = 0;i<arr.size();i++){
        sum += arr[i];
        if(map.find(sum - k) != map.end()){

            count += map[sum-k];
        }
        map[sum]++;
    }
    
    return count;
}
int main(){
    vector<int> arr = {3,9,-2,4,1,-7,2,6,-5,8,-3,-7,6,2,1};
    int k = 5;
    cout<<solution(arr,k);
    return 0;
}
