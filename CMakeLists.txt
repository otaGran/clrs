cmake_minimum_required(VERSION 3.6)
project(clrs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp chap24/Bellman-Ford.cpp chap24/DAG.cpp chap24/Dijkstra.cpp "chap25/Floyd-Warshall .cpp" chap25/EXTEND-SHORTEST-PATHS.cpp chap25/TRANSITIVE_CLOSURE.cpp chap15/Matrix-chain-multiplication.cpp chap15/LCS.cpp chap15/optimalBST.cpp chap22/DFSfuck.cpp)
add_executable(clrs ${SOURCE_FILES})
add_executable(Bellman-Ford chap24/Bellman-Ford.cpp)
add_executable(DAG chap24/DAG.cpp)
add_executable(Dijkstra chap24/Dijkstra.cpp)
add_executable(Floyd-Warshall  "chap25/Floyd-Warshall .cpp")
add_executable(EXTEND-SHORTEST-PATHS chap25/EXTEND-SHORTEST-PATHS.cpp)
add_executable(TRANSITIVE_CLOSURE chap25/TRANSITIVE_CLOSURE.cpp)
add_executable(Matrix-chain-multiplication chap15/Matrix-chain-multiplication.cpp)
add_executable(LCS chap15/LCS.cpp)
add_executable(optimalBST chap15/optimalBST.cpp)


add_executable(DFSfuck chap22/DFSfuck.cpp)