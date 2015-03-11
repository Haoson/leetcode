/*************************************************************************
  > File Name: palindrome_partitioning.cpp
  > Author:Haoson 
  > Created Time: Wed 11 Mar 2015 12:07:43 PM PDT
  > 解题思路:dfs.思路同combination，permutation题 
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> >res;
        vector<string> path;
        if(!s.empty())
            dfs(s,0,path,res);
        return res;
    }
private:
    void dfs(string& s,size_t partition_pos,vector<string> &path,vector<vector<string> >&res){
        if(partition_pos==s.size()){
            res.push_back(path);
            return;
        }else{
            for(auto i=partition_pos;i<s.size();++i){
                if(isPalindrome(s,partition_pos,i)){
                    path.push_back(s.substr(partition_pos,i-partition_pos+1));
                    dfs(s,i+1,path,res); 
                    path.pop_back();
                }
            }
        } 
    }
    bool isPalindrome(string& s,size_t start,size_t end){
        while(start<end)
            if(s[start++]!=s[end--])return false;
        return true;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    vector<vector<string> > res = s.partition("aab");
    for(auto v:res){
        for(auto t:v)cout<<t<<" ";
        cout<<endl;
    }
    return 0;
}
