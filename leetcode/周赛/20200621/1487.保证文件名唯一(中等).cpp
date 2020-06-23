class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        map<string, int> m;
        set<string> st;
        for(auto name: names)
        {
            if(st.find(name)==st.end())
            {
                st.insert(name);
                ans.push_back(name);
                m[name] = 1;
            }
            else{
                while(st.find(name+"("+to_string(m[name])+")")!=st.end())
                {
                    m[name]++;
                }
                string tmp = name+"("+to_string(m[name])+")";
                st.insert(tmp);
                ans.push_back(tmp);
                m[tmp] = 1;
                
            }
        }
        return ans;
    }
};