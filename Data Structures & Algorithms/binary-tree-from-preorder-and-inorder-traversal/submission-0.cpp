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
    unordered_map<int,int> mpp;
    TreeNode* f(vector<int>& preorder, vector<int>& inorder,int prestart,int preend,int instart,int inend){
        int n=preorder.size();
        if(prestart>preend || instart>inend){
            return NULL;
        }
        TreeNode* newroot=new TreeNode(preorder[prestart]);
        int splitindex=mpp[newroot->val];
        int numsleft=splitindex-instart;

        newroot->left=f(preorder,inorder,prestart+1,prestart+numsleft,instart,splitindex-1);
        newroot->right=f(preorder,inorder,prestart+numsleft+1,preend,splitindex+1,n-1);

        return newroot;


    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return f(preorder,inorder,0,n-1,0,n-1);


    }
};
