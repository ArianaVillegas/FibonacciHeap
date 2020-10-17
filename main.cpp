#include "Graph.h"
#include "Functions.cpp"

//int arr[] = {8, 9, 3, 5, 9, 1, 6, 7, 2, 2};

int main(){

    vector<vector<int>> data;

    data.push_back({1,2,4,5,6});
    data.push_back({10,2,4,1,6});
    data.push_back({1,0,4,5,13});
    data.push_back({12,2,7,5,2});

    Graph<long double> g;
    g.setSize(4);
    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            g.insert(i,j,dist(data[i],data[j]));
        }
    }

    g.omegaPrint();

    Graph<long double> graph = g.kruskal();
    //graph.omegaPrint();

}
