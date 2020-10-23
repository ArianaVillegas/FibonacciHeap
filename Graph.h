#include "FibonacciHeap.h"
#include "Functions.cpp"
#include <bits/stdc++.h>

template<typename T>
class Graph{
	
	struct Edge{
		int from, to;
		T value;
	};

	vector<int> rank;
	vector<int> parent;
	vector<Edge> edges;
	vector<string> image_names;

	int size = 0;

	void make_set(int v) {
	    parent[v] = v;
	    rank[v] = 0;
	}

	int find_set(int v) {
	    if (v == parent[v])
	        return v;
	    return parent[v] = find_set(parent[v]);
	}

	void union_sets(int a, int b) {
	    a = find_set(a);
	    b = find_set(b);
	    if (a != b) {
	    	if (rank[a] < rank[b])
            	swap(a, b);
	        parent[b] = a;
	        if (rank[a] == rank[b])
            	rank[a]++;
	    }
	}

public:

	Graph(){};

	void insert(int from, int to, T value){
		edges.push_back({from,to,value});
	}

	void insertFile(string filename){
		vector<vector<long double>> data;

	    ifstream infile;
	    infile.open(filename);

	    string line;
	    vector<long double> image;
	    while (getline(infile, line)) {
	        stringstream ss(line);
	        image.clear();
	        if(getline(ss, line, ' ')){
	            this->image_names.push_back(line);
	        }
	        while(getline(ss, line, ' ')){
	            image.push_back(stold(line));
	        }
	        data.push_back(image);
	    }

	    this->size = data.size();

	    for(int i=0; i<size-1; i++){
	        for(int j=i+1; j<size; j++){
	            insert(i,j,dist(data[i],data[j]));
	        }
	    }
	}

	void setSize(int size){
		this->size = size;
	}

	void setImageNames(vector<string> image_names){
		this->image_names = image_names;
	}

	Graph<T> kruskal(){
		Graph<T> temp;
		FibonacciHeap<T> variable;

		for(Edge e:edges){
			variable.insert(e.value,e.from,e.to);
		}

		rank.clear();
		parent.clear();
		rank.resize(size);
		parent.resize(size);

		for(int i=0; i<size; i++){
			this->make_set(i);
		}

		int num_edges = 0;
		while(variable.getSize() && num_edges < size-1){
			NodeB<T>* min = variable.extractMin();
			if(find_set(min->from) != find_set(min->to)){
				temp.insert(min->from, min->to, min->key);
				union_sets(min->from, min->to);
				num_edges++;
			}
		}

		temp.setSize(size);
		temp.setImageNames(image_names);

		return temp;
	}

	void clusterize(int k){
		k = min(k,size)
		while(k--){
			edges.pop_back();
		}
	}

	void print(){
		for(Edge e : edges){
			cout << e.from <<  "-->" << e.to << " value: " << e.value << '\n';
		}
	}

	void omegaPrint(){
        fstream output("graphviz.dot", ios::out | ios::trunc);
        output << "graph " << endl;
        output << "{" << endl;
        for(int i=0; i<size; i++){
        	output << i << "[image=\"" << image_names[i] << "\",label=\"\"];" << endl;
        }
        for(Edge e : this->edges){
            output << e.from << " -- " << e.to << "[label=\"" << e.value << "\",";
            output << "weight=\"" << e.value << "\"];" << endl;
        }
        output << "}" << endl;
	}

};