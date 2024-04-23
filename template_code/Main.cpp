#include <iostream>
#include "graph.h"
#include "graph.cpp"
#include <iostream>
#include <fstream> // For file input

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

//    int numOfVertices;
//    int numOfEdges;
//
//    if(!std::cin.eof()){
//        std::cin >> numOfVertices;
//        std::cin >> numOfEdges;
//    }
//    else{
//        std::cout<<"Input not found!"<<std::endl;
//        return 0;
//    }
//    Graph graph = Graph(numOfVertices, numOfEdges);
//
//    while(!std::cin.eof()){
//        int startVertice;
//        int endVertice;
//        std::cin >> startVertice;
//        std::cin >> endVertice;
//        graph.AddEdgeAndVertices(startVertice, endVertice);
//    }

    std::string filename;

    // Prompt for user input
    std::cout << "Enter the path to the text file containing graph data: ";
    std::getline(std::cin, filename);

    // Open the file for reading
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return 1; // Indicate error
    }

    // Read number of vertices and edges from the file
    int numOfVertices;
    int numOfEdges;
    inputFile >> numOfVertices >> numOfEdges;

    // Create the graph object
    Graph graph = Graph(numOfVertices, numOfEdges);

    // Read edge connections from the file
    while (inputFile >> std::skipws) { // Skip whitespace before each line
        int startVertice;
        int endVertice;
        inputFile >> startVertice >> endVertice;

        // Add edge to the graph
        graph.AddEdgeAndVertices(startVertice - 1, endVertice - 1);
    }

    // Close the file
    inputFile.close();

    // And here is where you start working on the three tasks
    graph.UpdateVertices();
    graph.PrintAdjacencyMatrix();
    graph.PrintOddDegreeVertices();
    graph.PrintShortestPath();
    
    return 0;
}