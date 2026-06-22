class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        auto& values = timeMap[key];
        int left = 0, right = values.size() - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

private:
    unordered_map<string, vector<pair<int, string>>> timeMap;

};
