/**
 * In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
 */

/**
 * 使用一个数组保存有人的位置，再用一个Index保存目前下一个有人的序号
 */

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> has_person;
        for(int i = 0; i < seats.size(); ++i) {
            if(seats[i] == 1) has_person.push_back(i);
        }
        int last_person = -1, next_person_index = 0, max_dist = 0;
        for(int i = 0; i < seats.size(); ++i) {
            int next_person = next_person_index == has_person.size() ? seats.size() : has_person[next_person_index];
            if(next_person == i) {
                last_person = next_person;
                ++next_person_index;
                continue;
            }
            // left length
            int temp_max_size = INT_MAX;
            if(last_person >= 0) temp_max_size = i - last_person;
            if(next_person < seats.size()) temp_max_size = std::min(temp_max_size, next_person - i);
            if(temp_max_size != INT_MAX) max_dist = std::max(max_dist, temp_max_size);
        }
        return max_dist;
    }
};