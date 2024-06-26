#include "Graph.h"
#include "Vertex.h"
#include <iostream>

Graph::Graph(int numOfVertices, int numOfEdges) {
    this->vertices = new Vertex[numOfVertices];
    this->edges = new Edge[numOfEdges];
    this->countEdges = 0;
    this->verticesDegree = new int[numOfVertices];
    this->numOfVertices = numOfVertices;
    this->numOfEdges = numOfEdges;
    for (int idx = 0; idx < numOfVertices; idx++)   {
        this->verticesDegree[idx] = 0;
    }
}

void Graph::AddEdgeAndVertices(int startVertice, int endVertice) {
    if (this->countEdges >= this->numOfEdges)    {
        return;
    }
    this->verticesDegree[startVertice]++;
    this->verticesDegree[endVertice]++;
    this->edges[this->countEdges] = Edge(startVertice, endVertice);
    this->countEdges++;
}

void Graph::UpdateVertices() {
    for (int idx = 0; idx < this->numOfVertices; idx++)    {
        this->vertices[idx].setIndex(idx);
        this->vertices[idx].setDegree(this->verticesDegree[idx]);
    }

    for (int idx = 0; idx < this->numOfEdges; idx++)    {
        this->vertices[this->edges[idx].getStart()].AddEdge(this->vertices[this->edges[idx].getEnd()]);
        this->vertices[this->edges[idx].getEnd()].AddEdge(this->vertices[this->edges[idx].getStart()]);
    }
}

void Graph::PrintAdjacencyMatrix() {
    int** adjacencyMatrix = new int* [this->numOfVertices];

    for (int i = 0; i < this->numOfVertices; ++i) {
        adjacencyMatrix[i] = new int[this->numOfVertices]; // Allocate inner arrays
    }

    // Initialized matrix
    for (int i = 0; i < this->numOfVertices; ++i) {
        for (int j = 0; j < this->numOfVertices; ++j) {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i = 0; i < this->countEdges; ++i) {
        int start = this->edges[i].getStart();
        int end = this->edges[i].getEnd();
        adjacencyMatrix[start][end] = 1;
        adjacencyMatrix[end][start] = 1; // Since it's an undirected graph
    }
    
    // Print the adjacency matrix
    std::cout << "The adjacency matrix of G:\n";
    for (int i = 0; i < this->numOfVertices; ++i) {
        for (int j = 0; j < this->numOfVertices; ++j) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
            std::cout << std::endl;
    }

    // Deallocate memory used for the adjacency matrix
    for (int i = 0; i < this->numOfVertices; ++i) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
}

void Graph::PrintOddDegreeVertices() {
    // TODO: get the odd degree vertices from this->verticesDegree and print
    std::cout << "The odd degree vertices in G:\n";
    std::cout << "O = { ";
    bool isFirstVertex = true;
    for (int i = 0; i < this->numOfVertices; ++i) {
        if (this->verticesDegree[i] % 2 != 0) {
            if (isFirstVertex) {
                isFirstVertex = false;
            } else {
                std::cout << " ";
            }
            std::cout << i + 1; // Print vertex index starting from 1
        }
    }
    std::cout << " }\n";
}

void Graph::PrintShortestPath() {
    // distance: for a vertex, the distance value indicate how far the vertex to start vertex
    // includeVertices: represent the set of vertex considered in the algorithm
    // previousVertex: given a vertex, what is its previous vertex in the shortest path
    // chosenVertex: temp vertex adding to the includeVertices
    int* distance = new int[this->numOfVertices];
    bool* includeVertices = new bool[this->numOfVertices];
    int* previousVertexIdx = new int[this->numOfVertices];
    Vertex chosenVertex = Vertex();

    for (int startIdx = 0; startIdx < this->numOfVertices; startIdx++) {
        // Get odd degree vertex
        if (this->verticesDegree[startIdx] % 2 == 0) {
            continue;
        }
        std::cout << "Single source shortest path lengths from node " << startIdx + 1 << std::endl;

        // Set distance to be num vertex + 1, which similar to inf in this problem. PreviousVertex is set to default,
        // and includeVertices is false, meaning no vertex is chosen for the algorithm
        for (int idx = 0; idx < this->numOfVertices; idx++) {
            distance[idx] = this->numOfVertices + 1;
            previousVertexIdx[idx] = -1;
            includeVertices[idx] = false;
        }

        // initially, we include startIdx and set the distance to 0
        distance[startIdx] = 0;

        // Loop until all the vertices are considered in the algorithm
        for (int count = 0; count <= this->numOfVertices; count++) {
            // iterate all the vertices, find vertex has minimum distance and is not included in the includeVertices
            int min_distance = this->numOfVertices + 1;
            for (int idx = 0; idx < this->numOfVertices; idx++) {
                if ((distance[idx] < min_distance) & (!includeVertices[idx])) {
                    min_distance = distance[idx];
                    chosenVertex = this->vertices[idx];
                }
            }

            // set chosen vertex to true, so later we do not consider it
            includeVertices[chosenVertex.getIndex()] = true;

            // update distance of adjacent vertices
            for (int adjacentIdx = 0; adjacentIdx < chosenVertex.getDegree();adjacentIdx++) {
                // if distance of the adjacent vertex of the chosen vertex is larger than the distance of the chosen
                // vertex + 1 (weight of all the edge), then replace the distance and the previous vertex accordingly
                if (distance[chosenVertex.GetAdjacentVerticeIdx(adjacentIdx)] >
                distance[chosenVertex.getIndex()] + 1) {
                    distance[chosenVertex.GetAdjacentVerticeIdx(adjacentIdx)] =
                            distance[chosenVertex.getIndex()] + 1;
                    previousVertexIdx[chosenVertex.GetAdjacentVerticeIdx(adjacentIdx)] = chosenVertex.getIndex();
                }
            }
        }
        // Check error: if not all vertices is included, there exist value in includeVertices is false
        for (int idx = 0; idx < this->numOfVertices; idx++)  {
            if (!includeVertices[idx])  {
                throw std::invalid_argument( "the shortest path algorithm do not work properly" );
            }
        }
        // print result:
        for (int idx = 0; idx < this->numOfVertices; idx++)  {
            std::cout << idx + 1 << ": " << distance[idx] << std::endl;
        }
    }
    delete[] distance;
    delete[] includeVertices;
    delete[] previousVertexIdx;
}

Graph::~Graph()   {
    delete[] this->vertices;
    delete[] this->edges;
    delete[] this->verticesDegree;
}

