 

                    DFS
            Time Complexity:(N+V)-> N no. of nodes with V edege
            Space Complexity:(N) -> N no of nodes

 

class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whether we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;// if node is null, then simply return null
        
  

        for a node, we will check whether we already creates a copy of thiis or not. If it is present in map that means we already creates a copy of this.
        But if not present in map, that means we have not a copy of this. Also, if we create a copy, then being a good neighbor, we find whether 
        our neighbor have a copy or not, so we will travel all around our adjcant.

 
        if(mp.find(node) == mp.end()) // if not present in map
        {
            mp[node] = new Node(node -> val, {}); // make a copy
            
            for(auto adj: node -> neighbors) // travel in adjcant
            {
                mp[node] -> neighbors.push_back(cloneGraph(adj)); //add copy
            }
        }
        
        return mp[node]; // and at last, return mp[node] as till now we clone our whole graph
        
    }
};


                                 BFS
                Time Complexity:(N+V)-> N no. of nodes with V edege
                Space Complexity:(N) -> N no of nodes

class Solution {
public:
    unordered_map<Node* , Node*> mp; // declaring map, to check whwther we have a copy of node or not and also to store copy
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;// if node is null, then simply return null
        
        Node* first = new Node(node -> val, {}); // make a copy of first node
        mp[node] = first;
        
        queue<Node*> q; //For bfs, we create queue
        q.push(node); // push into queue
        
        while(q.empty() == false) // until q. empty == false
        {
            Node* curr = q.front(); // extract front node
            q.pop(); // pop that from queue
            
            for(auto adj: curr -> neighbors) // now travel in adjcant
            {
                if(mp.find(adj) == mp.end()) // if not present in map
                {
                    mp[adj] = new Node(adj -> val, {}); // then create copy
                    q.push(adj); // push nto the queue
                    
                }
                
                mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
            }
        }
        
        return mp[node];
    }
};
