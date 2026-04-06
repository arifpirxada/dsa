class EventManager {
private:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mp;

public:
    EventManager(vector<vector<int>>& events) {
        for (int i = 0; i < events.size(); i++) {
            pq.push({events[i][1], -(events[i][0])});
            mp[events[i][0]] = events[i][1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, -eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()) {
            auto [priority, negId] = pq.top();
            int eventId = -negId;

            if (mp[eventId] == priority) {
                pq.pop();
                mp.erase(eventId);
                return eventId;
            }

            pq.pop();
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */