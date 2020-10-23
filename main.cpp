#include "Graph.h"
#include "Functions.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//int arr[] = {8, 9, 3, 5, 9, 1, 6, 7, 2, 2};

int main(){

    vector<vector<long double>> data;
    vector<string> image_names;

    ifstream infile;
    infile.open("data.txt");

    int i=0;
    string line;
    vector<long double> image;
    while (getline(infile, line)) {
        stringstream ss(line);
        image.clear();
        if(getline(ss, line, ' ')){
            image_names.push_back(line);
        }
        while(getline(ss, line, ' ')){
            image.push_back(stold(line));
        }
        data.push_back(image);
        //if((++i)==100) break;
    }

    /*.push_back({1,2,4,5,6});
    data.push_back({10,2,4,1,6});
    data.push_back({1,0,4,5,13});
    data.push_back({12,2,7,5,2});*/

    Graph<long double> g;
    int size = data.size();
    g.setSize(size);
    g.setImageNames(image_names);
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            g.insert(i,j,dist(data[i],data[j]));
        }
    }

    //g.omegaPrint();

    Graph<long double> graph = g.kruskal();
    //graph.omegaPrint();

    cout << "Termine\n";

}
