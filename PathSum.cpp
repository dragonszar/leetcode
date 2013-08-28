/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return(addchild(root, root->val, sum)

    }
    
    bool addchild(TreeNode *root, int accum, int sum)
    {
        if(root->left==NULL && root->right==NULL)
            return false;
            
        int tleft = root->left->val + accum;
        int tright = root->right->val + accum;
        if(tleft == sum || tright == sum)
            return true;
        addchild(root->left, tleft, sum);
        addchild(root->right, tright, sum);
    }
};