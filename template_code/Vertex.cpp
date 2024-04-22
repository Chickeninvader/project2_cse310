#include "Vertex.h"
#include <iostream>

Vertex::Vertex() {
    this->index = -1;
    this->degree = -1;
}
Vertex::Vertex(int idx, int numOfAdjacentVertices){
    this->index = idx;
    this->degree = numOfAdjacentVertices;
    this->adjacentVertices = new Vertex[numOfAdjacentVertices];
}

int Vertex::getIndex(){
    return this->index;
}

int Vertex::getDegree(){
    return this->degree;
}

void Vertex::setIndex(int index){
    this->index = index;
}

void Vertex::setDegree(int deg){
    this->degree = deg;
}

void Vertex::AddEdge(Vertex vertex) {
    if (this->countVertices < 0)    {
        throw std::invalid_argument( "num edge and num degree is not match" );
    }
    this->countVertices --;
    this->adjacentVertices[this->countVertices] = vertex;
}

Vertex* Vertex::GetAdjacentVertice()    {
    return this->adjacentVertices;
}

Vertex::~Vertex()   {
    delete[] this->adjacentVertices;
}

