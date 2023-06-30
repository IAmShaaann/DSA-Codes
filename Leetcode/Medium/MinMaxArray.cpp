#include<bits/stdc++.h>
using namespace std;
void solution(vector<int> arr){
    int min = INT_MAX, max = INT_MIN;
    for(int i =0;i<arr.size();i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] > max ){
            max = arr[i];
        }
    }
    cout<<min<<" "<<max<<endl;
}
int main(){
    vector<int> arr = { 1,2,3,4,5,6};
    solution(arr);
    return 0;
}