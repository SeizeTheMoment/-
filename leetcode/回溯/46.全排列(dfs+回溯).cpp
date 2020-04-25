class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> vec,vector<int>& tmp, int ind, vector<bool>& visited)
    {
        tmp.push_back(vec[ind]);
        if(tmp.size()==vec.size())
        {
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        visited[ind] = true;
        for(int i=0;i<vec.size();i++)
        {
            if(!visited[i])
            {
                dfs(vec,tmp,i,visited);
                visited[i] = false;
            }
        }
        tmp.pop_back();
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        vector<int> tmp;
        for(int i=0;i<nums.size();i++)
        {
            vector<bool> visited;
            visited.resize(nums.size());
            tmp.clear();
            dfs(nums,tmp,i,visited);
        }
        return ans;
    }
};
