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
    priority_queue<int> p;

    void traversal(TreeNode* root){
        if(root==NULL) 
            return;
        p.push(root->val);

        traversal(root->left);
        traversal(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        traversal(root);

        int res = INT_MAX;
        while(p.size()>1)
        {
            int top = p.top();
            p.pop();
            res = min(res, top-p.top());
        }
        return res;

    }
};