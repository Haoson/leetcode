/*************************************************************************
  > File Name: anagrams.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 03:02:28 PM PDT
  > 解题思路:Anagram（回文构词法）是指打乱字母顺序从而得到新的单词.这样，将几个单词按照字母顺序排序后，若它们相等，则它们属于同一组anagrams 
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        unordered_map<string,vector<string> >dict;   
        for(string str:strs){
            string tmp = str;
            std::sort(tmp.begin(),tmp.end());
            dict[tmp].push_back(str);
        }
        for(auto it = dict.begin();it!=dict.end();++it){
            if((*it).second.size()>1)
                res.insert(res.end(),(*it).second.begin(),(*it).second.end());
        }
        return res;
    }
};

int main(int argc,char * argv[]){
    Solution s;
    vector<string> input = {"tea","and","ate","eat","den"};
    vector<string> res = s.anagrams(input);
    for(string tmp:res)
        cout<<tmp<<" ";
    cout<<endl;
    return 0;
}
