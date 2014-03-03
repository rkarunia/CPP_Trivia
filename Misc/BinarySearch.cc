#include <iostream>
using namespace std;

int binarySearch (const int list[], int first, int last, int value)
{
  cout<<first<<","<<last<<endl;
  // Base case
  if (first>last)
    return -1;
  else
    {
      int mid = (last+first)/2;      
      if (list[mid] == value) 
	return mid;
      else
	{
	  if (value<list[mid])
	    binarySearch (list, first, mid-1, value);
	  else
	    binarySearch (list, mid+1, last, value);
	}
    }
}

int regSearch (const int list[], int size, int val)
{
  for (int i=0; i<size;++i)
    {
      cout<<i<<endl;
      if (val==list[i])
	return i;
    }
  return -1;
}

int max (const int list[], int a, int b)
{
  if (list[a]>list[b]) return a;
  else return b;
}

// Return the index of the max value in an array
int maxArray (const int list[], int first, int last)
{
  cout <<"First: "<<first<<"Last: "<<last<<endl;
  if (first==last)
    return first;
  else
    {
      int mid = (first + last)/2;
      //int max1 = maxArray (list, first, mid);
      //int max2 = maxArray (list, mid+1, last);
      //if (list[max1]>list[max2])
      //return max1;
      //else
      //return max2;

      return max(list, maxArray(list, first, mid), maxArray(list, mid+1, last));
    }
}
 
int main (int argc, char** argv)
{
  int size = 50;
  int array[size];

  for (int i=0; i<size; ++i)
    array[i]=i+1;

  int loc = binarySearch (array, 0, size-1, 1);

  cout<< "LOC: "<<loc<<endl;

  int loc2 = regSearch ( array, size, 1);

  cout<<"LOC2: "<<loc2<<endl;

  int array2[4];
  array2[0] = 1;
  array2[1] = 6;
  array2[2] = 8;
  array2[3] = 3;
  cout<<"MaxArray: "<<maxArray(array2, 0, 3)<<endl;
}
