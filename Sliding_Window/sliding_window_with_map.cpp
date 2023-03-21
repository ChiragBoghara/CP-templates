class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int> m;
        long long ans = 0, s = 0, i = 0;
        
        for(int j=0; j<nums.size(); j++) {
            //doing calculations until hit the window
            m[nums[j]]++;
            s += nums[j];
            if(k == j - i + 1) {
                //window size hit
                //sum can only be considered when it is unique
                //calculate answer
                if(m.size() == k) ans = max(ans, s);
                //remove calculations
                s -= nums[i];
                m[nums[i]]--;
                if(m[nums[i]]==0) m.erase(nums[i]);
                //slide the window
                i++;
            }
        }
        return ans;
    }
};