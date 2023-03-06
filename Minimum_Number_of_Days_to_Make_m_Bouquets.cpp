class Solution {
public:
    bool isPossible(vector<int>& bloomDay,int m,int k,int mid){
        int bouquets = 0, flowersCollected = 0;
        for (const auto& value : bloomDay) {
            if (value <= mid) {
                flowersCollected++;
            } else {
                flowersCollected = 0;
            }
            if (flowersCollected == k) {
                bouquets++;
                flowersCollected = 0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int res{-1};
        while(start<=end){
            int mid = start+(end-start)/2;

            if(isPossible(bloomDay,m,k,mid)){
                res=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        };
        return res;
    }
};
