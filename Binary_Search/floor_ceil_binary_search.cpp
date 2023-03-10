int searchFloor(int arr[], int n, int x){
    int start=0;
    int end = n-1;
    
    // 5 5 5 6 6 6 8 9
    //floor = greatest smaller number
    //ceil  = smallest greater number
    int res{-1};
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==x){
            return arr[mid];
        }
        if(arr[mid]<x){
            res=arr[mid];
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return res;
}

int searchCeil(int arr[], int n, int x){
    int start=0;
    int end = n-1;
    
    // 5 5 5 6 6 6 8 9
    int res{-1};
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==x){
            return arr[mid];
        }
        if(arr[mid]<x){
            start=mid+1;
        }else{
            res=arr[mid];
            end=mid-1;
        }
    }
    return res;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr,arr+n);
    
    int f = searchFloor(arr,n,x);
    int c = searchCeil(arr,n,x);
    
    pair<int, int> p;
    p.first=f;
    p.second=c;
    
    return p;
}
