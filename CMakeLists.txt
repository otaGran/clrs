cmake_minimum_required(VERSION 3.8)
project(clrs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp chap25/Bellman-Ford.cpp chap25/DAG.cpp chap25/Dijkstra.cpp "chap25/Floyd-Warshall .cpp" chap25/EXTEND-SHORTEST-PATHS.cpp chap25/johnson.cpp chap25/TRANSITIVE_CLOSURE.cpp)
add_executable(clrs ${SOURCE_FILES})
add_executable(Bellman-Ford chap25/Bellman-Ford.cpp)
add_executable(DAG chap25/DAG.cpp)
add_executable(Dijkstra chap25/Dijkstra.cpp)
add_executable(Floyd-Warshall  "chap25/Floyd-Warshall .cpp")
add_executable(EXTEND-SHORTEST-PATHS chap25/EXTEND-SHORTEST-PATHS.cpp)
add_executable(TRANSITIVE_CLOSURE chap25/TRANSITIVE_CLOSURE.cpp)