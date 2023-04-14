//Leetcode-2616
/*
You are given a 0-indexed integer array nums and an integer p. 
Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. 
Also, ensure no index appears more than once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.
*/

class Solution {
public:
    bool isItPossible(int diff,int p,vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=diff){
                p--;
                i++;
            }
        }
        return p<=0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        int start=0;
        int end=nums[nums.size()-1]-nums[0];
        int ans = end;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isItPossible(mid,p,nums)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }

        return ans;
    }
};