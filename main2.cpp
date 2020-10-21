#include <vector>
#include <iostream>
#include <string.h>
#include "CImg.h"
#include <fstream>

using namespace std;
string temp;
vector<string> files;
using namespace cimg_library;


vector<float>  Vectorizar(CImg<float>   & img )
{
         vector<float> R;
         cimg_forXY(img,x,y) 
          { 
              R.push_back( (img(x,y,0) + img(x,y,1) +  img(x,y,2))/3);
          }
         return R;
}

int main()
{
    //find /home/cesar/Desktop/git/eda/nuevo\ inicio\ /FibonacciHeap -type f -exec file --mime-type {}  \; | awk '{if ($NF == "image/jpeg") print $3 }' >files.txt
    fstream a("files.txt");
    
    while(a>>temp){
        temp.pop_back();
        files.push_back(temp);
    }  
    for(auto it:files){
        CImg<float>   A(it.c_str());
        CImg<float>   B =  A.haar(false,3);
        CImg<float>   c  = B.crop(0,0,27,27);
        vector<float> vc = Vectorizar(c);

        cout<<it<<" ";
        for ( auto it2:vc){
            cout<<it2<<" ";
        }
        cout<<endl;
    }


   
   
    return 1;
}
//-lX11 y -pthread

