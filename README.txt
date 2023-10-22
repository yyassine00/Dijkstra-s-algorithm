Younes Yassine 
Dijkstra's algorithm
CSCI 3761 001

-README

This program implements Dijkstra's algorithm for finding the shortest paths in a graph. The user is prompted to enter the name of a file containing the graph, and the source node to start from. The program then reads the graph from the file and outputs the shortest paths from the source node to all other nodes in the graph.

The program contains the following:

main.cpp
test10nodes.txt
test100nodes.txt

The main function reads the input file and initializes the necessary data structures. It then calls the dijkstra function, which implements Dijkstra's algorithm. The dijkstra function outputs the distances and previous nodes at each step of the algorithm. Finally, the program outputs the forwarding table for the source node, which shows the next hop for each node in the graph.

To run the program, compile the source code using a C++ compiler (e.g., g++), and run the executable file. The program will prompt you for the name of the input file and the source node. Use either of the .txt files included.

The program has been tested on Linux and Windows platforms using the g++ compiler.

