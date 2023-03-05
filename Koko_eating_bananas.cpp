class Solution {
public:
    bool isValid(vector<int>& piles, int limit,int speed){
        long long time{0};
        for(int i=0;i<piles.size();i++){
            time += (piles[i]/speed)+ ((piles[i]%speed)!=0);
        }
        if(time<=limit){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start=1;
        int end= *max_element(piles.begin(),piles.end());

        int res=-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(piles,h,mid)){
                res = mid;
                end =mid-1;
            }else{
                start=mid+1;
            }
        }

        return res;
    }
};
