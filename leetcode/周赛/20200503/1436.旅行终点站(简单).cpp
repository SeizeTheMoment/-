class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> graph;
        for(int i=0;i<paths.size();i++)
        {
            graph[paths[i][0]] = paths[i][1];
        }
        //return graph["New York"];
        for(int i=0;i<paths.size();i++)
        {
            if(graph.find(paths[i][0])==graph.end())
                return paths[i][0];
            if(graph.find(paths[i][1])==graph.end())
                return paths[i][1];
        }
        return paths[paths.size()-1][1];
    }
};
