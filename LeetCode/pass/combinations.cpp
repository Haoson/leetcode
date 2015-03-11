/*************************************************************************
  > File Name: combinations.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 04:54:57 PM PDT
  > 解题思路:思路同permutation那题，dfs。 
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >res;
        vector<int> path;
        dfs(n,k,1,path,res);
        return res;
    }
private:
    void dfs(int n,int k,int start,vector<int>&path,vector<vector<int> >&res){
        if(path.size()==static_cast<size_t>(k)){
            res.push_back(path);
            return;
        }else{
            for(int i=start;i<=n;++i){
                path.push_back(i);
                dfs(n,k,i+1,path,res);
                path.erase(path.end()-1);
            }
        } 
    }
};

int main(int argc,char* argv[]){
    Solution s;
    vector<vector<int> > res = s.combine(4,2);
    for(vector<int> v:res){
        for(int tmp:v)
            cout<<tmp<<" ";
        cout<<endl;
    }
    return 0;
}
