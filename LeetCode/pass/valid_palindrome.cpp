/*************************************************************************
  > File Name: valid_palindrome.cpp
  > Author:Haoson 
  > Created Time: Sun 08 Mar 2015 04:41:28 PM PDT
  > 解题思路:两个指针 
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

class Solution {
    public:
    bool isPalindrome(string s) {
        size_t len = s.length();
        if(len<=1)return true;
        size_t head_index = 0;
        size_t tail_index = len-1;
        while(head_index<tail_index){
            while(!isalnum(s[head_index])&&head_index<tail_index)++head_index;
            while(!isalnum(s[tail_index])&&head_index<tail_index)--tail_index;
            if(head_index>=tail_index)break;
            if(tolower(s[head_index++])!=tolower(s[tail_index--]))return false;
        }
        return true;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    cout<<(s.isPalindrome(" A man, a plan, a canal: Panama")?"true":"false")<<endl;
    return 0;
}
