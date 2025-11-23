class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0 ; 
        int right = nums.size()-1;
        while (left <= right ){
            int min = left + (right - left)/2;
            if (nums[min]== target)
                return  min;
            if (nums[min]<target)
                left = min +1;
            else 
                right = min -1;
            
        }
        return left; 
    }
};