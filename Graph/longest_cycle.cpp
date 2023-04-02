class Solution {
public: 
//How many cycles can each node at most be part of where each node has at most one outgoing edge?
//Each node can be part of at most one cycle. Start from each node and 
//find the cycle that it is part of if there is any. 
//Save the already visited nodes to not repeat visiting the same cycle multiple times.
    void dfs(int node,vector<int>& visited,vector<int>& edges,unordered_map<int,int>& mp,int &ans){
        visited[node]=1;
        int neighbour = edges[node];

        if(neighbour!=-1 && !visited[neighbour]){
            mp[neighbour]=(mp[node]+1);
            dfs(neighbour,visited,edges,mp,ans);
        }else if (neighbour != -1 && mp.count(neighbour)){
            ans = max(ans,(mp[node]-mp[neighbour]+1));
        }
    }
    int longestCycle(vector<int>& edges) {
        int size = edges.size();
        vector<int> visited(size,0);
        int ans{INT_MIN};

        for(int i=0;i<size;i++){
            if(!visited[i]){
                unordered_map<int,int> mp;
                mp[i]=1;
                dfs(i,visited,edges,mp,ans);
            }
        }

        return ans==INT_MIN?-1:ans;
    }
};