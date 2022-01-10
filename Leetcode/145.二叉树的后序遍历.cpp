/*
 * @Author: Outsider
 * @Date: 2021-12-02 20:11:35
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-02 20:17:00
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTestd:\C++\Leetcode\145.二叉树的后序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return v;
        else{
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            v.push_back(root->val);
            return v;
        }
    }
};
// @lc code=end

