// Question: Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include<bits/stdc++.h>
using namespace std;
int solution(string str, string word){
    for(int i =0 ;i<str.size();i++){
        if(str[i] == word[0]){
            if(str.substr(i, word.size()) == word){
                return i;
            }
        }
    }
    return -1;
}

int main(){
    string str = "hello", word= "ll";
    cout<<solution(str, word);
    return 0;
}