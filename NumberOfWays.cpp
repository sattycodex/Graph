class NumberWays{
    vector<vector<pair<int,int>>> graph;
    vector<long> ways;
    vector<long> dis;
    int nodecount=0;
    int mod=1e9+7;
    public:
        NumberWays(int n,vector<vector<pair<int,int>>> &graph){
            this->nodecount=n;
            this->graph=graph;
            ways.resize(nodecount);
            dis.resize(nodecount);
            initialise();
        }
        
        void initialise(){
            for(int i=0;i<nodecount;i++){
                dis[i]=1e15;
                ways[i]=0;
            }
        }
        
        int solve(){
            priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> pq;
            pq.push({0,0});
            dis[0]=0;
            ways[0]=1;
            while(!pq.empty()){
                int node=pq.top().second;
                long cost=pq.top().first;
                pq.pop();
                for(auto nb:graph[node]){
                    int nbn=nb.first;
                    int nbw=nb.second;
                    long temp=(long)cost+nbw;
                    if(dis[nbn]>temp){
                        dis[nbn]=(long)cost+nbw;
                        ways[nbn]=(ways[node])%mod;
                        pq.push({(long)cost+nbw,nbn});
                    }else if(dis[nbn]==temp){
                        ways[nbn]=(ways[nbn]+ways[node])%mod;
                    }
                }
            }
            
            return ways[nodecount-1]%mod;
        }
};
