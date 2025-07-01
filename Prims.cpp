class Prims{
    vector<vector<int>> graph;
    int nodecount;
    vector<bool> vis;
    public:
        Prims(int n,vector<vector<int>> &graph){
            this->graph=graph;
            this->nodecount=n;
            vis.resize(nodecount);
            initialise();
        }
        void initialise(){
            for(int i=0;i<nodecount;i++){
                vis[i]=0;
            }
        }
        
        vector<int> solve(){
            vector<pair<int,int>> ans;
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
            pq.push({0,{0,-1}});
            while(!pq.empty()){
                int node=pq.top().second.first;
                int wt=pq.top().first;
                int par=pq.top().second.second;
                if(par!=-1 && vis[par]==0){
                    vis[par]=1;
                    ans.push_back({par,node});
                }
                for(auto nb:graph[node]){
                    if(vis[nb.first]==0){
                        pq.push({nb.second,{nb.first,node}});
                    }
                }
            }
            return ans;
        }
};
