#include "BinSearchTree.hh"
#include <iostream>

void printItem (int& item)
{
  std::cout<<item<<" ";
}

int main (int argc, const char** argv)
{
  BinTree<int> T1, T2;
  BinTree<int> T3(70);
  BinSearchTree<int> TS;

  TS.insert(40);
  TS.insert(30);
  TS.insert(50);
  TS.insert(20);
  TS.insert(10); 
  TS.insert(60);
  TS.insert(70);

  TS.preOrderTraverse(printItem);
  std::cout<<std::endl;
  TS.inOrderTraverse(printItem);
  std::cout<<std::endl; 
  TS.postOrderTraverse(printItem);
  std::cout<<std::endl;

  TS.remove(40);
  TS.preOrderTraverse(printItem);
  std::cout<<std::endl;
  TS.inOrderTraverse(printItem);
  std::cout<<std::endl; 
  TS.postOrderTraverse(printItem);
  std::cout<<std::endl;

  T1.setRootData(40);
  T1.attachLeft(30);
  T1.attachRight(50);
  T1.preOrderTraverse(printItem);
  std::cout<<std::endl;
  T1.inOrderTraverse(printItem);
  std::cout<<std::endl; 
  T1.postOrderTraverse(printItem);
  std::cout<<std::endl;

  T2.setRootData(20);
  T2.attachLeft(10);
  T2.attachRightSubTree(T1);  
  T2.preOrderTraverse(printItem);
  std::cout<<std::endl;
  T2.inOrderTraverse(printItem);
  std::cout<<std::endl; 
  T2.postOrderTraverse(printItem);
  std::cout<<std::endl;
  
  BinTree<int> T (60, T2, T3);
  
  T.preOrderTraverse(printItem);
  std::cout<<std::endl;
  T.inOrderTraverse(printItem);
  std::cout<<std::endl; 
  T.postOrderTraverse(printItem);
  std::cout<<std::endl;
  
  return 0;
}
