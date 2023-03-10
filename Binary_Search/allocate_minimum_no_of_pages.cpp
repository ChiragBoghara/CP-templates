
class Solution 
{
    public:
    bool isValid(int arr[],int books,int k,int scheme){
        int students{1};
        int sum{0};
        
        for(int i=0;i<books;i++){
            sum+=arr[i];
            if(sum>scheme){
                students++;
                sum=arr[i];
            }
            if(students>k) return false;
        }
        
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //if students are greater than no of books then, we can't allocate
        if(M>N){
            return -1;
        }
        int start=-1;
        int end=-1;
        int maxVal{INT_MIN};
        int sum=0;
        for(int i=0;i<N;i++){
            maxVal=max(maxVal,A[i]);
            sum+=A[i];  
        }
        start=maxVal;
        end=sum;
        int res{-1};
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(isValid(A,N,M,mid)){
                end=mid-1;
                res=mid;
            }else{
                start=mid+1;
            }
        }
        
        return res;
    }
};
