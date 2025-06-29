class Dijikstra{
    vector<vector<pair<int,int>>> graph;
    int source;
    int nodecount=0;
    vector<int> dis;
    int destination;
    
    
    public:
        Dijikstra(int src,int dest,vector<vector<pair<int,int>>> &graph){
            this->source=src;
            this->graph=graph;
            this->nodecount=graph.size();
            dis.resize(nodecount);
            algorith();
            this->destination=dest;
        }
        
        void algorith(){
            for(int i=0;i<nodecount;i++){
                dis[i]=INT_MAX;
            }
            dis[source]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,source});
            while(!pq.empty()){
                int cost=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto nb:graph[node]){
                    if(dis[nb.first]>cost+nb.second){
                        dis[nb.first]=cost+nb.second;
                        pq.push({cost+nb.second,nb.first});
                    }
                }
            }
        }
        
        int find(){
            return dis[destination];
            
        }
};
