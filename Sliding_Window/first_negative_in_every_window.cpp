vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> ans;
    
    int  i=0;
    queue<long long> q;
    
    for(int j=0;j<N;j++){
        if(A[j] < 0){
            q.push(A[j]);
        }
        if(j-i+1 == K){
            //window size hit
            //negative number is there
            //calculate the answer
            if(q.empty()){
                ans.push_back(0);
            }else{
                int num = q.front();
                ans.push_back(num);
                //slide the window
                if(q.front()==A[i]){
                    q.pop();
                }
            }
            //slide the window
            i++;
        }
    }
    
    return ans;
 }