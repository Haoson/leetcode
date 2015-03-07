/*************************************************************************
  > File Name: insert_intervals.cpp
  > Author:Haoson 
  > Created Time: Sat 07 Mar 2015 05:40:26 AM PST
  > Description:解题思路：首先按照interval的start的大小直接将新元组插入进去，然后从插入的元素开始进行合并，这道题思路和merge_intervals思路一致 
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        bool insert_success = false;
        auto it = intervals.begin(); 
        for(;it!=intervals.end();++it){
            if((*it).start>newInterval.start){
                it = intervals.insert(it,newInterval);
                insert_success = true;
                break;
            }
        }    
        if(!insert_success)
            it = intervals.insert(intervals.end(),newInterval);
        if(it==intervals.begin())
            ++it;
        auto j = it-1;
        for(;it!=intervals.end();++it){
            if((*it).start<=(*j).end)
                (*j).end = ((*it).end>(*j).end)?(*it).end:(*j).end;
            else{
                ++j;
                (*j).start = (*it).start;
                (*j).end = (*it).end;
            }
        }
        intervals.erase(j+1,intervals.end());
        return intervals;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    vector<Interval> input = {Interval(1,5)};
    vector<Interval> output = s.insert(input,Interval(2,3));
    for(Interval tmp:output){
        cout<<(tmp.start)<<":"<<(tmp.end)<<endl;
    }
    return 0;
}
