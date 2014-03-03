#include <set>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

int sumDigitSquare (int i)
{
  int sumSquareDigit=0;
  while (i!=0)
    {
      int digit = i%10;
      sumSquareDigit += digit*digit;
      i = i/10;
    }
  return sumSquareDigit;
}

bool isHappyNum (int i)
{
  if (i==1)
    return true;
  else if (i<10)
    return false;
  else
    {
      int sum = sumDigitSquare(i);
      //cout<<"SUM: "<<sum<<endl;
      return isHappyNum(sum);
    }
}

bool isHappyInt (int i)
{
  int begin = sumDigitSquare(i);
  //cout<<"Seed number: "<<begin<<endl;
  return isHappyNum(begin);
}

map<string,int> wordOccurences (string filename)
{  
  map<string,int> wordCount;
  string input;
  ifstream ifs(filename.c_str());
  if (ifs.good())
    {
      while (ifs>>input)
	{
	  if (wordCount.find(input) != wordCount.end())
	    wordCount[input] = wordCount[input]+1;
	  else
	    wordCount[input] = 1;
	}
    }
  else
    {
      cout<<"Failed to open file: "<<filename<<endl;
      return wordCount;
    }
  ifs.close();
  return wordCount;
}

int uniqueWordCount (string filename) 
{
  string input;
  set<string> uniqueWords;
  ifstream ifs(filename.c_str());
  if (ifs.good())
    {
      while (ifs>>input)
	{
	  uniqueWords.insert(input);
	}
    }
  else
    {
      cout<<"Failed to open file: "<<filename<<endl;
      return -1;
    }
  ifs.close();
  return uniqueWords.size();
}

int main (int argc, char** argv)
{
  string filename = "/home/rkarunia/Interview/data/Genesis.txt";
  cout <<"Unique words in Genesis are: "<<uniqueWordCount(filename)<<endl;

  map<string,int> mymap;
  mymap = wordOccurences(filename);
  map<string,int>::iterator it;
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    {
      cout<<it->first<<" : "<<it->second<<endl;
    }

  for (int happy = 0; happy<101; ++happy)
    cout<<"Is "<<happy<<" a happy int? "<<((isHappyInt(happy))?"Yes":"No")<<endl;
}
