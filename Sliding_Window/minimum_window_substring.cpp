//1.Use two pointers to create a window of letters in s, 
//which would have all the characters from t.
//2.Expand the right pointer until all the characters of t are covered.
//3.Once all the characters are covered, move the left pointer and 
//ensure that all the characters are still covered to minimize the subarray size.
//4.Continue expanding the right and left pointers until you reach the end of s.

//variable size sliding window
class Solution {
public:
    string minWindow(string s, string t) {
        int i=0,j=0;
        int counter{0};
        unordered_map<char,int> mp;
        for(const auto &e : t){
            mp[e]++;
        }
        counter=mp.size();
        string res{""};
        int minSize{INT_MAX};

        for(j=0;j<s.size();j++){
            //doing calculations
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]]==0) counter--;
            }
            if(counter==0){
                //window size hit //can be my possible answer
                while(counter==0){
                    //negative (<0) means extra character is there
                    if(mp.count(s[i]) && mp[s[i]]<0){
                        mp[s[i]]++;
                        i++;
                    }
                    else if(mp.count(s[i]) && mp[s[i]]==0){
                        break;
                    }
                    else i++;
                }
                if(minSize>j-i+1){
                    minSize=j-i+1;
                    res=s.substr(i,j-i+1);
                }
            }
        }
        return res;
    }
};