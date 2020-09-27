class Solution {
public:
    unordered_set<string> st;
    int ans = 0;
    void dfs(string& s, int pos)
    {
        if(s.length()-pos+st.size()<=ans) return;
        if(pos==s.length())   
        {
            ans = max(ans,(int)st.size());
            return;
        }
        string temp;
        for(int i=pos;i<s.length();i++)
        {
            temp += s[i];
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                dfs(s,i+1);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        dfs(s,0);
        return ans;
    }
};
