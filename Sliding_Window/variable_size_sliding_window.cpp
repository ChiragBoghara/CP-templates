class Solution{
  public:
  //Longest K unique characters substring
  //aabacbebebe k=3
  //pick toys 
    int longestKSubstr(string s, int k) {
        int maxLen{-1};
        //condition=k unique characters
        unordered_map<char,int> mp;
        
        int start=0,end=0;
        int size = s.size();
        for(end=0;end<size;end++){
            mp[s[end]]++;
            if(mp.size()==k){
                //window size hit
                maxLen=max(maxLen,end-start+1);
            }else if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[start]]--;
                    if(mp[s[start]]==0){
                        mp.erase(s[start]);
                    }
                    start++;
                }
            }
        }
        return maxLen;
    }
    //Longest unique characters substring
    //or longest substring without repeting characters
    //variable size sliding window== 
    //1.<k
    //2.==k
    //3.>k
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }

        int maxi{INT_MIN};
        int i=0,j=0;
        unordered_map<char,int> mp;

        for(j=0;j<s.size();j++){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                maxi=max(maxi,j-i+1);
            }else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
        }   
        return maxi;
    }
};