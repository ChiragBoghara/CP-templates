class Solution {
public:
    void nextSmallerLeft(vector<int> heights,vector<int> &left){
        stack<pair<int,int>> temp;

        for(int i=0;i<heights.size();i++){
            if(temp.empty()){
                left.push_back(-1);
                temp.push({heights[i],i});
            }else{
                //stack is not empty
                while(!temp.empty() && temp.top().first>= heights[i]){
                    temp.pop();
                }

                if(temp.empty()){
                    left.push_back(-1);
                    temp.push({heights[i],i});
                }else{
                    left.push_back(temp.top().second);
                    temp.push({heights[i],i});
                }
            }
        }
    }

    void nextSmallerRight(vector<int> heights,vector<int> &right){
        stack<pair<int,int>> temp;

        for(int i=heights.size()-1;i>=0;i--){
            if(temp.empty()){
                right.push_back(heights.size());
                temp.push({heights[i],i});
            }else{
                //stack is not empty
                while(!temp.empty() && temp.top().first>= heights[i]){
                    temp.pop();
                }

                if(temp.empty()){
                    right.push_back(heights.size());
                    temp.push({heights[i],i});
                }else{
                    right.push_back(temp.top().second);
                    temp.push({heights[i],i});
                }
            }
        }   

        reverse(right.begin(),right.end());
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        vector<int> width;
        vector<int> area;

        nextSmallerLeft(heights,left);
        nextSmallerRight(heights,right);

        for(int i=0;i<left.size();i++){
            width.push_back(right[i]-left[i]-1);
        }

        for(int i=0;i<heights.size();i++){
            area.push_back(width[i] * heights[i]);
        }

        return *max_element (area.begin(),area.end());
    }
};  