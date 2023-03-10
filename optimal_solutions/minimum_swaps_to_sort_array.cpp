class Solution {
public:
    int minimumSwapsRequired( vector<int> v){
        //tc - N(logN)
        //sc - o(N)
        vector<int> temp(v.begin(),v.end());
        sort(temp.begin(),temp.end());
        int swaps{0};

        unordered_map<int,int> mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]]=i;
        }

        for(int i=0;i<v.size();i++){
            if(v[i]!=temp[i]){
                swaps++;
                int index = mp[temp[i]];
                swap(v[i],v[index]);

                mp[v[i]]=i;
                mp[v[index]]=index;
            }
        }
        return swaps;
    }
};