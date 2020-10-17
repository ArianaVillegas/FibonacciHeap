#include <vector> 
#include <iostream>
#include <fstream>
int cont =0;

using namespace std;
template<typename T>
struct NodeB{
    int grade=0; 
    T key;
    vector<NodeB<T>*> children;
    NodeB<T>* parent;
    int from,to;

    NodeB(T key1, int from, int to):key(key1),from(from),to(to),parent(nullptr){};

    /*void print(){
        for(auto it:children){
            it->print();
        }
        cout<<key<<" ";
        
    }*/

    NodeB<T>* find(T number){
        if (this->key==number){ 
            return this;
        }
        NodeB<T>* retorno=nullptr;
        for(auto it:children){
            retorno=it->find(number);
            if(retorno!=nullptr)break;
        }
        return retorno;
        
    }

    void omegaprint(fstream& out, int &cnt){
        int p = cnt;
        out << "n" << p << " [label=\"" << key << "\"] ;" << endl;
        for(auto it:children){
            cnt++;
            out << "n" << p << " -- n" << ++cnt << " ;" << endl;
            it->omegaprint(out, cnt);
        }
    }
};