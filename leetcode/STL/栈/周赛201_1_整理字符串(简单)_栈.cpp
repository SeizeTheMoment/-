class Solution {
public:
    string makeGood(string s) {
        int N = s.length();
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<N;i++)
        {
            if(!st.empty())
            {
                char top = st.top();
                if(top+32==s[i]||top==s[i]+32)
                {
                    st.pop();
                    continue;
                }
            }
            
            st.push(s[i]);
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
