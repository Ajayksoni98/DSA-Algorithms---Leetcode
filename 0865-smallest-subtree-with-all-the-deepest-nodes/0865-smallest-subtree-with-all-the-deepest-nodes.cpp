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

    int depth(TreeNode *root)
    {
        if(root ==NULL)return 0;

        if(root -> left == NULL && root ->right == NULL)return 1;

        return 1 + max(depth(root->left), depth(root->right));
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        if(root == NULL) return root;

        if(root -> left == NULL && root -> right == NULL)
        return root;

        int x = depth(root->left);
        int y = depth(root->right);

        if(x == y)return root;

        else if(x > y)
        {
            return subtreeWithAllDeepest(root->left);
        }
        else
            return subtreeWithAllDeepest(root->right);


return NULL;
        
    }
};