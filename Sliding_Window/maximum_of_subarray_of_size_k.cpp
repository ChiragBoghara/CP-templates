class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        int start=0,end=0;
        int maxi{INT_MIN};
        vector<int> v;
        list<int> l;
        
        for(end=0;end<n;end++){
            //doing calculations
            while(l.size()>0 && l.back()<arr[end]){
                l.pop_back();
            }
            l.push_back(arr[end]);
            if(end-start+1==k){
                //window size hit
                //calculate answer
                v.push_back(l.front());
                //remove calculations
                if(l.front() == arr[start]){
                    l.pop_front();
                }
                //slide the window
                start++;
            }
        }
        return v;
    }
};