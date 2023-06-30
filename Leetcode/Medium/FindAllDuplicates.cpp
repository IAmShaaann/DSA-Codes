#include<bits/stdc++.h>
using namespace std;
void solution (vector<int> arr){
    unordered_map<int, int> map;
    vector<int> ans;
    for(int i =0;i<arr.size();i++){
        map[arr[i]]++;
        if(map[arr[i] ]>1){
            ans.push_back(arr[i]);
        }

    }
    for(auto it: ans){
        cout<<it<<" "; 
    }
}
int main(){
    vector<int> arr = {4,3,2,7,8,2,3,1};
    solution(arr);
    return 0;
}
