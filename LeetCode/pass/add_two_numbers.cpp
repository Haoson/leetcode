/*************************************************************************
  > File Name: add_two_numbers.cpp
  > Author:Haoson 
  > Created Time: Mon 09 Mar 2015 09:13:11 AM PDT
  > Description: 
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);//辅助dummy节点    
        ListNode *res = &dummy;
        ListNode* ptr1 = l1,*ptr2 = l2;
        int carry = 0;
        while(ptr1||ptr2){
            int num = carry+(ptr1?ptr1->val:0)+(ptr2?ptr2->val:0);
            carry = num/10;
            num = num%10;
            res->next = new ListNode(num);
            res = res->next;
            if(ptr1)ptr1 = ptr1->next;
            if(ptr2)ptr2 = ptr2->next;
        }
        if(carry>0)res->next = new ListNode(carry);//进位导致位数增多情况
        return dummy.next;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    ListNode a(2);ListNode a1(4);ListNode a2(3);
    a.next = &a1;
    a1.next = &a2;
    ListNode b(5);ListNode b1(6);ListNode b2(4);
    b.next = &b1;
    b1.next = &b2;
    ListNode * res = s.addTwoNumbers(&a,&b);
    while(res){
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}
