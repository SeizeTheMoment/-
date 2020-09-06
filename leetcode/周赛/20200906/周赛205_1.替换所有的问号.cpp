class Solution {
public:
    string modifyString(string s) {
        int N = s.length();
        for(int i=0;i<N;i++)
        {
            if(s[i] != '?')
                continue;
            char c = 'a';
            while(i&&s[i-1]==c||i<N-1&&s[i+1]==c) ++c;
            s[i] = c;
        }
        return s;
    }
};
