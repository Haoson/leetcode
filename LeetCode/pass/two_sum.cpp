/*************************************************************************
  > File Name: two_sum.cpp
  > Author:Haoson 
  > Created Time: Sun 01 Mar 2015 10:14:57 AM PST
  > Description:解题思路：使用Hash表，存储每个数以及对应的下标 
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_multimap<int,int> num_map;
        int index=1;
        for(auto p=numbers.begin();p!=numbers.end();++p,++index){
            num_map.insert(pair<int,int>(*p,index));
        }
        vector<int> result;
        for(auto beg_it = num_map.begin();beg_it!=num_map.end();++beg_it){
            unordered_multimap<int,int>::iterator tmp_it = num_map.find(target-(*beg_it).first);
            if(tmp_it!=num_map.end()&&tmp_it!=beg_it){//&&后面的判断条件是为了处理有重复元素的情况
                result.push_back((*beg_it).second); 
                result.push_back((*tmp_it).second); 
                std::sort(result.begin(),result.end());
                break;
            } 
        }
        return result;   
    }
};

int main(int argc,char* argv[]){
    vector<int> input = {2,1,9,4,4,56,90,3};
    Solution s;
    vector<int> res = s.twoSum(input,8);
    for(int tmp:res){
        cout<<tmp<<" "; 
    }
    cout<<endl;
    return 0;
}
