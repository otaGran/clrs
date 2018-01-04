//
// Created by beans on 2017/12/21.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

const int MaxDistance = 1000;

class Graph_SP_AllPairs {
private:
    int num_vertex;
    std::vector<std::vector<int> > AdjMatrix, Distance, Predecessor;
public:
    Graph_SP_AllPairs() : num_vertex(0) {};

    Graph_SP_AllPairs(int n);

    void AddEdge(int from, int to, int weight);

    void PrintData(std::vector<std::vector<int> > array, int plusone);

    void InitializeData();

    void FloydWarshall();
};

#define EPS 1e-5

Graph_SP_AllPairs::Graph_SP_AllPairs(int n) : num_vertex(n) {
    // Constructor, initialize AdjMatrix with 0 or MaxDistance
    AdjMatrix.resize(num_vertex);
    for (int i = 0; i < num_vertex; i++) {
        AdjMatrix[i].resize(num_vertex, MaxDistance);
        for (int j = 0; j < num_vertex; j++) {
            if (i == j) {
                AdjMatrix[i][j] = 0;
            }
        }
    }
}

void Graph_SP_AllPairs::InitializeData() {

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

void Graph_SP_AllPairs::FloydWarshall() {

    InitializeData();

    std::cout << "initial Distance[]:\n";
    PrintData(Distance, 0);
    std::cout << "\ninitial Predecessor[]:\n";
    PrintData(Predecessor, 1);

    for (int k = 0; k < num_vertex; k++) {
        std::cout << "\nincluding vertex(" << k << "):\n";
        for (int i = 0; i < num_vertex; i++) {
            for (int j = 0; j < num_vertex; j++) {
                if ((Distance[i][j] > Distance[i][k] + Distance[k][j])
                    && (Distance[i][k] != MaxDistance)) {
                    Distance[i][j] = Distance[i][k] + Distance[k][j];
                    Predecessor[i][j] = Predecessor[k][j];
                }
            }
        }
        // print data after including new vertex and updating the shortest paths
        std::cout << "Distance[]:\n";
        PrintData(Distance, 0);
        std::cout << "\nPredecessor[]:\n";
        PrintData(Predecessor, 1);
    }
}

void Graph_SP_AllPairs::PrintData(std::vector<std::vector<int> > array, int plusone) {

    for (int i = 0; i < num_vertex; i++) {
        for (int j = 0; j < num_vertex; j++) {
            if (plusone) {
                if (array[i][j] == -1)
                    std::cout << std::setw(5) << "NIL";
                else
                    std::cout << std::setw(5) << array[i][j] + 1;
            } else{

                if(array[i][j] > 900)
                    printf("    ∞");
                else
                std::cout << std::setw(5) << array[i][j];
            }

        }
        std::cout << std::endl;
    }
}

void Graph_SP_AllPairs::AddEdge(int from, int to, int weight) {
    AdjMatrix[from][to] = weight;
}

int main() {



/*
    Graph_SP_AllPairs g10(5);
    g10.AddEdge(0,1,3);g10.AddEdge(0,2,8);g10.AddEdge(0,4,-4);
    g10.AddEdge(1,3,1);g10.AddEdge(1,4,7);
    g10.AddEdge(2,1,4);
    g10.AddEdge(3,0,2);g10.AddEdge(3,2,-5);
    g10.AddEdge(4,3,6);

 */
    Graph_SP_AllPairs g10(7);

    g10.AddEdge(0, 2, -4);
    g10.AddEdge(0, 3, 7);
    g10.AddEdge(1, 6, -1);
    g10.AddEdge(2, 4, 2);
    g10.AddEdge(3, 1, 3);
    g10.AddEdge(4, 5, -4);
    g10.AddEdge(5, 2, 6);
    g10.AddEdge(5, 3, 1);
    g10.AddEdge(6, 0, 9);
    g10.AddEdge(6, 4, 5);


    g10.FloydWarshall();

    return 0;
}
////final start from DP
