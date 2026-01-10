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
    
    long long maxsum = 0;
    long long maxproduct = 0;
    
    #define MOD 1e9+7
    
    void sumtree(TreeNode *root)
    {
        if(root == NULL)
            return;
        if(root -> left)
        {
        sumtree(root -> left);
        root -> val += root -> left->val;
        }
        if(root -> right)
        {
        sumtree(root -> right);
        root -> val  += root -> right-> val;
        }
        
        
        
    }
    
  void   inorder(TreeNode *root)
    {
        if(root == NULL)
            return;
         
         inorder(root -> left);
        inorder(root -> right);
         maxproduct = max(maxproduct, ((long long)root -> val)*(maxsum - (long long)root ->val));
      
        
    }
    int maxProduct(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        sumtree(root);
        maxsum = root ->val;
        
      inorder(root);
       return maxproduct %1000000007;
        
        
        
    }
};