#include<bits/stdc++.h>
using namespace std; 
vector<int> solution(vector<int> arr){ //solution with extra space.
    vector<int> res;
    for(int i = arr.size()-1 ;i>= 0;i--){
        res.push_back(arr[i]);
    }
   
    return res;
}
vector<int> solution2(vector<int> arr, int start, int end){ //solution without extra space.
    while(start<end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    return arr;

}
int main(){
    vector<int> arr = {3,4,5,6,7,8};
    vector<int> result = solution(arr);
    vector<int> soolution2Result = solution2(arr, 0, arr.size()-1)
    for(auto it: soolution2Result){
        cout<<it<<endl;
    }
    return 0;
}