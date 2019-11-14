//https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        vector<int> c=vector<int>(num, 0); 
        
        vector<vector<int>> g = vector<vector<int>>(num, vector<int>());
        for(int i = 0; i < pre.size(); i++){
            g[pre[i][0]].push_back(pre[i][1]);
        }
       
        for(int i = 0; i < g.size(); i++){            
            if(c[i] == 0){
                stack<int> s;
                s.push(i);
                while(!s.empty()){
                    int t = s.top();
                    c[t] = 1;
                    for(int k = 0; k < g[t].size(); k++){
                        if(c[g[t][k]] == 1){                           
                            return false;
                        }
                        if(c[g[t][k]] == 0){
                            s.push(g[t][k]);
                        }
                    }
                    if(c[s.top()] == 1){
                        c[s.top()] = 2;
                        s.pop();
                    }
                }                
            }
        }
        
        return true;
    }
};