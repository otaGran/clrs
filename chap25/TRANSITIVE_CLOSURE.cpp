//
// Created by beans on 2017/12/22.
//

//
// Created by beans on 2017/12/21.
//

#include <iostream>
#include <vector>
#include <iomanip>      // for setw()

const int MaxDistance = 0;
class Graph_SP_AllPairs{
private:
    int num_vertex;
    std::vector< std::vector<int> > AdjMatrix, Distance, Predecessor;
public:
    Graph_SP_AllPairs():num_vertex(0){};
    Graph_SP_AllPairs(int n);
    void AddEdge(int from, int to, int weight);
    void PrintData(std::vector< std::vector<int> > array);
    void InitializeData();
    void FloydWarshall();
};

Graph_SP_AllPairs::Graph_SP_AllPairs(int n):num_vertex(n){
    // Constructor, initialize AdjMatrix with 0 or MaxDistance
    AdjMatrix.resize(num_vertex);
    for (int i = 0; i < num_vertex; i++) {
        AdjMatrix[i].resize(num_vertex, MaxDistance);
        for (int j = 0; j < num_vertex; j++) {
            if (i == j){
                AdjMatrix[i][j] = 1;
            }
        }
    }
}
void Graph_SP_AllPairs::InitializeData(){

    Distance.resize(num_vertex);
    Predecessor.resize(num_vertex);

    for (int i = 0; i < num_vertex; i++) {
        Distance[i].resize(num_vertex);
        Predecessor[i].resize(num_vertex, -1);
        for (int j = 0; j < num_vertex; j++) {
            Distance[i][j] = AdjMatrix[i][j];
            if (Distance[i][j] != 0 && Distance[i][j] != MaxDistance) {
                Predecessor[i][j] = i;
            }
        }
    }
}
void Graph_SP_AllPairs::FloydWarshall(){

    InitializeData();

    std::cout << "initial connective[]:\n";
    PrintData(Distance);


    for (int k = 0; k < num_vertex; k++) {
        std::cout << "\nincluding vertex(" << k << "):\n";
        for (int i = 0; i < num_vertex; i++) {
            for (int j = 0; j < num_vertex; j++) {
                /*
                if ((Distance[i][j] > Distance[i][k]+Distance[k][j])
                    && (Distance[i][k] != MaxDistance)) {
                    Distance[i][j] = Distance[i][k]+Distance[k][j];
                    Predecessor[i][j] = Predecessor[k][j];
                }
                 */
                Distance[i][j] = Distance[i][j] | (Distance[i][k] & Distance[k][j]);

            }
        }
        // print data after including new vertex and updating the shortest paths
        std::cout << "connective[]:\n";
        PrintData(Distance);

    }
}
void Graph_SP_AllPairs::PrintData(std::vector< std::vector<int> > array){

    for (int i = 0; i < num_vertex; i++){
        for (int j = 0; j < num_vertex; j++) {
            std::cout << std::setw(5) << array[i][j];
        }
        std::cout << std::endl;
    }
}
void Graph_SP_AllPairs::AddEdge(int from, int to, int weight){
    AdjMatrix[from][to] = weight;
}

int main(){

    Graph_SP_AllPairs g10(8);

    /*
    g10.AddEdge(1,2,1);g10.AddEdge(1,3,1);
    g10.AddEdge(2,1,1);

    g10.AddEdge(3,0,1);g10.AddEdge(3,2,1);
     */
    g10.AddEdge(0,4,1);g10.AddEdge(0,5,1);
    g10.AddEdge(1,6,1);
    g10.AddEdge(2,4,1);
    g10.AddEdge(3,4,1);
    g10.AddEdge(4,7,1);
    g10.AddEdge(5,7,1);
    g10.AddEdge(6,2,1);g10.AddEdge(6,3,1);
    g10.AddEdge(7,1,1);

    g10.FloydWarshall();

    return 0;
}