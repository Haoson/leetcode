/*************************************************************************
  > File Name: validate_binary_search_tree.cpp
  > Author:Haoson 
  > Created Time: Sun 08 Mar 2015 02:05:25 PM PDT
  > 解题思路:二叉搜索树中序遍历，产生的数递增 
 ************************************************************************/

#include<iostream>
#include<limits>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        long long min = std::numeric_limits<long long>::min();
        return isValidBST(root,min);
    }
private:
    bool isValidBST(TreeNode* root,long long &lower){
        if(!root)return true;
        if(!isValidBST(root->left,lower))return false;
        if(lower>=root->val)return false;
        lower = root->val;
        if(!isValidBST(root->right,lower))return false;
        return true;
    }
};
