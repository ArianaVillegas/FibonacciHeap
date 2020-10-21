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
            cout<<img(x,y,0,0)<<endl;
              R.push_back( (img(x,y,0) + img(x,y,1) +  img(x,y,2))/3);
          }
         return R;
}

int main()
{
    //find /home/cesar/Desktop/git/eda/nuevo\ inicio\ /FibonacciHeap -type f -exec file --mime-type {}  \; | awk '{if ($NF == "image/jpeg") print $3 }' >files.txt
    fstream a("files2.txt");
    
    while(a>>temp){
        files.push_back(temp);
    }  
    //for(auto it:files){
        CImg<float>   A(/*it.c_str()*/"93369231.jpg");
        A = A.resize(160,160);
        CImg<float>   B =  A.haar(false,2);
        CImg<float>   c  = B.crop(0,0,10,10);
        vector<float> vc = Vectorizar(c);

        for ( auto it2:vc){
            cout<<it2<<" ";
        }
        cout<<endl;
    //}


   
   
    return 1;
}
//-lX11 y -pthread

