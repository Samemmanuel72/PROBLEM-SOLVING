
class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        
        int left_max = 0;
        int right_max = 0;
        
        int total_water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                // If current height is greater than left_max, update it
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    // Water trapped is the boundary minus current height
                    total_water += left_max - height[left];
                }
                left++;
            } else {
                // If current height is greater than right_max, update it
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    // Water trapped is the boundary minus current height
                    total_water += right_max - height[right];
                }
                right--;
            }
        }
        
        return total_water;
    }
};
