class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        map<int,int> pos;
        string str;
        int n = indices.size();
        for(int i=0;i<n;i++)
        {
            pos[indices[i]] = i;
        }
        for(int i=0;i<n;i++)
        {
            str+=s[pos[i]];
        }
        return str;
    }
};
