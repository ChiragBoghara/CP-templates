class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &Arr , int N){
        long maxSum = INT_MIN;
        int windowStart = 0;
        long windowSum = 0;

        for(int windowEnd = 0; windowEnd < N; windowEnd++) {
            windowSum += Arr[windowEnd]; 
            // Add the next element to the window
            
            if(windowEnd-windowStart+1 == k) { 
                // When we hit the window size. Update maximum sum, and slide the window
                maxSum = max(maxSum, windowSum);
                windowSum -= Arr[windowStart]; 
                // Subtract the element going out of the window (remove calculations)
                windowStart++; // Slide the window
            }
        }

        return maxSum;
    }
};