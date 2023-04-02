//DFS
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detectCycle(int src,int parent,vector<int> adj[],int visited[]){
       visited[src] = 1;
       
       for(auto &ele : adj[src]){
           if(visited[ele]!=1){
                if(detectCycle(ele,src,adj,visited)){
                    return true;
                }
           }else{
               if(ele!=parent){
                   return true;
               }
           }
       }
       
       return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int visited[V] {0};
        
        for(int i=0;i<V;i++){
            if(visited[i]!=1){
                if(detectCycle(i,-1,adj,visited) == true){
                    return true;
                }
            }
        }
        return false;
    }
};



//BFS
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int i,int parent,vector<int> adj[],vector<int>&visited){
        queue<pair<int,int>> q;
        //node,parent
        q.push({i,-1});
        visited[i]=1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(const auto &e : adj[node]){
                if(!visited[e]){
                    visited[e]=1;
                    q.push({e,node});
                }else{
                    if(parent != e){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect(i,-1,adj,visited)){
                    return true;
                }
            }
        }
        
        return false;
    }
};