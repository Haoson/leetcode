/*************************************************************************
  > File Name: merge_k_sorted_lists2.cpp
  > Author:Haoson 
  > Created Time: Tue 10 Mar 2015 11:08:37 AM PDT
  > 解题思路:构建堆，每次从堆中选择最小的元素 
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Comp{
    bool operator()(ListNode*a,ListNode*b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        size_t list_size =  lists.size();
        if(list_size==0)return NULL;
        ListNode dummy(0);
        ListNode* res = &dummy;
        priority_queue<ListNode*,vector<ListNode*>,Comp> pq;  
        for(size_t i=0;i<list_size;++i){
            if(lists[i])    
                pq.push(lists[i]);
        }
        while(!pq.empty()){
            ListNode* tmp = pq.top();
            pq.pop();
            res->next = tmp;
            res = res->next;
            if(tmp->next)
                pq.push(tmp->next);
        }
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
