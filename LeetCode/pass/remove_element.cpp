/*************************************************************************
  > File Name: remove_element.cpp
  > Author:Haoson 
  > Created Time: Mon 09 Mar 2015 10:50:33 PM PDT
  > 解题思路:两个指针，头指针找target数据，尾指针指数组的最后一个有效数字 
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0)return 0;
        size_t head_index = 0,tail_index =static_cast<size_t>(n-1);    
        while(head_index < tail_index){
            while(A[tail_index]==elem&&head_index<tail_index)--tail_index;
            while(A[head_index]!=elem&&head_index<tail_index)++head_index;
            if(head_index<tail_index){
                A[head_index] = A[tail_index];
                --tail_index;
                ++head_index;
            }
        }
        return (A[head_index]!=elem)?static_cast<int>(tail_index+1):static_cast<int>(tail_index);
    }
};

int main(int argc,char*argv[]){
    Solution s;
    int A[] = {3,1,3,4,5,1,4545,3456,7676,3,3,3,2,3,23,3};
    cout<<(s.removeElement(A,16,3))<<endl;
    return 0;
}
