class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        int vis[V] {0};
        vis[0] = 1;
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int d = q.front();
            q.pop();
            ans.push_back(d);
            for(const auto &ele : adj[d]){
                if(vis[ele]!=1){
                    q.push(ele);
                    vis[ele]=1;
                }
            }
        }
        
        return ans;
    }
};