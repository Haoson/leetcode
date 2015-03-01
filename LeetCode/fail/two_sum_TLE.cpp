/*************************************************************************
  > File Name: two_sum.cpp
  > Author:Haoson 
  > Created Time: Sun 01 Mar 2015 12:10:39 AM PST
  > Description: 
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> sortNum;
        sortNum.insert(sortNum.begin(),numbers.begin(),numbers.end());
        quickSort(sortNum,0,numbers.size());  

        vector<int> result;
        size_t i = 0,j = 0;
        while(true){
            while(sortNum[i]+sortNum[++j]<target);
            if(sortNum[i]+sortNum[j]==target){
                for(size_t index=0;index!=numbers.size();++index){
                    if(numbers[index]==sortNum[i]||numbers[index]==sortNum[j])
                        result.push_back(static_cast<int>(index+1));
                }
                break;
            }
            ++i;
            j = i;
        }
       return result;   
    }

    void quickSort(vector<int>&numbers,size_t begin,size_t end){
        if(end-begin<=1)return;
        size_t p = partition(numbers,begin,end); 
        quickSort(numbers,begin,p);
        quickSort(numbers,p+1,end);
    }
    
    size_t partition(vector<int>&numbers,size_t begin,size_t end){
        size_t pivot = begin,i = begin,j=end;
        while(true){
            while(less(numbers[++i],numbers[pivot]))if(i==end-1)break; 
            while(less(numbers[pivot],numbers[--j]))if(j==begin)break; 
            if(i>=j)break;
            swap(numbers,i,j);
        } 
        swap(numbers,pivot,j);
        return j;
    }

    template <typename T>
    bool less(T a,T b){
        return (a<b)?true:false;
    }

    void swap(vector<int>&num,size_t index1,size_t index2){
        int tmp = num[index1];
        num[index1] = num[index2];
        num[index2] = tmp;
    }
};

int main(int argc,char* argv[]){
    vector<int> input = {2,7,3,9};
    Solution s;
    vector<int> res = s.twoSum(input,16);
    for(int tmp:res){
        cout<<tmp<<" "; 
    }
    cout<<endl;
    return 0;
}
