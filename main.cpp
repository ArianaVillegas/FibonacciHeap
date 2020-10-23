#include "Graph.h"
#include <iostream>

using namespace std;

int main(){

    Graph<long double> g;
    g.insertFile("data.txt");

    //g.omegaPrint();

    Graph<long double> graph = g.kruskal();
    graph.omegaPrint();

    cout << "Termine\n";

}
