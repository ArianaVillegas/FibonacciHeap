#include "Graph.h"
#include "ReadImage.h"
#include <iostream>

using namespace std;

int main(){

    readImages("files.txt","data.txt",4);

    Graph<float> g;
    g.setDist(distEucledian);
    g.insertFile("data.txt");

    //g.omegaPrint();

    Graph<float> graph = g.kruskal();
    graph.omegaPrint();

    cout << "Termine\n";

}
