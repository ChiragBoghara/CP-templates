vector<int> nextGreaterElements(vector<int>& nums) {
        //next greater element in circular array
        //Imagine the input array as a concatenation of the same array, twice. [1,2,3,4,3] -> [1,2,3,4,3]
        stack<int> st;
		vector<int> ans;
		for(int i=nums.size()-1;i>=0;i--)
		{
			st.push(nums[i]);
		}

		for(int i=nums.size()-1;i>=0;i--)
		{
			while(!st.empty() && st.top()<=nums[i])
			{
				st.pop();
			}
			if(st.empty())
			{
				ans.push_back(-1);
			}
			else
			{
				ans.push_back(st.top());
			}
			st.push(nums[i]);
		}
		reverse(ans.begin(),ans.end());
		return ans;
    }