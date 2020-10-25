#include "Graph.h"
#include "ReadImage.h"
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main(){

    /*readImages("files.txt","data1.txt",1);
    readImages("files.txt","data2.txt",2);
    readImages("files.txt","data3.txt",3);
    readImages("files.txt","data4.txt",4);
    */
    Graph<float> g;
    g.setDist(distEucledian);
    g.insertFile("data.txt");

    //g.omegaPrint();

    clock_t time_req = clock();
    Graph<float> graph = g.kruskal();
    time_req = clock() - time_req;
    graph.clusterize(80);
    graph.omegaPrint();

    cout << "Tiempo de ejecución: " << (float)time_req/CLOCKS_PER_SEC << " s \n";

}
