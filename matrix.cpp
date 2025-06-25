class MatrixGraph{
    int row=0;
    int col=0;
    vector<int> x={-1,0,1,0};
    vector<int> y={0,1,0,-1};
    vector<vector<int>> matrix;
    public:
      MatrixGraph(vector<vector<int>> &matrix){
          this->row=matrix.size();
          this->col=matrix[0].size();
          this->matrix=matrix;
          
      }
      
      bool isValid(int r,int c){
          return r>=0 && r<row && c>=0 && c<col && matrix[r][c]==1;
      }
      
      void initialise(queue<pair<int,int>> &q){
          for(int i=0;i<row;i++){
              for(int j=0;j<col;j++){
                  if(matrix[i][j]==2){
                      q.push({i,j});
                  }
              }
          }
          
      }
      
      void solve(){
          //rooten orrange
          queue<pair<int,int>> q;
          initialise(q);
          int ans=0;
          while(q.size()>0){
              int n=q.size();
              ans++;
              for(int i=0;i<n;i++){
                  auto [r,c]=q.front();
                  q.pop();
                  for(int j=0;j<4;j++){
                      int nr=r+x[j];
                      int nc=c+y[j];
                      if(isValid(nr,nc)){
                          matrix[nr][nc]=2;
                          q.push({nr,nc});
                      }
                  }
              }
          }
          
          for(auto mat:matrix){
              for(auto cell:mat){
                  if(cell==1)return -1;
              }
          }
          return ans;
      }
    
};
