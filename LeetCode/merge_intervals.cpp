/*************************************************************************
  > File Name: merge_intervals.cpp
  > Author:Haoson 
  > Created Time: Sat 07 Mar 2015 03:25:44 AM PST
  > Description:解题思路：先排序，然后原地组合删除（两个指针，i指针扫描数据，j指针指示目前最大元组，这个元组可能是原有的，也有可能是合并而来的，扫描结束后，删除j指针之后的元素即可） 
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
 
struct IntervalComp{
    bool operator() (Interval a,Interval b){
        return a.start<b.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        size_t size = intervals.size();
        if(size<2)return intervals;
        std::sort(intervals.begin(),intervals.end(),IntervalComp());   
        size_t max_tuple_index =0;
        for(size_t i=1;i!=size;++i){
            if(intervals[max_tuple_index].end >= intervals[i].start){//有重叠时，合并，指示最大元组的指针位置不变
                intervals[max_tuple_index].end = max(intervals[i].end,intervals[max_tuple_index].end);
            }else{//当不相交时，指示最大元组的指针下移，将下一个元素重置为最大元组
                ++max_tuple_index; 
                intervals[max_tuple_index].start = intervals[i].start;
                intervals[max_tuple_index].end = intervals[i].end;
            }
        }
        intervals.erase(intervals.begin()+static_cast<int>(max_tuple_index)+1,intervals.end());
        return intervals;
    }
private:
    int max(int a,int b){
        return (a>b)?a:b;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    vector<Interval> input = {Interval(2,3),Interval(4,5),Interval(1,10)};
    vector<Interval> output = s.merge(input);
    for(Interval tmp:output){
        cout<<tmp.start<<":"<<tmp.end<<" ";
    }
    cout<<endl;
    return 0;
}
