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

    int height(TreeNode *root)
    {
        if(root == NULL) return 0;

        if(root ->left == NULL && root->right == NULL)return 1;

        return 1 + max(height(root->left), height(root ->right));
    }
    bool isBalanced(TreeNode* root) {

        if(!root) return true;

        if(root->left == NULL && root->right == NULL) return true;

        int x =  height(root->left) - height(root->right);

        cout<<x<<endl;

        if(x <=1 && x >=-1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

        return false;
        
    }
};