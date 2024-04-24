#include "Vertex.h"
#include <iostream>

Vertex::Vertex() {
    this->index = -1;
    this->degree = -1;
    this->countVertices = 0;
    for (int i = 0; i < 1000; i++) {
        this->adjacentVerticesIdx[i] = -1;
    }
}

int Vertex::getIndex()  {
    return this->index;
}

int Vertex::getDegree(){
    return this->degree;
}

void Vertex::setIndex(int idx){
    this->index = idx;
}

void Vertex::setDegree(int deg){
    this->degree = deg;
    this->countVertices = deg - 1;
}

void Vertex::AddEdge(Vertex vertex) {
    if (this->countVertices < 0)    {
        throw std::invalid_argument( "num edge and num degree is not match" );
    }
    if (vertex.getIndex() == -1)    {
        throw std::invalid_argument( "wrong vertex data" );
    }
    this->adjacentVerticesIdx[this->countVertices] = vertex.getIndex();
    this->countVertices --;
}

int Vertex::GetAdjacentVerticeIdx(int idx)    {
    return this->adjacentVerticesIdx[idx];
}


