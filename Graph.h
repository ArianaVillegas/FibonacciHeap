#include "FibonacciHeap.h"
#include "Functions.cpp"
#include <bits/stdc++.h>

template<typename T>
class Graph{

	struct Node{
		vector<T> image;
		string image_name;
	};
	
	struct Edge{
		int from, to;
		T value;
	};

	vector<int> rank;
	vector<int> parent;
	vector<Edge*> edges;
	vector<Node*> nodes;

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

	Node* newNode(){
		Node* node = new Node();
		return node;
	}

	Edge* newEdge(){
		Edge* edge = new Edge();
		return edge;
	}

	void insertNode(Node* node){
		nodes.push_back(node);
	}

	void insertEdge(Edge* edge){
		edges.push_back(edge);
	}

	void insertFile(string filename){
	    ifstream infile;
	    infile.open(filename);

	    string line, image_name;
	    vector<T> image;
	    while (getline(infile, line)) {
	        stringstream ss(line);
	        image.clear();
	        Node* node = newNode();
	        if(getline(ss, line, ' ')){
	            node->image_name = line;
	        }
	        while(getline(ss, line, ' ')){
	            node->image.push_back(stold(line));
	        }
	        insertNode(node);
	    }

	    for(int i=0; i<size-1; i++){
	        for(int j=i+1; j<size; j++){
	        	Edge* edge = newEdge();
	        	(*edge) = {i,j,dist(nodes[i]->image,nodes[j]->image)};
	            insertEdge(edge);
	        }
	    }
	}

	Graph<T> kruskal(){
		Graph<T> temp;
		FibonacciHeap<T> variable;

		for(Edge* e:edges){
			variable.insert(e->value,e->from,e->to);
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
				Edge* edge = newEdge();
	        	(*edge) = {min->from, min->to, min->key};
				temp.insertEdge(edge);
				union_sets(min->from, min->to);
				num_edges++;
			}
		}

		return temp;
	}

	void clusterize(int k){
		k = min(k,size);
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
        	output << i << "[image=\"" << nodes[i]->image_name << "\",label=\"\"];";
        	output << endl;
        }
        for(Edge* e : this->edges){
            output << e->from << " -- " << e->to << "[label=\"" << e->value << "\",";
            output << "weight=\"" << e->value << "\"];" << endl;
        }
        output << "}" << endl;
	}

};