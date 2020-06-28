class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> s;
        int curx = 0;
        int cury = 0;
        s.insert(make_pair(curx,cury));
        for(int i=0;i<path.length();i++)
        {
            char op = path[i];
            if(op=='N'){
                curx++;
            }
            else if(op=='S'){
                curx--;
            }
            else if(op=='E'){
                cury++;
            }
            else{
                cury--;
            }
            if(s.find(make_pair(curx,cury))!=s.end())
            {
                return true;
            }
            //cout<<curx<<" "<<cury<<endl; 
            s.insert(make_pair(curx,cury));
        }
        return false;
    }
};
