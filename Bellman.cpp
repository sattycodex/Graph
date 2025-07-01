class BellManFord{
    vector<vector<int>> graph;
    int nodecount;
    int src;
    public:
        BellManFord(int v,vector<vector<int>> &graph,int src){
            this->graph=graph;
            this->nodecount=v;
            this->src=src;
        }
        
        vector<int> solve(){
            vector<int> dis(nodecount,1e8);
            dis[src]=0;
            for(int i=1;i<nodecount;i++){
                for(auto val:graph){
                    int u=val[0];
                    int v=val[1];
                    int wt=val[2];
                    if(dis[u]!=1e8 && dis[u]+wt<dis[v]){
                        dis[v]=dis[u]+wt;
                    }
                }
            }
            
            for(auto val:graph){
                    int u=val[0];
                    int v=val[1];
                    int wt=val[2];
                    if(dis[u]!=1e8 && dis[u]+wt<dis[v]){
                        return vector<int>{-1};
                    }
                }
            
            return dis;
        }
};
