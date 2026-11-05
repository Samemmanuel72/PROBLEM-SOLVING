class Solution {
public:
    int digitsum(int n) {
        int t = n;
        int sum = 0;
        while(t > 0) {
            int tt = t % 10;
            sum += tt;
            t = t / 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        
        for(int i = 0;i < (int)nums.size();i++) {
            if(digitsum(nums[i]) == i) {
                return i;
            }
        }
        return -1;
    }
};