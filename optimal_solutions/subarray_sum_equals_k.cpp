class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      //goal=5
      //--------7
      //----------------------12
      //if 12-5==7 find subarrays with sum 5 and added it to answer
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[0] = 1;
        for(auto it:nums){
            sum += it;
            int find = sum - k;
            if(mp.find(find) != mp.end()){
                ans += mp[find];
            }
            mp[sum]++;
        }
        return ans;
    }
};
