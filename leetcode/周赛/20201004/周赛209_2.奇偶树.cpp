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
typedef struct P
{
    TreeNode* node;
    int level;
}P;
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<P> que;
        que.push({root,0});
        int prevlevel = -1;
        int lastval = 0;
        while(que.size())
        {
            TreeNode* nex = que.front().node;
            int level = que.front().level;
            que.pop();
            if(level!=prevlevel)
            {
                //奇数层  奇数则false
                if(level%2==1&&nex->val%2==1)
                    return false;
                if(level%2==0&&nex->val%2==0)
                    return false;
                prevlevel = level;
                lastval = nex->val;
            }
            else{
                //奇数层 为奇数或递增则false
                if(level%2==1)
                {
                    if(nex->val%2==1||nex->val>=lastval)
                        return false;
                    lastval = nex->val;
                }
                //偶数层 为偶数或递减
                else{
                    if(nex->val%2==0||nex->val<=lastval)
                        return false;
                    lastval = nex->val;
                }
            }
            if(nex->left)
                que.push({nex->left,level+1});
            if(nex->right)
                que.push({nex->right,level+1});
        }
        return true;
    }
};
