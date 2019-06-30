/**
 * Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.
 */

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream stream(text);
        string temp;
        bool start=false, ready=false;
        vector<string> res;
        while(stream>>temp)
        {
            if(ready) {res.push_back(temp);ready=false;}
            if(start&&temp==second) ready=true;
            if(temp==first) start=true;
            else start=false;   
        }
        return res;
    }
};