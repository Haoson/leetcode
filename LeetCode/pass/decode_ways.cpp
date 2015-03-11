/*************************************************************************
  > File Name: decode_ways.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 09:41:57 PM PDT
  > 解题思路:简单DP，一维 
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        size_t len = s.size();
        if(len==0||s[0]=='0')return 0;
        auto num = std::shared_ptr<int>(new int[len+1], [](int *p){delete p;});
        num.get()[0] = 0;
        num.get()[1] = 1;
        int one = 0;
        for(size_t i=2;i<=len;++i){
            if(valid(s[i-1])&&valid(s[i-2],s[i-1]))
                one = num.get()[i-1]+(i==2?1:num.get()[i-2]);
            else if(valid(s[i-1]))
                one = num.get()[i-1];
            else if(valid(s[i-2],s[i-1]))
                one = i==2?1:num.get()[i-2];
            else
                return 0;
            num.get()[i] = one;
        }
        return num.get()[len];
    }
private:
    bool valid(char a){
        return a>='1'&&a<='9';
    }
    bool valid(char first,char second){
        return first=='1'||(first=='2'&&second<='6');
    } 
};

int main(int argc,char* argv[]){
    Solution s;
    cout<<s.numDecodings("1212")<<endl;
    return 0;
}
