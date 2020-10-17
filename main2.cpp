#include <glob.h>
#include <vector>
#include <iostream>
#include <string.h>
#include "CImg.h"

using namespace std;


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


vector<string> globVector(const string& pattern){
    glob_t glob_result;
    glob(pattern.c_str(),GLOB_TILDE,NULL,&glob_result);
    vector<string> files;
    for(unsigned int i=0;i<glob_result.gl_pathc;++i){
        files.push_back(string(glob_result.gl_pathv[i]));
    }
    globfree(&glob_result);
    return files;
}

int main()
{
    vector<string> files = globVector("./*/");
    for(auto it:files){
        cout<<it<<endl;
    }
   
    
   CImg<float>   A("cara.jpeg");
   CImg<float>   B =  A.haar(false,3);
   CImg<float>   c  = B.crop(0,0,27,27);

   vector<float> vc = Vectorizar(c);

   A.display();
   B.display();
   c.display();

   
   
   return 1;
}
//-lX11 y -pthread

