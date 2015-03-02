    /*************************************************************************
  > File Name: climbing_stairs.cpp
  > Author:Haoson 
  > Created Time: Sat 07 Mar 2015 06:22:27 PM PST
  > 解题思路:DP 
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        else{
            int res = 0;
            int step1 = 1;
            int step2 = 2;
            for(int i=3;i<=n;++i){
                res = step1+step2;
                step1 = step2;
                step2 = res;
            }
            return res;
        }
    }
};

int main(int argc,char* argv[]){
    Solution s;
    cout<<(s.climbStairs(6))<<endl;
    return 0;
}
