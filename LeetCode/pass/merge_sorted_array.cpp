/*************************************************************************
  > File Name: merge_sorted_array.cpp
  > Author:Haoson 
  > Created Time: Sun 08 Mar 2015 12:08:01 PM PDT
  > 解题思路:从后往前开始归并 
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int res_index = m+n-1;
        int a_index = m-1;
        int b_index = n-1;
        while(a_index>=0&&b_index>=0){
            A[res_index--] = (A[a_index]>=B[b_index])?A[a_index--]:B[b_index--];
        }
        while(b_index>=0){
            A[res_index--] = B[b_index--];
        }
    }
};

int main(int argc,char * argv[]){
    int B[] = {2,5,7,11};
    int A[] = {1,6,8,9,10,13,14,15,0,0,0,0};
    Solution s;
    s.merge(A,8,B,4);
    for(int tmp:A){
        cout<<tmp<<" ";
    }
    cout<<endl;
    return 0;
}
