class Solution {
public:
    bool checkString(string s) {
        string t = s;
        sort(s.begin() , s.end());
        if(s == t) {
            return true;
        }
        return false;
    }
};