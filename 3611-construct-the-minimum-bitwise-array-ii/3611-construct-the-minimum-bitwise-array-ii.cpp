class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
    
        vector<int> any(nums.size());
        for (int i =0; i <nums.size();i++){
            int position =0;
            int mask = 1;
            if ((nums[i] & (nums[i]-1)) == 0) {
                any[i] = -1;
                continue;
            }
            while (nums[i] & mask) {
                position++;
                mask <<= 1;
            }

             unsigned int one_before_zero = 0;
            if (position > 0) {
                one_before_zero = 1 << (position - 1);
            }
            any[i]=(~one_before_zero )& nums[i];
            
        }
        return any;
    }
};