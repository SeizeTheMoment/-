class Solution {
public:
    int findmin(vector<int>& numbers, int le, int ri)
    {
        int result = numbers[le];
        for(int i=le+1; i<=ri; i++)
            if(result > numbers[i])
                result = numbers[i];
        return result;
    }
    int minArray(vector<int>& numbers) {
        int N = numbers.size();
        int le = 0;
        int ri = N-1;
        int mid = le;
        while(numbers[le] >= numbers[ri])
        {
            if(ri-le == 1)
            {
                mid = ri;
                break;
            }
            mid = (ri+le)/2;
            if(numbers[le]==numbers[ri]&&numbers[mid]==numbers[le])
                return findmin(numbers, le, ri);
            if(numbers[mid]>=numbers[le])
                le = mid;
            else if(numbers[mid]<=numbers[ri])
                ri = mid;
        }
        return numbers[mid];

    }
};
