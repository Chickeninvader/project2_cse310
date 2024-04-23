#ifndef PROJECT2_CSE310_GRAPH_H
#define PROJECT2_CSE310_GRAPH_H

#include "Vertex.h"
#include "Edge.h"

#include "Vertex.cpp"
#include "Edge.cpp"

class Graph{
private:
    Vertex* vertices;
    Edge* edges;
    int* verticesDegree;
    int countEdges;
    int numOfVertices;
    int numOfEdges;

public:
    Graph(int, int);
    void AddEdgeAndVertices(int, int);
    void UpdateVertices();
    void PrintAdjacencyMatrix();
    void PrintOddDegreeVertices();
    void PrintShortestPath();
    ~Graph();
};

#endif //PROJECT2_CSE310_GRAPH_H
