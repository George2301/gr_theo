//https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string s1, string s2, vector<string>& wordList) {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 != n2) return 0;
        unordered_set<string> words(wordList.begin(), wordList.end());
        unordered_set<string> vis;
        unordered_map<string, int> level;
        int ans = 0;
        queue<string> q;
        q.push(s1);
        vis.insert(s1);
        level[s1] = 1;
        while(!q.empty()){
            string x = q.front();
            q.pop();
            if(x.compare(s2) == 0){
                return level[x];
            }
            for(int i = 0; i < x.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    if (c == x[i]) continue;
                    string xx= x;
                    xx[i] = c;
                    if(words.count(xx) && !vis.count(xx)){
                        q.push(xx);
                        vis.insert(xx);
                        level[xx] = level[x] + 1;
                    }
                }
            }
        }
        return 0;
    }
};