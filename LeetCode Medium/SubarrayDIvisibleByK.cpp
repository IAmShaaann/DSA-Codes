#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> arr , int k){
    int n= arr.size();
    map<int, int> hmap;
    hmap[0] = 1;
    int ps = 0, ans = 0;
    for(int i =0;i<arr.size();i++){
        cout<<"round: "<<i<<" ";
        ps += arr[i];
        cout<<"preSum: "<< ps<<" "; 
        int rem = ps % k;
        cout<<"Rem: "<<rem<<" ";
        if(rem < 0){
            cout<<"Negative"<<" ";
            rem += k;
        }
        ans += hmap[rem];
        cout<<"ans: "<< ans<<endl;
        hmap[rem]++;
        // cout<<"Hmap Values: "<<hmap[rem]->first<<" "<<hmap[rem]->second<<end;
    }
    cout<<ans;
    return ans;

}
int main()
{
    vector<int> arr = {4,5,0,-2,-3,1};
    solution(arr,5);
}