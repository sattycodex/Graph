#include <bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int>> graph;
    int nodes;
    vector<bool> vis;
    public:
      Graph(vector<vector<int>> &graph){
          this->nodes=graph.size();
          this->graph=graph;
          vis.resize(nodes);
      }
      
      void dfs(int src,int par){
          cout<<src<<" ";
          vis[src]=1;
          for(auto nb:graph[src]){
              if(nb!=par && vis[nb]==0){
                  dfs(nb,src);
              }
          }
      }
      
      void resetVisited(){
          for(int i=0;i<nodes;i++){
              vis[i]=0;
          }
      }
      
      void bfs(int src){
          queue<int> q;
          q.push(src);
          while(q.size()>0){
              int n=q.front();
              q.pop();
              if(vis[n])continue;
              vis[n]=1;
              cout<<n<<" ";
              for(auto nb:graph[n]){
                  q.push(nb);
              }
          }
      }
    
    
};

int main()
{
    vector<vector<int>> graph;
    graph.push_back(vector<int>{1,3,2});
    graph.push_back(vector<int>{0,2});
    graph.push_back(vector<int>{1,3,0});
    graph.push_back(vector<int>{1,2});
    
    Graph* gr=new Graph(graph);
    gr->resetVisited();
    gr->bfs(3);
    gr->resetVisited();
    cout<<endl;
    gr->dfs(1,-1);
    

    return 0;
}
