#ifndef sorter_h
#define sorter_h

//
// Sortapalooza
//
// Implementation of
// mergeSort, quickSort, bubbleSort, selectionSort, insertionSort
//
// Ronald Karunia
//

template <class T>
void swap (T& a, T& b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <class T>
// index of smallest or largest depends on the compar function
int indexOfSmallest (T a[], int n, int start, int (*compar) (T a, T b))
{
  // n = size of array a
  // i = the search starting index 
  int idxSmall = start;
  for (int i=start+1; i<n; ++i)
    {
      if (compar(a[i], a[idxSmall])<0) 
	idxSmall = i;
    }
  return idxSmall;
}

// To be used with qwkSort() func
template <class T>
void partition (T a[], int start, int end, int& pivotIndex, int (*compar) (T a, T b))
{
  // Partition array a only from start to end by the pivot value
  // S1 = a[start...pivotIndex-1] < pivot value
  // S2 = a[pivotIndex+1...end] > pivot value
  // a[pivotIndex] == pivot value

  // Initial condition pre partition
  T pivot = a[start]; // assume pivot value is a[start]
  int e1 = start; // e1 = index of the last element in region S1
  int fu = start+1; 
  //fu = first unknown, initially all items are in the unknown region, S1 and S2 are empty.
 
  for (; fu <= end; ++fu)
    {
      if (compar(a[fu],pivot)<0)
	{
	  e1++;
	  swap(a[fu],a[e1]);
	}
    }
  swap(a[start],a[e1]);
  pivotIndex = e1;
}

// To be used with mrgSort() func
template <class T>
void merge (T a[], int start, int mid, int end, int (*compar) (T a, T b))
{
  int tmpsize = end - start + 1;
  T tmp[tmpsize];

  int s1 = start;
  int e1 = mid;
  int s2 = mid+1;
  int e2 = end;
  int i  = 0;
  int j  = 0;

  for (i=0; i<tmpsize; ++i)
    {
      if ((s1<=e1)&&(s2<=e2))
	{
	  if (compar(a[s1],a[s2])<0)
	    {
	      tmp[i] = a[s1];
	      s1++;
	    }
	  else
	    {
	      tmp[i] = a[s2];
	      s2++;
	    }
	}
      else
	break;
    }
  for (j=s1; j<=e1; ++j)
    {
      if (i<tmpsize)
	{
	  tmp[i] = a[j];
	  i++;
	}
    }
  for (j=s2; j<=e2; ++j)
    {
      if (i<tmpsize)
	{
	  tmp[i] = a[j];
	  i++;
	}
    }
  i=0;
  for (j=start; j<=end; ++j)
    {
      a[j] = tmp[i];
      i++;
    }
}

// Quick Sort
template <class T>
void qwkSort (T a[], int start, int end, int (*compar) (T a, T b))
{
  int pivotIndex=0;
  
  if (start<end)
    {
      partition(a, start, end, pivotIndex, compar);
      
      qwkSort(a, start, pivotIndex-1, compar);
      qwkSort(a, pivotIndex+1, end, compar);
    }
}

// Merge Sort
template <class T>
void mrgSort (T a[], int start, int end, int (*compar) (T a, T b))
{
  if (start < end)
    {
      int mid = (start+end)/2;
      mrgSort(a, start, mid, compar);
      mrgSort(a, mid+1, end, compar);
      
      merge (a, start, mid, end, compar);
    }
}

// Selection Sort
template <class T>
void selSort (T a[], int n, int (*compar) (T a, T b))
{
  // n is the size of array a
  for (int i=0; i<n; ++i)
    {
      int idxSmall = indexOfSmallest(a, n, i, compar);
      swap (a[i], a[idxSmall]);
    }
}

// Modified Bubble Sort
template <class T>
void bblSort (T a[], int n, int (*compar) (T a, T b))
{
  bool swapped = false;

  // n = the size of array a
  for (int i = n-1; i >= 0; --i)
    {
      swapped = false;

      for (int j = 0; j<i; ++j)
	{
	  if (compar(a[j], a[j+1])>0) 
	    {
	      swapped = true;
	      swap(a[j], a[j+1]);
	    }
	}

      if (!swapped)
	break;
    }
}

// Insertion Sort
template <class T>
void insSort (T a[], int n, int (*compar) (T a, T b))
{
  for (int i = 1; i<n; ++i)
    {
      T next = a[i];
      int loc;
      for (loc = i; loc>0; --loc)
	{
	  if (compar(a[loc-1],next)>0)
	    a[loc] = a[loc-1];
	  else
	    break;
	}
      a[loc] = next;
    }
}

#endif
