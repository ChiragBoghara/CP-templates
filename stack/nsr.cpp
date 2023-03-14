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