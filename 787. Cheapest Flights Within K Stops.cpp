//https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>>g(101);
        vector<vector<int>>w(101, vector<int>(101));
        for (auto& v: flights) {
            int a = v[0];   // src
            int b = v[1];   // dst
            int c = v[2];   // weight
            g[a].push_back(b);
            w[a][b] = c;
        }
        auto comp = [](vector<int>& v1, vector<int>& v2) {
          return v1[1] > v2[1];  
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>pq(comp);
        pq.push({src, 0, K});
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int from = v[0];
            int cost = v[1];
            int stop = v[2];
            
            if (from == dst) {
                return cost;
            }
            if (stop < 0) {
                continue;
            }
            --stop;
            for (int x: g[from]) {
                pq.push({x, cost + w[from][x], stop});
            }
        }
        return -1;
    }
};