/**
 * At a lemonade stand, each lemonade costs $5.

Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

Note that you don't have any change in hand at first.

Return true if and only if you can provide every customer with correct change.
 */

/**
 * 主要是20元找零时注意，虽然有两种解决方案，但是优先找零一张五元加一张十元
 */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_num = 0, ten_num = 0;
        for(auto bill : bills) {
            if(bill == 5) {
                ++five_num;
            } else if(bill == 10) {
                if(five_num == 0) return false;
                ++ten_num;
                --five_num;
            } else {
                if(five_num > 0 && ten_num > 0) {
                    --ten_num;
                    --five_num;
                } else if(five_num >= 3) {
                    five_num -= 3;
                } else return false;
            }
        }
        return true;
    }
};