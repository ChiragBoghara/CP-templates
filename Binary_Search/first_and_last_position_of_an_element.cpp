class Solution {
public:
    int firstPos(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int first{-1};
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                //one possible answer
                first = mid;
                //search in left side for first occurence if has any
                end=mid-1;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return first;
    }
    int lastPos(vector<int>& nums, int target){
        int start=0;
        int end=nums.size()-1;
        int last{-1};
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]==target){
                //one possible answer
                last = mid;
                //search in left side for first occurence if has any
                start=mid+1;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstPos(nums,target);
        int last = lastPos(nums,target);

        vector<int> res;
        res.push_back(first);
        res.push_back(last);
        return res;
    }
};
