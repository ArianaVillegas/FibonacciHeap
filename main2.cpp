#include <vector>
#include <iostream>
#include <string.h>
#define cimg_use_jpeg 1
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
        files.push_back(temp);
    }  
    for(int i=0;i<files.size();i++){
        CImg<float>   A(files[i].c_str());
        A = A.resize(160,160);
        CImg<float>   B =  A.haar(false,4);
        CImg<float>   c  = B.crop(0,0,9,9);
        vector<float> vc = Vectorizar(c);

        cout<<files[i]<<" ";
        for ( auto it2:vc){
            cout<<it2<<" ";
        }
        cout<<endl;
    }


   
   
    return 1;
}
//-lX11 y -pthread

