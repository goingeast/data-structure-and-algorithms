/* 
 * File:   Graph.h
 * Author: haoruzhao
 *
 * Created on April 22, 2013, 9:35 PM
 */

#ifndef GRAPH_H
#define	GRAPH_H
#include<iostream>
#include<vector>
using namespace std;

class EdgeNode{
public:
    EdgeNode(int y, int weight, EdgeNode* next = NULL )
        :_y(y),_weight(weight),_next(next){
    };
    int _y;
    int _weight;
    EdgeNode* _next;
};

class Graph{
public:
    Graph(bool directed)
        :_nedges(0),_directed(directed){
            
    };
    vector<EdgeNode*> edges;
    vector<int> degree;
    int _nedges;
    bool _directed;
    void Insert(int x,int y, bool directed= false, int weight = NULL);
    void BuildGraph();
    void PrintGraph();
    
};

void Graph::Insert(int x, int y, bool directed, int weight){
    while(edges.size() < x){
        edges.push_back(NULL); // due to vector
        degree.push_back(0);
    }
    x = x-1; // index
    EdgeNode* newEdge = new EdgeNode(y, weight, edges[x]);
    
    edges[x] = newEdge;
    degree[x]++;
    if(directed == false)
        Insert(y, x+1, true);
    else
        _nedges++;
}

void Graph::BuildGraph(){
    int nedges;
    
    cout << "input number of edges:"<<endl;
    cin >> nedges;
    
    while(nedges--){
        int x,y;
        cout << "input start and end:"<< endl;
        cin >> x >> y;
        Insert(x, y, _directed);
    }
}

void Graph::PrintGraph(){
    EdgeNode* p;
    for(int i=0; i < edges.size(); ++i){
        cout << "\n"<< i+1 << ":";
        p = edges[i];
        while(p != NULL){
            cout << p->_y;
            p = p->_next;
        }
    }
}
#endif	/* GRAPH_H */

