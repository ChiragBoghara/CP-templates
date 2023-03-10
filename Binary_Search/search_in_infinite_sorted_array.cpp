// arr= 1 3 5 6 7 8 9 10 11 12 13 14 15 16..............♾

int low = 0;
int high = 1;
int key = 8;

while(key>arr[high]){
  low = high;
  high = high*2;
}

// here we have found valid low and high range where our key will fall
//(double the high until we found key between high and low)
// now do normal binary search 

binarySearch(arr,low,high);
