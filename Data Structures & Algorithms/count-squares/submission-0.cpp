class CountSquares {
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        if (point.size() != 2)
            return;

        pointCounter[point[0]][point[1]]++;
        if (pointCounter[point[0]][point[1]] == 1)
            pointTracker.push_back({point[0], point[1]});
    }
    
    int count(vector<int> point) {
        int squareTracker = 0;
        if (point.size() != 2)
            return squareTracker;

        for (auto& addedPoint: pointTracker) {
            if (abs(point[0] - addedPoint.first) != abs(point[1] - addedPoint.second) || point[0] == addedPoint.first)
                continue;

            int corner1 = pointCounter[addedPoint.first][addedPoint.second];
            int corner2 = 0;
            if (pointCounter.count(addedPoint.first)) {
                if (pointCounter[addedPoint.first].count(point[1])) {
                    corner2 = pointCounter[addedPoint.first][point[1]];
                }
            }
            int corner3 = 0;
            if (pointCounter.count(point[0])) {
                if (pointCounter[point[0]].count(addedPoint.second)) {
                    corner3 = pointCounter[point[0]][addedPoint.second];
                }
            }
            if (corner1 != 0 && corner2 !=0 && corner3 != 0) {
                squareTracker = squareTracker + (corner1 * corner2 * corner3);
            }
        }

        return squareTracker;
    }

private:
    vector<pair<int, int>> pointTracker;
    unordered_map<int, unordered_map<int, int>> pointCounter;
};
