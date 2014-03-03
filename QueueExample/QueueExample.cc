#include <queue>
#include <stack>
#include <iostream>
using namespace std;

void makePalindrome (queue<char>& myqueue)
{
  stack<char> tmp;
  int qsize = myqueue.size();
  for (int i=0; i<qsize; i++)
    {
      char n = myqueue.front();  
      tmp.push(n);    
      myqueue.pop();
      myqueue.push(n);
    }
  while(!tmp.empty())
    {
      myqueue.push(tmp.top());
      tmp.pop();
    }
}

void makeStutter (queue<int>& myqueue)
{
  int qsize = myqueue.size();
  for (int i=0; i<qsize; i++)
    {
      int n = myqueue.front();      
      myqueue.pop();
       
      for (int i=0 ; i<2 ; ++i)
	{
	  myqueue.push(n);
	}
    }
}

int main (int argc, char** argv)
{
  queue<int> myqueue;
  for (int i=1; i<=3; i++)
    {
      myqueue.push(i);
    }
  makeStutter(myqueue);
  //cout<<"Queue: "<<myqueue<<endl;
  while (!myqueue.empty())
    {
      cout<<myqueue.front()<<" ";
      myqueue.pop();
    }
  cout<<endl;

  queue<char>mychar;
  mychar.push('a');
  mychar.push('b');
  mychar.push('c');

  makePalindrome(mychar);

  while (!mychar.empty())
    {
      cout<<mychar.front()<<" ";
      mychar.pop();
    }
  cout<<endl;
}
