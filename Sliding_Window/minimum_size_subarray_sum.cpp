class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini{INT_MAX};
        int i=0,j=0;
        int sum{0};
        for(j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                mini=min(mini,j-i+1);
                sum-=nums[i++];
            }
        }

        return mini==INT_MAX?0:mini;
    }
};