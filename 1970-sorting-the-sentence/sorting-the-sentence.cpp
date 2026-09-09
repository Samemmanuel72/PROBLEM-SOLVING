class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;
        vector<string>vec1;
        while(ss >> word) {
            vec1.push_back(word);
        }
        vector<string>vec2(10);
        for(int i = 0;i < vec1.size();i++) {
            char ch = vec1[i][vec1[i].length() - 1];
            int idx = ch - '0';
            vec1[i].pop_back();
            vec2[idx] = vec1[i];
        }
        string t = "";
        for(int i = 1;i <= vec1.size();i++) {
            t = t + vec2[i] + (i != vec1.size() ? " " : "");
        }
        return t;

    }
};