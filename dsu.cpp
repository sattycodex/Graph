#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> par;
    vector<int> rank;
    int nodecount=0;
    public:
        DSU(int nodecount){
            this->nodecount=nodecount;
            par.resize(nodecount);
            rank.resize(nodecount);
            initialiseParAndRank();
        }
        
        void initialiseParAndRank(){
            for(int i=0;i<nodecount;i++){
                par[i]=i;
                rank[i]=1;
            }
        }
        
        int findParent(int node){
            if(par[node]==node)return node;
            return par[node]= findParent(par[node]);
        }
        
        void merge(int u,int v){
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu!=pv){
                if(rank[pu]>rank[pv]){
                    par[pv]=pu;
                    rank[pu]++;
                }else{
                    par[pu]=pv;
                    rank[pv]++;
                }
            }
        }
};
