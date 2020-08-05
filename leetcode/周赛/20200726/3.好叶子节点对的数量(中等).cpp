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
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
    //return 该节点与叶子节点的距离数组
    vector<int> dfs(TreeNode* root, int distance, int &ans)
    {
        //空
        if(root==nullptr)
            return {};
        //叶子节点
        //就返回{0}，代表有距离一个叶子节点的距离为0
        if(root->left==nullptr&&root->right==nullptr)
            return {0};
        vector<int> ret;
        //左子树的距离数组
        vector<int> le = dfs(root->left, distance, ans);
        for(int& e : le)
        {
            e++;
            //跳过距离超过distance的节点
            if(e>distance)
                continue;
            //将新距离推入vector
            ret.push_back(e);
        }
        //右子树距离数组 
        vector<int> ri = dfs(root->right, distance, ans);
        for(int& e: ri)
        {
            e++;
            if(e>distance)
                continue;
            ret.push_back(e);
        }
        //遍历左子树距离和右子树距离数组，最短路径为两个距离之和
        for(int l : le)
            for(int r : ri)
                ans += ((l+r)<=distance);
        return ret;
    }
};
