#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
    private:
       int index;
       int degree;
       int adjacentVerticesIdx[1000];
       int countVertices;
    public:
        Vertex();
        int getIndex();
        int getDegree();
        void setIndex(int);
        void setDegree(int);
        void AddEdge(Vertex);
        int GetAdjacentVerticeIdx(int);
};


#endif