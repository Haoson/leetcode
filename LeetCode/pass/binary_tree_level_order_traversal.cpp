/*************************************************************************
  > File Name: binary_tree_level_order_traversal.cpp
  > Author:Haoson 
  > Created Time: Wed 11 Mar 2015 10:13:22 AM PDT
  > Description: 
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> >res;
        if(!root)return res;
        typedef pair<TreeNode*,size_t> pr;
        queue<pr > q;
        size_t index = 1,tmp = 0;
        q.push(pr(root,index));
        while(!q.empty()){
            pr pr_tmp = q.front();
            q.pop();
            tmp = pr_tmp.second;
            if(res.size()<tmp)
                res.push_back(vector<int>());
            res[tmp-1].push_back(pr_tmp.first->val);
            if(pr_tmp.first->left)
                q.push(pr(pr_tmp.first->left,tmp+1));
            if(pr_tmp.first->right)
                q.push(pr(pr_tmp.first->right,tmp+1));
        }
        return res;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    TreeNode* root = new TreeNode(3);
    TreeNode* r = new TreeNode(20);
    root->left = new TreeNode(9);
    root->right = r;
    r->left = new TreeNode(15);
    r->right = new TreeNode(7);
    vector<vector<int> > res = s.levelOrder(root);
    for(vector<int> v:res){
        for(int tmp:v)cout<<tmp<<" ";
        cout<<endl;
    }
    return 0;
}
