#include <iostream>
#include <vector>

using namespace std;
// Adjacency Matrix
class GraphMatrix{
    private: 
        vector<vector<int>> adjMatrix;
        int vertices;

    public:

    //constructor
    GraphMatrix(int v) {
        vertices = v;
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v){
        if (u >= vertices || v >= vertices) {
            cout << "Error: Invalid vertex index (" << u << ", " << v << ")\n";
            return;
        }
        adjMatrix[u][v]=1;
        adjMatrix[u][v]=1;
    }

    void display(){
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class GraphAdjList{
    private:
    vector<vector<int>> adjList; 
    int vertices;

    public:
    // constructor
    GraphAdjList(int v){
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v){
        if (u >= vertices || v >= vertices) {
            cout << "Error: Invalid vertex index (" << u << ", " << v << ")\n";
            return;
        }
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void display(){
        cout << "Adjacency Matrix:\n";
        for(int i=0;i < vertices; i++){
            cout << i << " -> ";
            for(int & it: adjList[i]){
                cout << it <<" ";
            }
            cout << endl;
        }
    }

};

int main(){
    GraphMatrix g1(5);
    g1.addEdge(0,1);
    g1.addEdge(3,1);
    g1.addEdge(2,4);
    g1.addEdge(2,1);
    g1.addEdge(4,1);

    g1.display();

    GraphAdjList g2(5); 

    g2.addEdge(0, 1);
    g2.addEdge(3, 1);
    g2.addEdge(2, 4);
    g2.addEdge(2, 1);
    g2.addEdge(4, 1);
    
    g2.display();
}