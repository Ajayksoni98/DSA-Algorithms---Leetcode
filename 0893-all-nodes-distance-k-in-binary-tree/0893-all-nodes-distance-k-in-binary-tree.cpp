/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *, TreeNode *> parent;
    void addparent(TreeNode *root, TreeNode *parent)
    {
        if(root == NULL)
        return;

        this->parent[root] = parent;
        addparent(root->left,root);
        addparent(root->right,root);

        
    }

    void dfs(TreeNode *target, int k ,vector<int> &ans,unordered_set<TreeNode *> & visited)
    {
        if(!target || visited.count(target)== 1)return;

        visited.insert(target);

        if( k== 0)
        {
        ans.push_back(target->val);
        return;
        }

        dfs(parent[target],k-1,ans,visited);
        dfs(target->left,k-1, ans,visited);
        dfs(target->right,k-1,ans,visited);


        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        addparent(root,NULL);

        unordered_set<TreeNode *> visited;

        vector<int> ans;


        dfs(target,k,ans,visited);

        return ans;
        
    }
};