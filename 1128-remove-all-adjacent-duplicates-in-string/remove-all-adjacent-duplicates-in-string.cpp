class Solution {
public:
    string removeDuplicates(string s) {
        stack<int>st;
        string ans = "";
        for(char ch : s) {
            if(st.empty()) {
                st.push(ch);
            }else{
                if(ch == st.top()) {
                    st.pop();
                }else{
                    st.push(ch);
                }
            }

        }
        while(!st.empty()) {
            
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};