#include "FibonacciHeap.cpp"

//int arr[] = {8, 9, 3, 5, 9, 1, 6, 7, 2, 2};

int main(){
    srand(time(NULL));
    FibonacciHeap<int> variable;
    int stop=rand()%10;
    int to_change;
    for(int i=1000;i>0;i--){
        /*int temp=rand()%10;
        if(i==stop){
            to_change=temp;
        }*/
        //cout<<i<<" ";
        variable.insert(i);
    }

    for(int i=1000;i>0;i--){
        variable.extractMin();
        if(i%10) continue;
        variable.omegaprint(i);
        string command = "dot -Tpng graphviz.dot -o out"+to_string(i)+".png";
        system(command.c_str());
        system("rm graphviz.dot");
    }
}
