class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int area{INT_MIN};
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                int mini = min(height[i],height[j]);
                int diff = j-i;
                area = max(area,mini*diff);
            }
        }
        return area;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end = height.size()-1;
        int area{INT_MIN};

        //we will increment pointer with smaller height because it will not give better answer 
        //even if we will find smaller,greater or same height

        while(start<end){
            int mini = min(height[start],height[end]);
            int diff = end-start;
            area = max(area,mini*diff);
            if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }
        }
        return area;
    }
};