class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> st;
        vector<string> ans;
        int now = 1;
        int ind = 0;
        int N = target.size();
        while(ind<N)
        {
            if(now==target[ind])
            {
                ans.push_back("Push");
                ind++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            now = now%n+1;
        }
        return ans;
    }
};

