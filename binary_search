class Solution {
public:
    //works when array is sorted o(logn) TC
    //Change the conditions based on the array sorted in increasing or decreasing order
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        int index{-1};
        int mid;

        while(start <= end){
            //to overcome integer overflow
            mid = start + (end- start) /2;

            if(nums[mid]==target){
                index = mid;
                break;
            }else if(nums[mid] < target){
                start=mid+1;
            }else{
                end = mid -1;
            }
        }

        return index;
    }
    
};
