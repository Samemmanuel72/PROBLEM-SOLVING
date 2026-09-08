class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mpp;
        
       
        for (const string& word : arr) {
            mpp[word]++;
        }
        
    
        for (const string& word : arr) {
            if (mpp[word] == 1) {
                k--;
                if (k == 0) {
                    return word;
                }
            }
        }
        
        return "";
    }
};