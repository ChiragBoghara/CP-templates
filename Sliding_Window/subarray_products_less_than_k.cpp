class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0;
        long prod = 1;
        int count =0;
        for(int end =0; end< nums.size(); end++){
            prod *= nums[end];
            //if subarray is not valid make it valid and get answer
            while(prod>=k && start<nums.size()){
                prod/=nums[start];
                start++;
            }
            if(prod<k){
                //window size hit
                count+=(end-start+1);
            }
        }
        return count;
    }
};