#include<ctime>
#include<iostream>
using namespace std;
int main()
{
    time_t start=time();
    int a;
    clock_t begin=clock();
     for(float i=0;i<10000;i+=.01)
     {
          a++;
     }
     clock_t end =clock();
     double time=100*double(end-begin)/CLOCKS_PER_SEC;
     int t=double(time);
     cout<<t;
}
