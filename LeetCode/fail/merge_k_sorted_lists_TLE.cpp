/*************************************************************************
  > File Name: merge_k_sorted_lists.cpp
  > Author:Haoson 
  > Created Time: Mon 09 Mar 2015 07:43:51 PM PDT
  > 解题思路:两两归并merge 
 ************************************************************************/

#include<iostream>
#include<vector>
#include<limits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        size_t list_size =  lists.size();
        if(list_size==0)return NULL;
        ListNode* p = lists[0];
        for(size_t i=1;i<list_size;++i){
            p = mergeTwoSortedLists(p,lists[i]); 
        }
        return p;
    }
private:
    ListNode* mergeTwoSortedLists(ListNode*p1,ListNode*p2){
        ListNode dummy(std::numeric_limits<int>::min());    
        ListNode* ptr = &dummy;
        while(p1&&p2){
            if(p1->val<=p2->val){
                ptr->next = p1;
                p1 = p1->next;
            }else{
                ptr->next = p2;
                p2 = p2->next;
            }   
            ptr  = ptr->next;
        }
        if(p1)ptr->next = p1;
        if(p2)ptr->next = p2;
        return dummy.next;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    vector<ListNode*> input = {new ListNode(7),new ListNode(49),new ListNode(73),new ListNode(58),new ListNode(30),new ListNode(72)};
    ListNode* res = s.mergeKLists(input);
    while(res){
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}
