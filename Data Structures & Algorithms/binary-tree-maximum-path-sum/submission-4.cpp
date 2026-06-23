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
    int f(TreeNode* root,int &maxi){
        if(!root){
            return 0;
        }
        int lh=f(root->left,maxi);
        int rh=f(root->right,maxi);
        if(lh<0){lh=0;}
        if(rh<0){rh=0;}
        maxi=max(maxi,root->val+lh+rh);
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;

        f(root,maxi);
        return maxi;
    }
};
