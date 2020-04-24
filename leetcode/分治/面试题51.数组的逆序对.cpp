class Solution {
public:
    int merge_count(vector<int>& a)
    {
        int N = a.size();
        if(N<=1)
            return 0;
        int cnt = 0;
        vector<int> vec1;
        vector<int> vec2;
        for(int i=0;i<N/2;i++)
            vec1.push_back(a[i]);
        for(int i=N/2;i<N;i++)
            vec2.push_back(a[i]);
        cnt += merge_count(vec1);
        cnt += merge_count(vec2);
        int pi=0;
        int pj=0;
        int pk=0;
        while(pk<N)
        {
            if(vec1[pi]<vec2[pj])
            {
                a[pk++] = vec1[pi++];
            }
            else{
                cnt += N/2 - pi;
                a[pk++] = vec2[pj++];
            }
        }
        while(pi<vec1.size())
        {
            a[pk++] = vec1[pi++];
        }
        while(pj<vec2.size())
        {
            cnt += N/2 - pi;
            a[pk++] = vec2[pj++];
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int N = nums.size();
        if(N<=1)
            return 0;
        return merge_count(nums);
    }
};