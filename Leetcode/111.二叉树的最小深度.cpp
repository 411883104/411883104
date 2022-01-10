/*
 * @Author: Outsider
 * @Date: 2021-11-15 22:54:20
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-15 23:37:20
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTestd:\C++\Leetcode\111.二叉树的最小深度.cpp
 */
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int res=0;
    int minDepth(TreeNode* root) {
        if(root->left==nullptr||root->right==nullptr)
            return res;
        else{
            res++;
            minDepth(root->left);
            minDepth(root->right);
        }
    }
};
// @lc code=end

