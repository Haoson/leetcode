/*************************************************************************
  > File Name: word_ladder.cpp
  > Author:Haoson 
  > Created Time: Sun 08 Mar 2015 05:37:12 PM PDT
  > 解题思路:BFS 
 ************************************************************************/

#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        size_t s_len = start.size();
        size_t e_len = end.size();
        if(s_len==0||e_len==0||(s_len!=e_len))return 0;
        if(start==end)return 2;
        typedef pair<string,int> pr;
        queue<pr> q; 
        unordered_set<string> unique;//去重
        q.push(pr(start,1));
        unique.insert(start);
        while(!q.empty()){
            pr pr_tmp = q.front();
            q.pop();
            for(size_t i = 0;i < pr_tmp.first.size();++i){
                string tmp = pr_tmp.first;
                for(auto j = 'a';j<='z';++j){
                    if(tmp[i]==j)continue;
                    tmp[i] = j; 
                    if(tmp==end)return pr_tmp.second+1;
                    if(dict.find(tmp)!=dict.end()&&unique.find(tmp)==unique.end()){
                        q.push(pr(tmp,pr_tmp.second+1));
                        unique.insert(tmp); 
                    }
                }
            }
        }
        return 0;
    }
};
int main(int argc,char* argv[]){
    Solution s;
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    cout<<(s.ladderLength("hit","cog",dict))<<endl;
    return 0;
}
