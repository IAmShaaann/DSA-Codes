#include<bits/stdc++.h>
using namespace std;
vector<char> URLify(string str){
    int spaceCount = 0;
    for(auto it: str){
        if(it == 0){
            spaceCount++;
        }
    }
    int desiredStringSize = str.size() + (spaceCount * 2);
    // cout<<desiredStringSize;
    vector<char> newString;
    for(int i =0;i<str.size();i++){
        if(str[i] == ' '){
            newString.push_back('%');
            newString.push_back('2');
            newString.push_back('0');
        }else{
            newString.push_back(str[i]);
        }

    }
    return newString;
}

int main(){
    string str = "Mr john smith";
    vector<char> res;

    res = URLify(str);
    for(auto it: res){
        cout<<it;
    }
    return 0;
}