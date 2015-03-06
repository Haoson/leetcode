/*************************************************************************
  > File Name: three_sum.cpp
  > Author:Haoson 
  > Created Time: Thu 05 Mar 2015 06:06:26 PM PST
  > Description:解题思路：先排序，然后两个指针前后夹逼 
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> >res;
        if(num.size()<3)return res;
        auto begin = num.begin(),end = num.end();
        std::sort(begin,end);
        for(auto it=begin;it!=end-2;++it){
            auto head = it+1,tail = end-1;    
            if(it>begin&&*it==*(it-1))continue;//跳过重复的元素
            while(head<tail){
                if(*it+*head+*tail>0){
                    do{
                        --tail;
                    }while(head<tail&&*tail==*(tail+1));
                }else if(*it+*head+*tail<0){
                    do{
                        ++head;
                    }while(head<tail&&*head==*(head-1));
                }else{
                    vector<int> triplet={*it,*head,*tail};
                    std::sort(triplet.begin(),triplet.end());
                    res.push_back(triplet);
                    do{
                        ++head;
                        --tail;
                    }while(head<tail&&*head==*(head-1)&&*tail==*(tail+1));
                }
            }
        }
        return res;
    }
};
int main(int argc,char*argv[]){
    Solution s;
    vector<int> input = {1,2,-2,-1};
    vector<vector<int> > res = s.threeSum(input);
    for(vector<int> tmp:res){
        for(int tmp_num:tmp){
            cout<<tmp_num<<" ";
        } 
        cout<<endl;
    }
    return 0;
}
