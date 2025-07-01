class FloydWarshal{
    vector<vector<int>> matrix;
    int nodecount=0;
    
    public:
        FloydWarshal(vector<vector<int>> &matrix){
            this->matrix=matrix;
            this->nodecount=matrix.size();
        }
        
        void solve(){
            for(int k=0;k<nodecount;k++){
                for(int i=0;i<nodecount;i++){
                    for(int j=0;j<nodecount;j++){
                        if(i==k || j==k)continue;
                        if( (matrix[i][k]!=1e8 && matrix[k][j]!=1e8) && matrix[i][j]>(matrix[i][k]+matrix[k][j])){
                            matrix[i][j]=(matrix[i][k]+matrix[k][j]);
                        }
                    }
                }
            }
        }
};
