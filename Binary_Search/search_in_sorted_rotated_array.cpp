class Solution {
public:
    int findPivotIndex(vector<int> nums) {
        int n = nums.size();
	    int start = 0;
	    int end = n-1;
	    while(start<=end){
		if(nums[start]<=nums[end]){
			return start;
		}
		int mid = start + (end-start)/2;
		int prev = (mid+n-1)%n;
		int next = (mid+1)%n;

		if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
			return mid;
		}
		if(nums[start]<=nums[mid]){
			start=mid+1;
		}else if(nums[mid]<=nums[end]){
			end=mid-1;
		}
	    }
	    return 0; 
	}

    int binarySearch(vector<int>& nums,int start,int end,int goal){
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==goal){
                return mid;
            }
            if(goal<nums[mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot = findPivotIndex(nums);
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            //search in rightside
            return binarySearch(nums,pivot,nums.size()-1,target);
        }else{
            //search in leftside
            return binarySearch(nums,0,pivot-1,target);
        }
    }
};
