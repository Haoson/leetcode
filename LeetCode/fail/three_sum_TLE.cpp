/*************************************************************************
  > File Name: three_sum.cpp
  > Author:Haoson 
  > Created Time: Thu 05 Mar 2015 04:46:36 AM PST
  > Description: 
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> >res;
        unordered_map<string,int> r_duplicate;//去重
        for(auto it=num.begin();it!=num.end();++it){
            for(auto it1=it+1;it1!=num.end();++it1){
                for(auto it2=it1+1;it2!=num.end();++it2){
                    if(*it+*it1+*it2==0){
                        vector<int> triplet = {*it,*it1,*it2}; 
                        std::sort(triplet.begin(),triplet.end());
                        ostringstream tmp_ss;
                        for(int tmp_int:triplet)
                            tmp_ss<<tmp_int;
                        if(r_duplicate.insert(pair<string,int>(tmp_ss.str(),0)).second)
                            res.push_back(triplet);
                    }
                }
            }
        }
        return res;
    }
};
int main(int argc,char *argv[]){
    Solution s;
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int> > res = s.threeSum(input);
    for(vector<int> tmp:res){
        for(int tmp_num:tmp){
            cout<<tmp_num<<" ";
        } 
        cout<<endl;
    }
}
