#include<iostream>
#include<vector>
using namespace std;
// 第一题
  struct TreeNode01 {
 	int val;
 	struct TreeNode01 *left;
 	struct TreeNode01 *right;
  };

    vector<int> postorderTraversal01(TreeNode01* root) {
        // write code here
        vector<int> res;
        if(!root)
        return res;
        vector<int> left = postorderTraversal01(root->left);
        vector<int> right = postorderTraversal01(root-> right);
        res.insert(res.end(),left.begin(),left.end());
        res.insert(res.end(), right.begin(),right.end());
        res.push_back(root->val);
        return res;
    }

