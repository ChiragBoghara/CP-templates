 vector<int> nextGreaterLeftElement(vector<int> arr, int n){
        vector<int> ans;
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                ans.push_back(-1);
                st.push(arr[i]);
            }else{
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
        
        return ans;
    }