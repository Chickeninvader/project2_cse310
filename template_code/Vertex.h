#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
    private:
       int index;
       int degree;
       Vertex* adjacentVertices;
       int countVertices;
    public:
        Vertex();
        ~Vertex();
        int getIndex();
        int getDegree();
        void setIndex(int);
        void setDegree(int);
        void AddEdge(Vertex&);
        Vertex* GetAdjacentVertice();
};


#endif