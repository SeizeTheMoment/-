class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        string word;
        int ind = 1;
        int ans = -1;
        while(ss>>word)
        {
            int N = searchWord.length();
            if(strcmp(word.substr(0,N).c_str(),searchWord.c_str())==0)
            {
                ans = ind;
                break;
            }
            ind++;
        }
        return ans;
    }
};
