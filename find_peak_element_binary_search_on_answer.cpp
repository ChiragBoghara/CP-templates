class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //binary search on answer
        //sometimes binary search also works when array is not sorted
        //somehow we have to figured out two things
        //1) our mid is anwwer or not
        //2) if mid is not answer on which side(left|right) our answer can be
        // based on some criteria given in the question
      
        //in this question mid can be answer when it is greater than both of its neighbour (mid-1,mid+1)
        int start=0;
        int size = nums.size();
        int end = size-1;
        if(size==1){
            return 0;
        }

        while(start<=end){
            int mid = start+(end-start)/2;
            if(mid>0 && mid<size-1){
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return mid; 
                }
                if(nums[mid-1] >nums[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else if(mid==0){
                return nums[0]>nums[1] ? 0 : 1;
            }else{
                //mid==size-1
                return nums[size-1]>nums[size-2] ? size-1 : size-2;
            }
        }

        return -1;
    }
};
