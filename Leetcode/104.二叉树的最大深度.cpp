/*
 * @Author: Outsider
 * @Date: 2021-11-15 23:17:21
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-17 23:33:37
 * @Description: In User Settings Edit
 * @FilePath: \Notesd:\C++\Leetcode\104.二叉树的最大深度.cpp
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        else
        {
            int left_depth=maxDepth(root->left);
            int right_depth=maxDepth(root->right);
            return max(left_depth,right_depth)+1;
        }
    }
};
// @lc code=end

