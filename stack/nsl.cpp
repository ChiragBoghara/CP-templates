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