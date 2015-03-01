/*************************************************************************
  > File Name: atoi.cpp
  > Author:Haoson 
  > Created Time: Sun 01 Mar 2015 01:12:31 PM PST
  > Description: 
 ************************************************************************/

#include<iostream>
#include<string>
#include<cmath>
#include<climits>
using namespace std;

class Solution {
public:
    int atoi(string str) {
        bool hasMinus = false;
        size_t i;
        for(i=0;i!=str.length();++i)
            if(str[i]!=' ')break;
        string tmp_str = str.substr(i);
        if(tmp_str.length()==0)
            return 0;
        if(tmp_str[0]=='-')hasMinus = true;
        if(tmp_str[0]=='-'||tmp_str[0]=='+')
            tmp_str = tmp_str.substr(1);
        for(i=0;i!=tmp_str.length();++i)
            if(tmp_str[i]<'0'||tmp_str[i]>'9')break;
        if(i==0)
            return 0;
        int res = 0;
        double testNum = pow(10,i-1);
        if(i!hasMinus&&testNum>INT_MAX)
            return INT_MAX;
        if(hasMinus&&-testNum<INT_MIN)
            return INT_MIN;
        long tmp_res = 0;
        size_t count = i;
        for(size_t j=0;j<count;++j,--i)
            tmp_res+=(tmp_str[j]-'0')*pow(10,i-1); 
        if(tmp_res>INT_MAX&&!hasMinus)
            res = INT_MAX;
        else if(hasMinus&&(-tmp_res<INT_MIN))
            res = INT_MIN;
        else
            res =hasMinus?-tmp_res:tmp_res;    
        return res;
    }

};
int main(int argc,char* argv[]){
    Solution s;
    cout<<(s.atoi("      -11919730356x"))<<endl;
    return 0;
}

