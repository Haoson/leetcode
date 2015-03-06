/*************************************************************************
  > File Name: implement_strstr.cpp
  > Author:Haoson 
  > Created Time: Fri 06 Mar 2015 03:05:11 AM PST
  > Description: 
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        size_t len_h = strlen(haystack);
        size_t len_n = strlen(needle);
        if(len_n==0)return 0;
        if(len_h<len_n)return -1;
        bool exist = true;
        for(size_t i=0;i<=(len_h-len_n);++i){
            exist = true;
            if(haystack[i]==needle[0]){
                for(size_t j=1;j<len_n;++j){
                    if(haystack[i+j]!=needle[j]){
                        exist=false; 
                        break;
                    } 
                } 
                if(exist)return static_cast<int>(i);
            } 
        }
        return -1;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    char h[] = "";
    char n[] = "";
    cout<<(s.strStr(h,n))<<endl;
    return 0;
}
