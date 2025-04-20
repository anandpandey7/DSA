#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class GraphList{
    private:
    int vertices;
    unordered_map<int,vector<int>>graph;

    public:
    GraphList(int v) {
        vertices = v;
    }

    void addEdge(int u, int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void display(){
        cout << "Adjacency List:\n";
        for(auto & it: graph){
            cout << it.first << " -> ";
            for(int v : it.second ){
                cout << v <<" ";
            }
            cout << endl;
        }
    }
};

int main() {
    int v = 5;
    GraphList gl(v);

    gl.addEdge(0, 1);
    gl.addEdge(0, 4);
    gl.addEdge(1, 2);
    gl.addEdge(1, 3);
    gl.addEdge(1, 4);
    gl.addEdge(2, 3);
    gl.addEdge(3, 4);

    gl.display();
    
    return 0;
}