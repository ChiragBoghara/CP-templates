class Solution {
public:
    int trap(vector<int>& arr) {
        int size = arr.size();
        vector<int> leftMax(size);
        vector<int> rightMax(size);

        leftMax[0] = arr[0];
        rightMax[size-1] = arr[size-1];
        
        for(int i=1;i<size;i++){
            leftMax[i] = max(leftMax[i-1],arr[i]);
        }
        for(int i=size-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],arr[i]);
        }
        int sum = 0;
        for(int i=0;i<leftMax.size();i++){
            sum+=(min(leftMax[i],rightMax[i]) - arr[i]);
        }
        return sum;
    }
};