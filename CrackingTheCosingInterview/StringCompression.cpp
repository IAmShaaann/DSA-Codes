#include<bits/stdc++.h>
using namespace std;
string strCompression(string str){
    string newString = "";
    int count = 0;
    for(int i =0;i<str.size();i++){
        count++;
        if(str[i] != str[i+1]){
            newString+= str[i]+ to_string(count);
            count = 0;
        }
    }
    return newString.size() > str.size() ? str : newString;

}
// Note: There can be another HashMap approach, where you maintain a freq hashmap, and based upon map.first and map.second you create a new string. 

int main(){
    string str = "aabcccccaaa";
    cout<<strCompression(str);
    return 0;
}