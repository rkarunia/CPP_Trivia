#include <string>
#include <iostream>
#include <stack>
#include <ctype.h>
using namespace std;

int checkPalindrome (string p, bool casesensitive= false)
{
  stack<char> l;
  int i = 0;
  for (i = 0; i<(int)(p.length()/2); ++i)
    {
      char c = casesensitive?p[i]:tolower(p[i]);
      l.push(c);
    }
  if (p.length()%2)
    i++;
  for (i; i<(int)p.length(); i++)
    {
      char c = casesensitive?p[i]:tolower(p[i]);
      if (l.top()!=c)
	return i;
      else
	l.pop();
    }
  if (l.empty())
    return -1;
  else
    return 10;
}

int checkBalance(string code) 
{
  stack<char> parens;
  for (int i = 0; i < (int) code.length(); i++) 
    {
      char c = code[i];
      if (c == '(' || c == '{') 
	{
	  parens.push(c);
	} 
      else if (c == ')' || c == '}') 
	{
	  if (parens.empty()) 
	    {
	      return i;
	    }
	  char top = parens.top();
	  if ((top == '(' && c != ')') || (top == '{' && c != '}'))
	    {
	      return i;
	    }
	  else
	    parens.pop();
	}
    }
  
  if (parens.empty()) 
    {
      return -1;
      // balanced
    } 
  else 
    {
      return 10;
    }
}

int main (int argc, char** argv)
{
  string test1 = "int main () { return true; }";
  string test2 = "void unbalance ({return false;}";

  cout << "Test 1, string: "<<test1<<", "<<checkBalance(test1)<<endl;
  cout << "Test 2, string: "<<test2<<", "<<checkBalance(test2)<<endl;

  string palin1 = "ASASA";
  string palin2 = "HONDA";

  cout <<"Test palin1: "<<palin1<<", "<<checkPalindrome(palin1)<<endl;
  cout <<"Test palin2: "<<palin2<<", "<<checkPalindrome(palin2)<<endl;
}
