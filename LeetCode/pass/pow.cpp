/*************************************************************************
  > File Name: pow.cpp
  > Author:Haoson 
  > Created Time: Sat 07 Mar 2015 02:57:58 AM PST
  > Description:解题思路：二分法 
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if(n < 0)
            return 1/powHandler(x,-n);
        else 
            return powHandler(x,n);
    }
private:
    double powHandler(double x,int n){
        if(n==0){
            return 1;
        }else{
            double tmp = powHandler(x,n/2);
            return tmp*tmp*((n%2==0)?1:x);
        }
    }
};

int main(int argc,char *argv[]){
    Solution s;
    cout<<(s.pow(2,3))<<" "<<(s.pow(2,-2))<<endl;
    return 0;
}
