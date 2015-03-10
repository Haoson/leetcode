/*************************************************************************
  > File Name: sprt.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 04:35:46 PM PDT
  > 解题思路:二分 
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if(x<=0)return 0;
        int high = x;
        int low = 1;
        while(1){
            int mid = (low+high)/2;
            if(mid==low||mid==high)
                return mid;
            int tmp = x/mid;//不能直接用mid*mid,防止溢出
            if(tmp==mid)
                return mid;
            else if(tmp<mid)
                high = mid;
            else
                low = mid;
        }    
    }
};
