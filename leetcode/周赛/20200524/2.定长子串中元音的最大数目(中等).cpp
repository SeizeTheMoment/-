class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> vowel;
        char ch[6] = "aeiou";
        for(int i=0;i<5;i++)
            vowel.insert(ch[i]);
        int N = s.length();
        int maxi = -1;
        int tmp = 0;
        for(int i=0;i<k;i++)
            if(vowel.find(s[i])!=vowel.end())
                tmp++;
        maxi = max(maxi,tmp);
        for(int i=1;i+k-1<N;i++)
        {
            int j = i+k-1;
            if(vowel.find(s[i-1])!=vowel.end())
                tmp--;
            if(vowel.find(s[j])!=vowel.end())
                tmp++;
            maxi = max(maxi,tmp);
        }
        return maxi;
    }
};
