/**
 * Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 */


class MyCalendar {
public:
    map<int, int> log;
    MyCalendar() {
        log.clear();
    }

    bool book(int start, int end) {
        if(log.find(start)!=log.end()) return false;
        map<int, int>::iterator l, r;
        l=log.lower_bound(start);
        r=log.upper_bound(start);
        if(l==log.begin()) l=log.end();
        else l--;
        if(l!=log.end()&&l->second>start) return false;
        if(r!=log.end()&&r->first<end) return false;
        log[start]=end;
        return true;
    }

};