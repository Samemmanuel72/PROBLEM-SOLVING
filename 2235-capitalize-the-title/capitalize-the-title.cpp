class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        vector<string>vec;
        string word;
        while(ss >> word) {
            vec.push_back(word);
        }
        for(int i = 0;i < vec.size();i++) {
            for(int j = 0;j < vec[i].length();j++) {
                if(vec[i].length() == 1) {
                    vec[i][0] = tolower(vec[i][0]);
                    continue;
                }
                if(vec[i].length() == 2) {
                    vec[i][0] = tolower(vec[i][0]);
                    vec[i][1] = tolower(vec[i][1]);
                    continue;
                }
                if(islower(vec[i][0])) {
                    vec[i][0] = toupper(vec[i][0]);
                }
                if(j != 0 && isupper(vec[i][j])) {
                    vec[i][j] = tolower(vec[i][j]);
                }
            }
        }
        string t = "";
        for(int i = 0;i < vec.size();i++) {
            t = t + vec[i] + (i != vec.size()-1? " ": "");
        }
        return t;
        
    }
};