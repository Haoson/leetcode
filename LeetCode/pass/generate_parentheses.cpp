/*************************************************************************
  > File Name: generate_parentheses.cpp
  > Author:Haoson 
  > Created Time: Mon 09 Mar 2015 11:11:36 AM PDT
  > 解题思路:dfs一步步构造字符串。当左括号出现次数< n 时，就可以放置新的左括号。当右括号出现次数小于左括号出现次数时，就可以放置新的右括号
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n>0) dfs(n,"",0,0,res);
        return res;
    }
private:
    void dfs(int n,string s,int l_p,int r_p,vector<string>& res){
        if(l_p==n){
            res.push_back(s.append(static_cast<size_t>(n-r_p),')'));
            return;
        }else{
            dfs(n,s+'(',l_p+1,r_p,res);
            if(l_p>r_p)dfs(n,s+')',l_p,r_p+1,res);
        }
    }
};

int main(int argc,char* argv[]){
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for(string tmp:res)
        cout<<tmp<<" ";
    cout<<endl;
    return 0;
}
