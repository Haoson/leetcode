/*************************************************************************
  > File Name: subsets.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 05:19:15 PM PDT
  > 解题思路:dfs。思路同combination、permutation题 
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> path;
        std::sort(S.begin(),S.end());
        size_t size = S.size();
        for(size_t i=0;i<=size;++i){
            dfs(0,i,S,path,res);
            path.clear();
        }
        return res;
    }
private:
    void dfs(size_t start,size_t len,vector<int> &s,vector<int>&path,vector<vector<int> >&res){
        if(path.size()==len){
            res.push_back(path);
            return;
        }else{
            for(size_t i=start;i<s.size();++i){
                path.push_back(s[i]);
                dfs(i+1,len,s,path,res);
                path.erase(path.end()-1);
            }
        } 
    }
};

int main(int argc,char* argv[]){
    Solution s;
    vector<int> input = {2,3,1};
    vector<vector<int> > res = s.subsets(input);
    for(vector<int> v:res){
        for(int tmp:v)
            cout<<tmp<<" ";
        cout<<endl;
    }
    return 0;
}
