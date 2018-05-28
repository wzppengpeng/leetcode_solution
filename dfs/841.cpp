/**
 * There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0). 

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:

Input: [[1],[2],[3],[]]
Output: true
Explanation:  
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
Example 2:

Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
 */

/**
 * 使用一个集合来保存没有来过的房间，然后dfs遍历即可，注意不用退出当前房间
 */


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> not_visit;
        for(int i = 0; i < rooms.size(); ++i) not_visit.emplace(i);
        return can_visite(rooms, 0, not_visit);
    }

    bool can_visite(const vector<vector<int>>& rooms, int room, unordered_set<int>& not_visit) {
        if(not_visit.count(room) == 0) return false;
        not_visit.erase(room);
        if(not_visit.empty()) return true;
        const auto& next = rooms[room];
        bool is_can = false;
        for(auto n : next) {
            is_can |= can_visite(rooms, n, not_visit);
        }
        return is_can;
    }
};