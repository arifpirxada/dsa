// https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
private:
    vector<string> history;
    int index = 0;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
    }
    
    void visit(string url) {
        history.resize(index + 1);
        history.push_back(url);
        index = history.size() - 1;
    }
    
    string back(int steps) {
        index = max(0, index - steps);
        return history[index];
    }
    
    string forward(int steps) {
        index = min(index + steps, static_cast<int>(history.size()) - 1);
        return history[index];
    }
};