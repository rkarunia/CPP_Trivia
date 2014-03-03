#include "BinSearchTree.hh"
#include <iostream>
#include "BSTTable.hh"
#include <string>

void printItem (int& item)
{
  std::cout<<item<<" ";
}

void func (string& item)
{
  std::cout<<item<<" ";
}

int main (int argc, const char** argv)
{
  BinTree<int> T1, T2;
  BinTree<int> T3(70);
  BinSearchTree<int> TS;

  TS.insert(100);
  TS.insert(90);
  TS.insert(80);
  TS.insert(70);
  TS.insert(150);
  TS.insert(140); 
  TS.insert(160);
  TS.insert(20);
  TS.insert(50);
  TS.insert(40);
  TS.insert(30);
  TS.insert(110); 
  TS.insert(105);
  TS.insert(10);

  std::cout<<"PREORDER                    : ";
  TS.preOrderTraverse(printItem);
  std::cout<<std::endl; 
  std::cout<<"PREORDER (NON-RECURSIVE)    : ";
  TS.preOrderTraverse(printItem, false);
  std::cout<<std::endl; 
  std::cout<<"INORDER                     : ";
  TS.inOrderTraverse(printItem);
  std::cout<<std::endl;  
  std::cout<<"INORDER (NON-RECURSIVE)     : ";
  TS.inOrderTraverse(printItem, false);
  std::cout<<std::endl; 
  std::cout<<"LEVEL ORDER (BFS)           : ";
  TS.levelOrderTraverse(printItem);
  std::cout<<std::endl;
  std::cout<<"POST ORDER                  : ";
  TS.postOrderTraverse(printItem);
  std::cout<<std::endl; 
  std::cout<<"POSTORDER (NON-RECURSIVE)   : ";
  TS.postOrderTraverse(printItem, false);
  std::cout<<std::endl;  
  std::cout<<"POSTORDER (NON-RECURSIVE B) : ";
  TS.postOrderTraverse(printItem, false);
  std::cout<<std::endl; 
  std::cout<<"LEVEL ORDER (BFS) with newline: "<<endl;
  TS.printTreeLevelOrder();
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
  
  BSTTable bstTable;

  string item1 ("Aaron");  string item2 ("Caron");
  string item7 ("Maron");  string item3 ("Baron");
  string item8 ("Naron");  string item4 ("Daron");
  string item9 ("Laron");  string item5 ("Faron");
  string item10 ("Zaron");  string item6 ("Garon");

  bstTable.insert (item1);
  bstTable.insert (item2);  bstTable.insert (item9);
  bstTable.insert (item3);  bstTable.insert (item10);
  bstTable.insert (item4);  bstTable.insert (item8);
  bstTable.insert (item5);
  bstTable.insert (item6);  bstTable.insert (item7);

  bstTable.traverse(func);

  return 0;
}
