#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void fillup(double* p, const int N, const double dx,
           const double xmin)
  {
    for(int i=0; i<N; i++)
    {
     p[i]=exp(-(xmin+i*dx)*(xmin+i*dx));
          
    }  
  }
  
void ableiten(double* p, const int N, const double dx,
           const double xmin)
  {
    double a,b;
    b=0;
    p[N+1]=0;
    for(int i=1; i<N; i++)
    {
     a=p[i];
     p[i]=(p[i+1]-b)/2/dx;
     b=a;
    }  
    
  }


void print(double* p, const int N, const double dx,
           const double xmin)
{ 
 ofstream out("dateiableitungskrampf.dat");
   for(int i=0; i<N; i++)
   {   
     cout << i*dx + xmin << "\t" << p[i] << endl;
     out<< i*dx + xmin << "\t" << p[i] << endl;
   }
   
   
 out.close();
}


int main(){

  const int N = 100;
  double p[N+1];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  // call to function which fills array p here
  fillup(p,N,dx,xmin);
  // call to function which calculates the derivative
  ableiten(p,N,dx,xmin);
  
  print(p,N,dx,xmin);

  return 0;
}
