class Solution {
public:
    static bool cmp(pair<string,int> p1,pair<string,int> p2)
    {
        if(p1.first.length()==p2.first.length())
            return p1.second<p2.second;
        return p1.first.length()<p2.first.length();
    }
    string arrangeWords(string text) {
        istringstream ss(text);
        string str;
        string ans;
        vector<pair<string,int> > vec;
        int ind = 0;
        while(ss>>str)
        {
            if(str[0]<=90)
                str[0]+=32;
            vec.push_back(make_pair(str,ind++));
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<vec.size();i++)
        {
            if(i!=0)
                ans+=" ";
            string tmp = vec[i].first;
            if(i==0)
            {
                if(tmp[0]>=97)
                    tmp[0]-=32;
            }
            ans+=tmp;
        }
        return ans;
    }
};
