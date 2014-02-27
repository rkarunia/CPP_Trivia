#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Sorter.hh"

using namespace std;

template <class T>
int ascend_compar (T a, T b)
{
  if (a<b) return -1;
  else if (a>b) return 1;
  else return 0;
}

template <class T>
int descend_compar (T a, T b)
{
  if (a<b) return 1;
  else if (a>b) return -1;
  else return 0;
}
	
int main (int argc, const char** argv)
{
  int n; 

  if (argc==1)
    n=100;
  else if (argc==3)
    {
      if (strcmp(argv[1], "-n")==0)
	{
	  n = atoi(argv[2]);
	}
      else
	exit(-1);
    }
  else
    exit(-1);

  srand (888);
 
  cout<<"N: "<<n<<endl;

  //if ((n<1) || (n>500001)) exit(-1);
  
  //int a[n];
  //int b[n];
  //int c[n];
  //int d[n];
  //int e[n];

  char chr[26];
  chr[10] = 'a';
  chr[9] = 'b';
  chr[8] = 'c';
  chr[7] = 'd';
  chr[6] = 'e';  
  chr[5] = 'f';
  chr[4] = 'g';  
  chr[3] = 'h';
  chr[2] = 'i';  
  chr[0] = 'j';
  chr[1] = 'k';  
  chr[11] = 'l';
  chr[12] = 'm';  
  chr[13] = 'n';
  chr[14] = 'o';
  chr[15] = 'p';
  chr[16] = 'q'; 
  chr[17] = 'r';
  chr[18] = 's';  
  chr[19] = 't';
  chr[20] = 'u'; 
  chr[25] = 'v';
  chr[24] = 'w';
  chr[23] = 'x';
  chr[22] = 'y'; 
  chr[21] = 'z';
 
  double duration=0.0;
  
  for (int i=0; i<n; ++i)
    {
      int r = rand()%n;
      //a[i] = r;
      //b[i] = r;
      //c[i] = r;
      //d[i] = r;
      //e[i] = r;
    }

  //for (int i=0; i<20; ++i)
  //cout<<a[i]<<" ";
  //cout<<endl;

  clock_t start = clock();
  bblSort(chr, 26, descend_compar);
  duration = (clock() - start) / (double) CLOCKS_PER_SEC;
  for (int i=0; i<26; ++i)
    cout<<chr[i]<<" ";
  cout<<endl;
  cout<<"BUBBLE SORT DURATION FOR "<<26<<" ITEMS IS: "<<duration<<" SECONDS."<<endl;

  //clock_t start = clock();
  //bblSort(chr, 26, ascend_compar);
  //duration = (clock() - start) / (double) CLOCKS_PER_SEC;
  //for (int i=0; i<20; ++i)
  //cout<<a[i]<<" ";
  //cout<<endl;
  //cout<<"BUBBLE SORT DURATION FOR "<<n<<" ITEMS IS: "<<duration<<" SECONDS."<<endl;
  
  start = clock();
  //insSort(b, n, ascend_compar);
  duration = (clock() - start) / (double) CLOCKS_PER_SEC;
  //for (int i=0; i<20; ++i)
  //cout<<b[i]<<" ";
  //cout<<endl;
  cout<<"INSERTION SORT DURATION FOR "<<n<<" ITEMS IS: "<<duration<<" SECONDS."<<endl;
  
  start = clock();
  //mrgSort(c, 0, n-1, ascend_compar);
  //duration = (clock() - start) / (double) CLOCKS_PER_SEC;
  //for (int i=0; i<20; ++i)
  //cout<<c[i]<<" ";
  //cout<<endl;
  cout<<"MERGE SORT DURATION FOR "<<n<<" ITEMS IS: "<<duration<<" SECONDS."<<endl;
  
  start = clock();
  //selSort(d, n, ascend_compar);
  duration = (clock() - start) / (double) CLOCKS_PER_SEC;
  //for (int i=0; i<20; ++i)
  //cout<<d[i]<<" ";
  //cout<<endl;
  cout<<"SELECTION SORT DURATION FOR "<<n<<" ITEMS IS: "<<duration<<" SECONDS."<<endl;

  start = clock();
  //qwkSort(e, 0, n-1, ascend_compar);
  //duration = (clock() - start) / (double) CLOCKS_PER_SEC;
  //for (int i=0; i<20; ++i)
  //cout<<e[i]<<" ";
  //cout<<endl;
  cout<<"QUICK SORT DURATION FOR "<<n<<" ITEMS IS: "<<duration<<" SECONDS."<<endl;
}
