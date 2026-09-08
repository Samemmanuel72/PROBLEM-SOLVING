class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int>vec;
        if(nums.size() == 1) {
            vec.push_back(nums[0]);
            return vec;
        }
        
        for(int i = 1;i < nums.size();i++) {
            if(nums[i] - nums[i - 1] > 1 && i == 1) {
                vec.push_back(nums[i - 1]);
            }
            if(i < nums.size()-1 && nums[i] - nums[i - 1] > 1 && nums[i + 1] - nums[i] > 1) {
                vec.push_back(nums[i]);
            }
            if(i == nums.size() -  1) {
                if(nums[i] - nums[i - 1] > 1) {
                    vec.push_back(nums[i]);
                }
            }

        }
        return vec;
    }
};