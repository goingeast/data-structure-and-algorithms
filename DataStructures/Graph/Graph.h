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
#include <queue>
#include <stack>
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
    void BFS(int start);
    void DFS(int start);
    void _DFS(vector<bool> & discovered, vector<bool>& processed, vector<int> & parent,
                    vector<int> & entry_time,vector<int> & exit_entry, int start);
    
};

void Graph::Insert(int x, int y, bool directed, int weight){
    while(edges.size() < x + 1){
        edges.push_back(NULL); // due to vector
        degree.push_back(0);
    }
    
    EdgeNode* newEdge = new EdgeNode(y, weight, edges[x]);
    
    edges[x] = newEdge;
    degree[x]++;
    if(directed == false)
        Insert(y, x, true);
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
    for(int i=1; i < edges.size(); ++i){
        cout << "\n"<< i << ":";
        p = edges[i];
        while(p != NULL){
            cout << p->_y;
            p = p->_next;
        }
    }
}
void Graph::BFS( int start){
    vector<bool> discovered;
    vector<bool> processed;
    vector<int> parent;
    for(int i=0; i < edges.size(); ++i){
        discovered.push_back(false);
        processed.push_back(false);
        parent.push_back(-1);
    }
    queue<int> q;
    q.push(start);
    discovered[start] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        processed[v] = true;
        EdgeNode * en = edges[v];
        while(en!=NULL){
            int y=en->_y;
            if(processed[y] == false || _directed){
                cout << "processed X:"<< v <<"Y:"<< y << endl;
            }
            if(discovered[y] == false){
                discovered[y] = true;
                q.push(y);
                parent[y] = y;
            }
            en= en->_next;
        }
    }
   
}

void Graph::DFS(int start){
    vector<bool> discovered;
    vector<bool> processed;
    vector<int> parent;
    vector<int> entry_time;
    vector<int> exit_time;
    for(int i=0; i < edges.size(); ++i){
        discovered.push_back(false);
        processed.push_back(false);
        parent.push_back(-1);
        entry_time.push_back(0);
        exit_time.push_back(0);
    }
    _DFS(discovered,  processed, parent, entry_time, exit_time, start);
}

void Graph::_DFS(vector<bool>& discovered, vector<bool>& processed, 
        vector<int>& parent, vector<int>entry_time, vector<int> exit_time, int v){
    
    discovered[v] = true;
    static int time = 0;
    //if(finished) return;
    //process vertex u if desired
    entry_time[v] = ++time;
    EdgeNode* p = edges[v];
    while(p != NULL){
        int y = p->_y;
        if(discovered[y] == false){
            discovered[y] = true;
            //process edge
            parent[y] = v;
            _DFS(discovered, processed, parent, entry_time, exit_time, y);
        }else if(processed[v] == false || _directed ){
            //process edge
        }
        //if(finished) return;
        p = p->_next;
    }
    exit_time[v] = ++time;
    processed[v] = true; 

}
#endif	/* GRAPH_H */

