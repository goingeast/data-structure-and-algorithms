#include"Graph.h"

int main(){
    Graph myGraph(false);
    myGraph.BuildGraph();
    myGraph.PrintGraph();
    myGraph.BFS(1);
}