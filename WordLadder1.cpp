class WordLadder{
    string start;
    string end;
    vector<string> words;
    public:
        WordLadder(string start,string end,vector<string> words){
            this->start=start;
            this->end=end;
            this->words=words;
        }
        
        int solve(){
            queue<string> q;
            q.push(start);
            unordered_set<string> vis;
            for(auto word:words){
                vis.insert(word);
            }
            
            vis.erase(start);
            int step=1;
            while(q.size()>0){
                int n=q.size();
                cout<<endl;
                for(int i=0;i<n;i++){
                    string temp=q.front();
                    q.pop();
                    if(temp==end)return step;
                    for(int j=0;j<temp.size();j++){
                        char original=temp[j];
                        for(char ch='a';ch<='z';ch++){
                            temp[j]=ch;
                            if(vis.find(temp)!=vis.end()){
                                q.push(temp);
                                vis.erase(temp);
                            }
                        }
                        temp[j]=original;
                    }
                    
                }
                step++;
            }
            return 0;
            
        }
};

//Brute force
// bool isValid(string a,string b){
//     int ct=0;
//     for(int i=0;i<a.size();i++){
//         if(a[i]!=b[i])ct++;
//     }
//     return ct==1;
// }
// int ans=INT_MAX;
// void dfs(string word,string end, vector<string>& words,unordered_set<string> &vis,int ct){
//     if(word==end){
//         ans=min(ans,ct);
//         return ;
//     }
//     vis.insert(word);
//     for(auto w:words){
//         if(vis.find(w)==vis.end() && isValid(word,w)){
//             dfs(w,end,words,vis,ct+1);
//         }
//     }
//     vis.erase(word);
// }
