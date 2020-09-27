class Solution {
public:
    string reorderSpaces(string text) {
        int N = text.length(); 
        int cnt = 0;
        for(int i=0;i<N;i++)
        {
            if(text[i]==' ')
                cnt++;
        }
        istringstream ss(text);
        vector<string> strs;
        string s;
        string ans;
        while(ss>>s)
        {
            strs.push_back(s);
        }
        if(strs.size()<=1)
        {
            for(int i=0;i<cnt;i++)
            {
                s+=' ';
            }
            return s;
        }
        int avg = cnt/(strs.size()-1);
        int remain = cnt%(strs.size()-1);
        string spaces;
        for(int i=0;i<avg;i++)
            spaces += ' ';
        for(int i=0;i<strs.size();i++)
        {
            if(i!=0)
                ans += spaces;
            ans += strs[i];
        }
        for(int i=0;i<remain;i++)
            ans += ' ';
        return ans;
    }
};
