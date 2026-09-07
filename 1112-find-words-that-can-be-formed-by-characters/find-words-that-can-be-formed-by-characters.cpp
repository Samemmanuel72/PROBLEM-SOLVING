class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>charmpp(26, 0);
        for(char ch : chars) {
            charmpp[ch - 'a']++;
        }
        long long ans = 0;
        vector<int>freq(26, 0);
        for(string word : words) {
            for(char ch : word) {
                freq[ch - 'a']++;
            }
            bool istrue = true;
            for(char ch = 'a'; ch <= 'z';ch++) {
                if(charmpp[ch - 'a'] < freq[ch - 'a']) {
                    istrue = false;
                    break;
                }
            }
            if(istrue) {
                ans = ans + word.length();
            }
            for(int i = 0;i < 26;i++) {
                freq[i] = 0;
            }
        }
        return ans;
    }
};