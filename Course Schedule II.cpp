class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        //CREATING GRAPH AND GENERATING A INDEGREE
        vector<int>Indegree(numCourses,0);
        for(auto &p : prerequisites){
            int u = p[1];
            int v = p[0];
            adj[u].push_back(v);
            Indegree[v]++;
        }
        //CREATING A QUEUE
        queue<int>q;

        for (int i = 0 ; i<numCourses ; i++){
            if(Indegree[i] == 0){
                q.push(i);
            }
        }
        //Vector for storing popped values
        vector<int>topo;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(int v : adj[u] ){
                if((--Indegree[v]) == 0){
                    q.push(v);
                }
            }
        }

        if(topo.size() == numCourses){
            return topo;
        }
        return{};
    }
};
