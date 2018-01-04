//
// Created by beans on 2017/12/21.
//

// C++ code
#include <iostream>
#include <vector>
#include <list>
#include <utility>          // for std::pair<>
#include <iomanip>          // for std::setw()
using namespace std;
const int Max_Distance = 1000;
class Graph_SP{             // SP serves as Shortest Path
private:
    int num_vertex;
    std::vector<std::list<std::pair<int,int>>> AdjList;
    std::vector<int> predecessor, distance;
public:
    Graph_SP():num_vertex(0){};
    Graph_SP(int n):num_vertex(n){
        AdjList.resize(num_vertex);
    }
    void AddEdge(int from, int to, int weight);
    void PrintDataArray(std::vector<int> array);

    void InitializeSingleSource(int Start);     // 以Start作為起點
    void Relax(int X, int Y, int weight);       // 對edge(X,Y)進行Relax
    bool BellmanFord(int Start = 0);            // 以Start作為起點
    // if there is negative cycle, return false
};

bool Graph_SP::BellmanFord(int Start){

    InitializeSingleSource(Start);
    Start+=1;
    std::cout << "predecessor[]:\n";
    PrintDataArray(predecessor);
    std::cout << "distance[]:\n";
    PrintDataArray(distance);
    cout << endl;
    for (int i = 0; i < num_vertex-1; i++) {                // |V-1|次的iteration
        // for each edge belonging to E(G)
        for (int tmp_j = Start ; tmp_j < num_vertex+Start; tmp_j++) {// 把AdjList最外層的vector走一遍
            int j = tmp_j % num_vertex;
            //cout << j <<endl;
            for (std::list<std::pair<int,int> >::iterator itr = AdjList[j].begin();
                 itr != AdjList[j].end(); itr++) {          // 各個vector中, 所有edge走一遍
                Relax(j, (*itr).first, (*itr).second);
                }
        }
        std::cout << "Loop: " << i+1 <<std::endl;
        std::cout << "predecessor[]:\n";
        PrintDataArray(predecessor);
        std::cout << "distance[]:\n";
        PrintDataArray(distance);
        cout << endl;

    }

    // check if there is negative cycle
    for (int i = 0; i < num_vertex; i++) {
        for (std::list<std::pair<int,int> >::iterator itr = AdjList[i].begin();
             itr != AdjList[i].end(); itr++) {
            if (distance[(*itr).first] > distance[i]+(*itr).second) {   // i是from, *itr是to
                return false;
            }
        }
    }

    // print predecessor[] & distance[]


    return true;
}
void Graph_SP::PrintDataArray(std::vector<int> array){
    for (int i = 0; i < num_vertex; i++)
        std::cout << std::setw(4) << i;
    std::cout << std::endl;
    for (int i = 0; i < num_vertex; i++)
        if(array[i]>900)
            printf("   ∞");
        else
        std::cout << std::setw(4) << array[i];
    std::cout << std::endl;
}
void Graph_SP::InitializeSingleSource(int Start){

    distance.resize(num_vertex);
    predecessor.resize(num_vertex);

    for (int i = 0; i < num_vertex; i++) {
        distance[i] = Max_Distance;
        predecessor[i] = -1;
    }
    distance[Start] = 0;
}
void Graph_SP::Relax(int from, int to, int weight){

    if (distance[to] > distance[from] + weight) {
        distance[to] = distance[from] + weight;
        predecessor[to] = from;
    }
}
void Graph_SP::AddEdge(int from, int to, int weight){
    AdjList[from].push_back(std::make_pair(to,weight));
}

int main(){

/*

    Graph_SP g7(5);
    g7.AddEdge(0,1,6);g7.AddEdge(0,3,7);
    g7.AddEdge(1,2,5);g7.AddEdge(1,3,8);g7.AddEdge(1,4,-4);
    g7.AddEdge(2,1,-2);
    g7.AddEdge(3,2,-3);g7.AddEdge(3,4,9);
    g7.AddEdge(4,0,2);g7.AddEdge(4,2,7);



*/
    Graph_SP g7(8);
    g7.AddEdge(0,2,11);g7.AddEdge(0,3,22);
    g7.AddEdge(1,0,-2);g7.AddEdge(1,4,25);
    g7.AddEdge(2,3,4);g7.AddEdge(2,5,-8);
    g7.AddEdge(3,4,-3);g7.AddEdge(3,5,20);g7.AddEdge(3,6,39);
    g7.AddEdge(4,2,16);g7.AddEdge(4,7,12);
    g7.AddEdge(5,7,8);
    g7.AddEdge(6,1,13);g7.AddEdge(6,4,-5);g7.AddEdge(6,5,17);g7.AddEdge(6,7,15);


    if (g7.BellmanFord(2))
        std::cout << "There is no negative cycle.\n";
    else
        std::cout << "There is negative cycle.\n";

    return 0;
}