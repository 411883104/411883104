/*
 * @Author: Outsider
 * @Date: 2021-11-17 23:35:45
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-18 18:17:11
 * @Description: In User Settings Edit
 * @FilePath: \Java_testd:\C++\Leetcode\112.路径总和.cpp
 */
/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
class Solution
{
public:
    bool result=false;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        
        if (!root)
            return result;
        else
        {
            if (!root->left && !root->right && targetSum==root->val)
                result=true;
            else
            {
                if (root->left)
                    hasPathSum(root->left,targetSum-root->val);
                if (root->right)
                    hasPathSum(root->right,targetSum-root->val);
            }
        }
        return result;
    }
};
// @lc code=end
