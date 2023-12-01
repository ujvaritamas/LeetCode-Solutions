#include <map>
#include <memory>
#include <vector>
#include <set>
#include <iostream>
#include <limits.h>
using namespace std;

/*This implementation created for fun
just to practice graph creation and walking.

This is not efficient solution.

TODO: runtime optimalization.
*/

class Node{
    private:
        int value;
        vector<int> neighboors;
    public:
        Node(int value);
        ~Node();
        void addNeighbor(int val);
        int getValue();
        void printNode();
        vector<int>& getNeighbors();
};

class Graph{
    private:
        std::map<int, std::unique_ptr<Node>> nodes;
        bool isAllNodeChecked(int&, std::set<int>&);

    public:
    void createGraph(int n, vector<vector<int>>& edges);
    std::unique_ptr<Node>& getNode(int value);

    void printGraph();
    int walk(int&, int&);


};

Node::Node(int value): value(value){}

void Node::addNeighbor(int val){
            this->neighboors.push_back(val);
}

int Node::getValue(){
    return this->value;
}

vector<int>& Node::getNeighbors(){
    return this->neighboors;
}

void Node::printNode(){
    cout<<"Node: " <<this->value <<" Neighbors: ";
    for(auto i:this->neighboors){
        cout<<i<<" ";
    }
    cout<<endl;
}

void Graph::createGraph(int n, vector<vector<int>>& edges){
    for(auto i = 0; i<n; i++){
        std::unique_ptr<Node> p = std::make_unique<Node>(i);
        nodes[i] = std::move(p);
    }

    for(auto i:edges){
        auto& node0 = this->getNode(i[0]);
        auto& node1 = this->getNode(i[1]);
        node0->addNeighbor(i[1]);
        node1->addNeighbor(i[0]);
    }
}

std::unique_ptr<Node>& Graph::getNode(int value){
    if (this->nodes.find(value) == this->nodes.end()) {
        // not found
        throw "error occurred";
    }

    return this->nodes.at(value);   //return this->nodes[value];
    
}

Node::~Node(){
    cout<<"Destructor called"<<endl;
}

void Graph::printGraph(){
    for (auto const& x : this->nodes)
    {
        x.second->printNode();
    }
}

bool Graph::isAllNodeChecked(int& n, std::set<int>& checkedNodes){
    return checkedNodes.size() == n;
}

void printSet_debug(std::set<int>& s){
    std::set<int>::iterator itr;

  // Displaying set elements
  for (itr = s.begin(); 
       itr != s.end(); itr++) 
  {
    cout << *itr << " ";
  }
  cout<<endl;
}

int Graph::walk(int& root, int& n){
    auto& rootNode = this->getNode(root);

    std::set<int> checkedNodes;
    std::set<int> nextCheck;
    std::set<int> nodesOnNextLevel;

    int level = 0;

    cout<<"_________________"<<endl;

    nextCheck.insert(root);

    while(!nextCheck.empty()){
        //cout<<"______nextCheck________"<<endl;
        //printSet_debug(nextCheck);
        //cout<<"______nextCheck________"<<endl;
        int check = *nextCheck.begin();
        nextCheck.erase(check);
        checkedNodes.insert(check);
        if(this->isAllNodeChecked(n, checkedNodes))
            return level;
        else{
            auto& currentNode = this->getNode(check);
            for(auto i: currentNode->getNeighbors()){
                if(checkedNodes.find(i) == checkedNodes.end()){
                    nodesOnNextLevel.insert(i);
                }
            }
            if(nextCheck.empty()){
                //the level is empty
                level++;
                nextCheck = nodesOnNextLevel;
                nodesOnNextLevel.clear();
            }
        }

        //cout<<"______nextCheck, nodesOnNextLevel, checkedNodes________"<<endl;
        //printSet_debug(nextCheck);
        //printSet_debug(nodesOnNextLevel);
        //printSet_debug(checkedNodes);
        //cout<<"______nextCheck, nodesOnNextLevel, checkedNodes________"<<endl;
    }
    return level;
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ret;
        int min = INT_MAX;
        Graph g;
        g.createGraph(n,edges);
        g.printGraph();

        for(auto i = 0; i<n;i++){
            int step = g.walk(i, n);

            if(step<min){
                min = step;
                ret.clear();
                ret.push_back(i);
            }
            else if(step == min){
                ret.push_back(i);
            }

            cout<<"RootNode: "<< i<<" step "<<step<<endl;
        }
        return ret;
    }
};