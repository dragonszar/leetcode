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
        if(root==NULL)
            return false; 
        return(addchild(root, 0, sum));

    }
    
    bool addchild(TreeNode *root, int accum, int sum)
    {       
        int acc = accum  + root->val;
        if(acc==sum && isleaf(root))
            return true;
        if(root->left != NULL){   
            addchild(root->left, acc, sum);
        }
        
        if(root->right != NULL){   
            addchild(root->right, acc, sum);
        }
        return false;
        
    }
    
    bool isleaf(TreeNode *root)
    {
        return (root->left==NULL && root->right==NULL);
    }
};