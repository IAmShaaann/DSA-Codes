// Question: Write an efficient program to print all the duplicates and their counts in the input string 

#include<bits/stdc++.h>
using namespace std;
void solution(string str){
    unordered_map<char, int> map;
    for(int i =0;i<str.size();i++){
        map[str[i]]++;
    }
    for(auto it: map){
        if(it.second > 1){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}
int main(){
    string str = "HelloThereHowareyou";
    solution(str);
    return 0;
}