/*************************************************************************
  > File Name: validate_binary_search_tree.cpp
  > Author:Haoson 
  > Created Time: Sun 08 Mar 2015 12:35:46 PM PDT
  > 解题思路:对于每一个子树，限制它的最大，最小值，如果超过则返回false。需要注意的是，初始最大值（最小值）应该大于Int的最大值（最小值） 
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
        return isValidBST(root,std::numeric_limits<long long>::min(),std::numeric_limits<long long>::max());
    }
private:
    bool isValidBST(TreeNode*root,long long lower,long long upper){
        if(!root)return true;
        return (root->val>lower&&root->val<upper&&isValidBST(root->right,root->val,upper)&&isValidBST(root->left,lower,root->val));
    }
};
int main(int argc,char* argv[]){
    Solution s;
    TreeNode *r_child = new TreeNode(2147483647);
    TreeNode *r = new TreeNode(-2147483648);
    r->right = r_child;
    cout<<(s.isValidBST(r)?"true":"false")<<endl;
    return 0;
}
