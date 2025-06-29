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
        
        vector<vector<string>> solve(){
            queue<vector<string>> q;
            q.push({start});
            unordered_set<string> vis;
            for(auto word:words){
                vis.insert(word);
            }
            vector<vector<string>> ans;
            while(q.size()>0){
                int n=q.size();
                for(int i=0;i<n;i++){
                    vector<string> t=q.front();
                    q.pop();
                    string temp=t.back();
                    vis.erase(temp);
                    for(int j=0;j<temp.size();j++){
                        char original=temp[j];
                        for(char ch='a';ch<='z';ch++){
                            temp[j]=ch;
                            if(vis.find(temp)!=vis.end()){
                                t.push_back(temp);
                                if(temp==end){
                                    ans.push_back(t);
                                }
                                q.push(t);
                                t.pop_back();
                            }
                        }
                        temp[j]=original;
                    }
                    
                }
                if(ans.size()>0)return ans;
            }
            return ans;
            
        }
};
