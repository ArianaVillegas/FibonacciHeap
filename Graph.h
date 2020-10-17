#include "FibonacciHeap.h"
#include <bits/stdc++.h>

template<typename T>
class Graph{
	
	struct Edge{
		int from, to;
		T value;
	};

	vector<Edge> edges;
	vector<int> parent;
	vector<int> rank;

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

	Graph<T> kruskal(){
		Graph<T> temp;
		FibonacciHeap<T> variable;

		for(Edge e:edges){
			variable.insert(e.value,e.from,e.to);
		}

		parent.clear();
		rank.clear();
		parent.resize(size);
		rank.resize(size);

		for(int i=0; i<size; i++){
			this->make_set(i);
		}

		while(variable.getSize()){
			NodeB<T>* min = variable.extractMin();
			if(find_set(min->from) != find_set(min->to)){
				temp.insert(min->from, min->to, min->key);
				union_sets(min->from, min->to);
			}
		}

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
        for(Edge e : this->edges){
            output << e.from << " -- " << e.to << "[label=\"" << e.value << "\",";
            output << "weight=\"" << e.value << "\"];" << endl;
        }
        output << "}" << endl;
	}

};