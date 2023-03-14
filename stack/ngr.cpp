 vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans;
        stack<long long> st;
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                //stack is empty
                ans.push_back(-1);
                st.push(arr[i]);
            }else{
                //stack is not empty
                while(!st.empty() && st.top()<=arr[i]){
                    st.pop();
                }
                    
                if(st.empty()){
                    ans.push_back(-1);
                }else{
                   ans.push_back(st.top());
                }
                st.push(arr[i]);
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }