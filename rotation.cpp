class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    int start = 0;
	    int end = n-1;
	    
	    //index of the minimum element would be our answer
	    //so somehow we have to find minimum element
	    //mid would be our answer if it is smaller than both of its neighbours
	    //if it is not we have to cancel one part and has to go on another part
	    //our answer would be in unsorted part
	    
	    while(start<=end){
	        	    
    	    //if first element is smaller than last element it means already sorted
    	    if(nums[start]<=nums[end]){
    	        return start;
    	    }
	        int mid = start + (end-start)/2;
	        int prev = (mid+n-1)%n;
	        int next = (mid+1)%n;
	        
	        if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return mid;
            }
            if(nums[start]<=nums[mid]){
                start=mid+1;
            }else if(nums[mid]<=nums[end]){
                end=mid-1;
            }
	    }
	    
	    return 0; 
	}

};
