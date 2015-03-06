/*************************************************************************
  > File Name: merge_two_list.cpp
  > Author:Haoson 
  > Created Time: Thu 05 Mar 2015 11:29:14 PM PST
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode* res = NULL;
        bool hasHead = false;
        while(l1&&l2){
            ListNode* l1_tmp = NULL;
            ListNode* l2_tmp = NULL;
            if(!hasHead){
                res = (l1->val <= l2->val)?l1:l2; 
                hasHead = true;
            }
            while(l1&&l1->val <= l2->val){
                l1_tmp = l1;
                l1 = l1->next;
            }
            if(l1_tmp)
                l1_tmp->next = l2;
           while(l2&&l1&&l2->val <= l1->val){
                l2_tmp = l2;
                l2 = l2->next;
            }
            if(l2_tmp)
                l2_tmp->next = l1;    
        }    
        return res;
    }
};

