class Bipartite{
    vector<vector<int>> graph;
    vector<int> vis;
    int nodecount=0;
    public:
        Bipartite(vector<vector<int>> &graph){
            this->nodecount=graph.size();
            this->graph=graph;
            vis.resize(nodecount);
            initialise();
        }
        
        void initialise(){
            for(int i=0;i<nodecount;i++){
                vis[i]=-1;
            }
        }
        
        bool checkBipartiteDfs(int src,int color){
            vis[src]=color;
            for(auto nb:graph[src]){
                if(vis[nb]!=-1 && vis[nb]==color){
                    return false;
                }
                if(vis[nb]==-1 && !checkBipartiteDfs(nb,!color)){
                    return false;
                }
            }
            return true;
        }
        bool checkBipartiteBfs(int src,int color){
            queue<int> q;
            q.push(src);
            vis[src]=color;
            while(q.size()>0){
                int temp=q.front();
                q.pop();
                for(auto nb:graph[temp]){
                    if(vis[nb]==-1){
                        q.push(nb);
                        vis[nb]=!vis[temp];
                    }else if(vis[nb]==vis[temp]){
                        return false;
                    }
                }
                
            }
        }
        bool check(){
            for(int i=0;i<nodecount;i++){
                if(vis[i]==-1){
                    bool temp=checkBipartiteDfs(i,0);
                    if(temp==false)return false;
                }
            }
            return true;
        }
};
