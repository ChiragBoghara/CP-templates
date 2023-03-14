
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int arr[], int n)
    {
        //next greater left index
        //price[] = [100 80 60 70 60 75 85]
        //Output:
        //1 1 1 2 1 4 6
        vector<int> indexAns;
        stack<pair<int,int>> temp;
        
        for(int i=0;i<n;i++){
            if(temp.empty()){
                indexAns.push_back(-1);
                temp.push({arr[i],i});
            }else{
                //stack is not empty
                if(temp.top().first > arr[i]){
                    indexAns.push_back(temp.top().second);
                    temp.push({arr[i],i});
                }else{
                    //>=
                    while(!temp.empty() && temp.top().first <= arr[i]){
                        temp.pop();
                    }
                    if(temp.empty()){
                        indexAns.push_back(-1);
                    }else{
                        indexAns.push_back(temp.top().second);
                    }
                    temp.push({arr[i],i});
                }
            }
        }
        
        int t = 0;
        
        for(auto &i : indexAns){
            i = t-i;
            t++;
        }
        
        return indexAns;
    }
};