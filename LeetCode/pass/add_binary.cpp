/*************************************************************************
  > File Name: add_binary.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 03:44:12 PM PDT
  > 解题思路:这题跟Add Two Numbers相似，两个指针，注意进位即可 
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        size_t a_index = a.size(),b_index = b.size();
        while(a_index!=0||b_index!=0){
            int tmp = (a_index==0?'0':a[--a_index])-'0'+(b_index==0?'0':b[--b_index])-'0'+carry;
            carry = tmp/2;
            tmp = tmp%2;
            res.insert(res.begin(),static_cast<char>(tmp+'0')); 
        }
        if(carry>0)
            res.insert(res.begin(),static_cast<char>(carry+'0')); 
        return res;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    cout<<s.addBinary("11","1")<<endl;
    return 0;
}
