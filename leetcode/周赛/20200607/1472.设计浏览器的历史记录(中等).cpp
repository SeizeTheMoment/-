class BrowserHistory {
public:
    vector<string> pages;
    int cur;
    BrowserHistory(string homepage) {
        pages.push_back(homepage);
        cur = 0;
    }
    void visit(string url) {
        int N = pages.size();
        for(int i=cur+1;i<N;i++)
            pages.pop_back();
        pages.push_back(url);
        cur = cur+1;
    }
    string back(int steps) {
        if(cur-steps<0)
            cur = 0;
        else cur = cur - steps;
        return pages[cur];
    }
    string forward(int steps) {
        if(cur+steps>pages.size()-1)
            cur = pages.size()-1;
        else cur = cur+steps;
        return pages[cur];
    }
};