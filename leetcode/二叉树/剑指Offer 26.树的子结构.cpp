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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL || B==NULL)
            return false;
        bool result = false;
        if(A->val == B->val)
            result = theSame(A, B);
        if(!result)
            result = isSubStructure(A->left, B);
        if(!result) 
            result = isSubStructure(A->right, B);
        return result;

    }
    bool theSame(TreeNode* A, TreeNode* B)
    {
        if(B == NULL)
            return true;
        if(A == NULL || A->val != B->val)
            return false;
        return theSame(A->left, B->left) && theSame(A->right, B->right);
    }
};
