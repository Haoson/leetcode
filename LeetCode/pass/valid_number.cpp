/*************************************************************************
  > File Name: valid_number.cpp
  > Author:Haoson 
  > Created Time: Sat 07 Mar 2015 06:40:39 AM PST
  > 解题思路：利用有限自动机解决。
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        enum InputType{//输入字符串的字符类型
            INVALID,//无效类型，例如')'
            SPACE,//空格
            SIGN,//正负符号
            DIGIT,//数字
            DOT,//点
            EXPONENT//e或者E
        };
        int trans_table[][6] = {
            //0INVA,1SPA,2SIG,3DI,4DO,5E  
            {-1,  0,  3,  1,  2, -1},//0初始无输入或者只有space的状态  
            {-1,  8, -1,  1,  4,  5},//1输入了数字之后的状态  
            {-1, -1, -1,  4, -1, -1},//2前面无数字，只输入了Dot的状态  
            {-1, -1, -1,  1,  2, -1},//3输入了符号状态  
            {-1,  8, -1,  4, -1,  5},//4前面有数字和有dot的状态  
            {-1, -1,  6,  7, -1, -1},//5'e' or 'E'输入后的状态  
            {-1, -1, -1,  7, -1, -1},//6输入e之后输入Sign的状态  
            {-1,  8, -1,  7, -1, -1},//7输入e后输入数字的状态  
            {-1,  8, -1, -1, -1, -1},//8前面有有效数输入之后，输入space的状态  
        };  
        int state = 0;//一开始处于初始态
        for(size_t i=0;i!=s.size();++i){
            InputType it = INVALID;
            if(s[i]==' ')it = SPACE;
            else if(s[i]=='+'||s[i]=='-')it = SIGN;
            else if(s[i]>='0'&&s[i]<='9')it =  DIGIT;
            else if(s[i]=='.')it = DOT;
            else if(s[i]=='e'||s[i]=='E')it =  EXPONENT;
            state = trans_table[state][it];
            if(state==-1)return false;
        }
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    cout<<((s.isNumber(" 2e10 "))?"true":"false")<<endl;
    return 0;
}
