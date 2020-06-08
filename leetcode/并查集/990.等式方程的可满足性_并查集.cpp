class Solution {
public:
    map<int,int> father;
    int Find(int x)
    {
        int r = x;
        while(father[r]!=r)
            r = father[r];
        int i = x;
        int j;
        while(father[i]!=i)
        {
            j = father[i];
            father[i] = r;
            i = j;
        }
        return r;
    }
    void Union(int x, int y)
    {
        int fx = Find(x);
        int fy = Find(y);
        //x,y,fx,fy
        if(fx<fy)
            father[fx] = fy;
        else father[fy] = fx;
    }
    bool equationsPossible(vector<string>& equations) {
        for(string equation:equations)
        {
            father[equation[0]-'a'] = equation[0]-'a';
            father[equation[3]-'a'] = equation[3]-'a';  
        }
        for(string equation : equations)
        {
            if(equation[1]=='=')
            {
                Union(equation[0]-'a',equation[3]-'a');
            }
           
        }
        for(string equation:equations)
        {
            if(equation[1]=='!')
            {
                if(Find(equation[0]-'a')==Find(equation[3]-'a'))
                     return false;
            }
        }
        return true;
    }
        
};
