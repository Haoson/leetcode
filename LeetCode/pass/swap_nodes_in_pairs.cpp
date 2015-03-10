/*************************************************************************
  > File Name: swap_nodes_in_pairs.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 11:28:25 AM PDT
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
    ListNode *swapPairs(ListNode *head) {
        if(!head||!(head->next))return head;    
        ListNode dummy(0);//辅助节点
        ListNode* cur = &dummy;
        ListNode* pre = head;
        while(pre&&pre->next){
            cur->next = head->next;
            head = head->next->next;
            cur->next->next = pre;
            cur = pre;
            pre->next = head;
            pre = head;
        }
        return dummy.next;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    a->next = b;b->next = c;c->next = d;
    ListNode* res = s.swapPairs(a);
    while(res){
        cout<<res->val<<" ";
        res =res->next;
    }
    cout<<endl;
    return 0;
}
