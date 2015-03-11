/*************************************************************************
  > File Name: sum_root_to_leaf_numbers.cpp
  > Author:Haoson 
  > Created Time: Wed 11 Mar 2015 11:26:33 AM PDT
  > 解题思路:DFS 
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int res = 0;
        if(root)
            dfs(root,root->val,res);
        return res;
    }
private:
    void dfs(TreeNode* cur_node,int cur_num,int& res){
        if(!(cur_node->left)&&!(cur_node->right))
            res+=cur_num;
        if(cur_node->left)
            dfs(cur_node->left,cur_num*10+cur_node->left->val,res);
        if(cur_node->right)
            dfs(cur_node->right,cur_num*10+cur_node->right->val,res);
    }
};

int main(int argc,char* argv[]){
    Solution s;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right= new TreeNode(3);
    cout<<s.sumNumbers(root)<<endl;
    return 0;
}
