#include<bits/stdc++.h>
using namespace std;
void solutionBrute(vector<int> arr){
    vector<int> ans;
    for(auto it: arr){
        if(it != 0){
            ans.push_back(it);
        }
    }
    int remain = arr.size() - ans.size();
    while(remain--){
        ans.push_back(0);
    }
    for(auto it: ans){
        cout<<it<<" "; 
    }
}
void solution(vector<int>& arr){
    int p = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] != 0){
            arr[p] = arr[i];
            p++;
        }
    }
    for(int i = p;i<arr.size();i++){
        arr[i] = 0 ;
    }
    for(auto it: arr){
        cout<<it<<" ";    }

}
int main(){
    vector<int> arr = {0,1,0,3,12};
    solution(arr);
    return 0;
}