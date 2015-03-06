/*************************************************************************
  > File Name: valid_parentheses.cpp
  > Author:Haoson 
  > Created Time: Thu 05 Mar 2015 06:53:29 PM PST
  > Description: 
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool valid = true;
        stack<char> symbol_stack;
        typedef pair<char,char> pr;
        unordered_map<char,char> m = {pr(')','('),pr('}','{'),pr(']','[')};
        for(auto it=s.begin();it!=s.end();++it){
            if(m.find(*it)!=m.end()){
                if(!(symbol_stack.empty())&&m[*it]==symbol_stack.top()){
                    symbol_stack.pop();
                }else{
                    valid = false;
                    break;
                }
            }else{
                symbol_stack.push(*it);    
            }
        }
        if(!(symbol_stack.empty()))
            valid = false;
        return valid;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    cout<<(s.isValid("(()[()}])[]{}"))<<endl;
    return 0;
}



