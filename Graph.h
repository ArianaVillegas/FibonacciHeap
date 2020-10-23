#include "FibonacciHeap.h"
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