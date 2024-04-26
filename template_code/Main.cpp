#include <iostream>
#include "Graph.h"

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return 0;
    }
    Graph graph = Graph(numOfVertices, numOfEdges);

    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        std::cin >> startVertice;
        std::cin >> endVertice;
        graph.AddEdgeAndVertices(startVertice - 1, endVertice - 1);
    }

    // And here is where you start working on the three tasks
    graph.UpdateVertices();
    graph.PrintAdjacencyMatrix();
    graph.PrintOddDegreeVertices();
    graph.PrintShortestPath();
    
    return 0;
}