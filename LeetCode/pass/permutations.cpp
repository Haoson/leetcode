/*************************************************************************
  > File Name: permutations.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 02:22:33 PM PDT
  > 解题思路:dfs 
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> >res;
        vector<int>path;
        dfs(num,path,res);
        return res;
    }
private:
    void dfs(vector<int>& num,vector<int>& path,vector<vector<int> >&res){
        if(path.size()==num.size()){
            res.push_back(path);
            return;
        }else{
            for(int tmp:num){
                if(find(path.begin(),path.end(),tmp)==path.end()){
                    path.push_back(tmp);
                    dfs(num,path,res);
                    path.erase(path.end()-1);
                }
            }
        } 
    }
};

int main(int argc,char* argv[]){
    Solution s;
    vector<int> input = {2,3,1};
    vector<vector<int> > res = s.permute(input);
    for(vector<int> tmp_v:res){
        for(int tmp_int:tmp_v)
            cout<<tmp_int<<" ";
        cout<<endl;
    }
    return 0;
}
