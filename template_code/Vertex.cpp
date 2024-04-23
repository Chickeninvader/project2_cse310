#include "Vertex.h"
#include <iostream>

Vertex::Vertex() {
    this->index = -1;
    this->degree = -1;
    this->adjacentVertices = nullptr;
    this->countVertices = 0;
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
    this->adjacentVertices = new Vertex[deg];
    this->countVertices = deg - 1;
}

void Vertex::AddEdge(Vertex &vertex) {
    if (this->countVertices < 0)    {
        throw std::invalid_argument( "num edge and num degree is not match" );
    }
    if (vertex.getIndex() == -1)    {
        throw std::invalid_argument( "wrong vertex data" );
    }
    this->adjacentVertices[this->countVertices] = vertex;
    this->countVertices --;
}

Vertex* Vertex::GetAdjacentVertice()    {
    return this->adjacentVertices;
}

Vertex::~Vertex()   {
    delete[] this->adjacentVertices;
}

