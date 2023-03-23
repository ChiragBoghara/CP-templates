//Given an array of integers nums and an integer k. 
//A continuous subarray is called nice if there are k odd numbers on it.
//Return the number of nice sub-arrays.

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0;
        int odds{0};
        unordered_map<int,int> mp;
        mp[0]=1;
        int counter{0};
        for(j=0;j<nums.size();j++){
            if(nums[j]%2!=0){
                odds++;
            }
            int key=odds-k;
            if(mp.count(key)){
                counter+=mp[key];
            }
            mp[odds]++;
        }
        return counter;
    }
};