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
    vector<vector<int>> paths;
    void getPath(TreeNode* root, vector<int>& path)
    {
        path.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr)
        {
            paths.push_back(path);
        }
        if(root->left)
        {
            getPath(root->left,path);
        }
        if(root->right)
        {
            getPath(root->right,path);
        }
        path.pop_back();
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path;
        getPath(root,path);
        int ans = 0;
        for(auto path:paths)
        {
            unordered_map<int,int> m;
            for(int x:path)
            {
                m[x]++;
            }
            int N = path.size();
            int odd = 0;
            for(auto it=m.begin();it!=m.end();it++)
            {
                if(it->second&1==1)
                    odd++;
            }
             if(odd==0||(odd==1&&N&1==1))
                 ans++;
                 
        }
       
        return ans;
    }
};
