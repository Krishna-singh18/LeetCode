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
    void inorderTr(TreeNode* root,vector<int>&inorder ){
        if(root==NULL)return ;
        inorderTr(root->left,inorder);
        inorder.push_back(root->val);
        inorderTr(root->right,inorder);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inorderTr(root,inorder);
        int left =0;
        int right=inorder.size()-1;

        while(left<right){
            int sum =inorder[left]+inorder[right];

            if(sum==k)return true;
            else if( sum<k)left++;
            else right--;

        }
        return false;

    }
};