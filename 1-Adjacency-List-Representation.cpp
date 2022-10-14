#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    public:
        Graph(int v){

            //v represents the number of vertices (nodes) in the graph
            V=v;
            l=new list<int>[V];
        }

        void addEdge(int i, int j, bool undir=true){
            l[i].push_back(j);
            if(undir) l[j].push_back(i);
        }

        void printAdjacencyList(){
            for(int i=0;i<V;i++){
                cout<<i<<"-->";
                for(auto node:l[i]) cout<<node<<" ";
                cout<<endl;
            }
        }

        

    
};

int main(){
    Graph g(6); //specifies that there will be 6 nodes in the graph

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(5,4);

    g.printAdjacencyList();
}