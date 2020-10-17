#include "node.cpp"
#include <bits/stdc++.h>
#include <unistd.h>

template< typename T>
class FibonacciHeap{
    int size=0;
    int grade=0;
    list<NodeB<T>*> heap;
    NodeB<T>* min=nullptr;
    
    NodeB<T>* unir(NodeB<T>* a,NodeB<T>* b){
        if(a->grade==grade){
            grade++;
        }
        if(a->key<b->key){
            a->children.push_back(b);
            b->parent=a;
            a->grade++;
            return a;
        }else{
            if(a == min) min = b;
            b->children.push_back(a);
            a->parent=b;
            b->grade++;
            return b;
        }
        
    }

    void compactar_aux(vector<NodeB<T>*> &grades, NodeB<T>* node){
        if(grades[node->grade] == nullptr){
            grades[node->grade] = node;
        } else {
            auto cur_grade = node->grade;
            NodeB<T>* temp = unir(node, grades[node->grade]);
            grades[cur_grade] = nullptr;
            compactar_aux(grades, temp);
        }    
    }

    void compactar(){
        vector<NodeB<T>*> grades(log2(this->size)+1,nullptr);
        for(NodeB<T>* node : heap){
            compactar_aux(grades,node);
        }
        heap.clear();
        for(NodeB<T>* node : grades){
            if(node != nullptr) heap.push_back(node);
        }
    }

    void insert(NodeB<T>* elem){
        if(min==nullptr or min->key>elem->key){
            min=elem;
        }
        heap.push_back(elem);
        size++;
    }

    NodeB<T>* findMin(){
        NodeB<T>* retorno=new NodeB<T>(INT_MAX);
        for(NodeB<T>* node : heap){
            if(retorno->key > node->key){
                retorno = node;
            }
        }
        return retorno;
    }

public:

    FibonacciHeap(){};

    void insert(T elem){
        insert(new NodeB<T>(elem));
    }

    T extractMin(){
        T key = min->key;
        deleteMin();
        return key;
    }

    void deleteMin(){
        heap.remove(min);
        for(auto it:min->children){
            this->insert(it);
        }
        this->compactar();
        min = findMin();
    }
    

    /*void print(){
        for(auto it:heap){
            it.second->print();
            cout<<endl;
        }
    }*/

    void omegaprint(int i){
        cont=0;
        fstream output("graphviz.dot", ios::out | ios::trunc);
        output << "graph \"\"" << endl;
        output << "{" << endl;
        output << "label=\"besto trabajo ever\"" << endl;
        int cnt=0;
        for(NodeB<T>* ptr : heap){
            output << "subgraph cluster" << cnt << endl;
            output << "{" << endl;
            output << "label=\"Grado: " << ptr->grade << "\"" << endl;
            output << "n" << cnt << " ;"<< endl;
            ptr->omegaprint(output,cnt);
            cnt++;
            output << "}" << endl;
        }
        output << "}" << endl;
    }

};