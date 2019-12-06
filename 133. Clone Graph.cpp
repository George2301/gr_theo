//https://leetcode.com/problems/clone-graph/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*,Node*> copied;
    
    Node* cloneGraph(Node* node) {
        if(copied.find(node)!=copied.end())return copied[node];
        Node* newnode;
        newnode=new Node(node->val, {});
        copied[node]=newnode;
        for(int i=0; i<node->neighbors.size(); i++)newnode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        return newnode;
    }
};