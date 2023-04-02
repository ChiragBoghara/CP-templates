class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node,vector<int> adj[],int visited[],stack<int> &st)
	{
	    visited[node] = 1;
	   
        for(auto &ele : adj[node]){
            if(visited[ele] != 1){
                //not visited
                dfs(ele,adj,visited,st);
            }
        }
        st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    int visited[V] {0};
	    
	    for(int i=0;i<V;i++){
	        if(visited[i]!=1){
	            dfs(i,adj,visited,st);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};


//BFS
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegrees(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(const auto &e: adj[i]){
	           indegrees[e]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	       if(indegrees[i]==0){
	           q.push(i);
	       }
	    }
	    
	    vector<int> topo;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(const auto &e : adj[node]){
	            indegrees[e]--;
	            if(indegrees[e]==0){
	                q.push(e);
	            }
	        }
	    }
	    
	    return topo;
	}
};