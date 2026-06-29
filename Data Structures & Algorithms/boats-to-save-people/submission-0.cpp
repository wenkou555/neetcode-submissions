class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;

        while (left <= right) {
            // If the lightest kid fits with the heaviest guy, take the kid too
            if (people[left] + people[right] <= limit) {
                left++;
            }
            
            // The heaviest guy gets on a boat regardless
            right--; 
            boats++;
        }

        return boats;
    }
};