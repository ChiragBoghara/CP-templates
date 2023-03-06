class Solution {
public:
    bool isShippable(vector<int>& weights,int days,int capacity){
        int ans{0};
        int sum{0};
        for(const auto &e : weights){
            sum+=e;
            if(sum>capacity){
                sum=e;
                ans++;
            }
        }
        ans++;
        return ans<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(),weights.end());
        int end{0};
        for(const auto &e : weights) end+=e;
        int res{-1};

        while(start<=end){
            int mid = start +(end-start)/2;

            if(isShippable(weights,days,mid)){
                res = mid;
                end= mid-1;
            }else{
                start=mid+1;
            }
        }       

        return res;
    }
};
