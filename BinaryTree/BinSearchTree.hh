#ifndef binsrchtree_h
#define binsrchtree_h

#include <stdio.h>
#include <assert.h>
#include "BinTree.hh"
#include <iostream>

using namespace std;


template <class T>
class BinSearchTree : public BinTree<T>
{
public:

  virtual void insert (T item);
  virtual bool remove (T item);
  virtual bool retrieve (T item);

protected:

  void insertItem (treeNode<T>*& node, T item);
  void deleteLeftMostNodeFromRightSubTree (treeNode<T>*& node, T& item);
  bool deleteItem (treeNode<T>*& node, T item);
  treeNode<T>* retrieveItem (treeNode<T> *node, T item);
};

template <class T>
void BinSearchTree<T>::insert (T item)
{ 
  if (!BinTree<T>::rootPtr())
    {
      BinTree<T>::setRootData(item);
      return;
    }
  treeNode<T>* root = BinTree<T>::rootPtr();
  insertItem (root, item); 
}

template <class T>
void BinSearchTree<T>::insertItem (treeNode<T>*& node, T item)
{ 
  if (!node)
    node = new treeNode<T> (item, 0, 0);
    
  if (item < node->item)
    insertItem (node->leftChild, item);
  else if (item > node->item)
    insertItem (node->rightChild, item);
}

template <class T>
bool BinSearchTree<T>::remove (T item)
{  
  if (!BinTree<T>::rootPtr())
    return false;
  treeNode<T>* itemPtr = retrieveItem (BinTree<T>::rootPtr(), item);
  if (!itemPtr)
    return false; 
  if (deleteItem (itemPtr, item))
    return true;
  return false;
}

template <class T>
bool BinSearchTree<T>::deleteItem (treeNode<T>*& itemNode, T item)
{
  if (!itemNode)
    return false;
  
  if (!itemNode->leftChild && !itemNode->rightChild)
    {
      delete itemNode;
      itemNode = 0;
      return true;
    }
  else if (itemNode->leftChild && !itemNode->rightChild)
    {
      treeNode<T>* tmp = itemNode;
      itemNode = itemNode->leftChild;
      delete tmp;
      return true;
    }
  else if (!itemNode->leftChild && itemNode->rightChild)
    {
      treeNode<T>* tmp = itemNode;
      itemNode = itemNode->rightChild;
      delete tmp;
      return true;
    }
  else
    {
      T replacement;
      treeNode<T>*& itemRightChild = itemNode->rightChild;
      deleteLeftMostNodeFromRightSubTree (itemRightChild, replacement);
      cout <<"REPL: "<<replacement<<endl;
      itemNode->item = replacement;
      return true;
    }
  return false;
}

template <class T>
void BinSearchTree<T>::deleteLeftMostNodeFromRightSubTree (treeNode<T>*& node, T& item)
{
  if (!node) 
    return;
  if (!node->leftChild)
    {
      item = node->item;
      treeNode<T>* tmp = node;
      node = node->rightChild;
      tmp->rightChild = 0;
      delete tmp;
    }
  else
    deleteLeftMostNodeFromRightSubTree (node->leftChild, item);
}

template <class T>
bool BinSearchTree<T>::retrieve (T item)
{
  if (retrieveItem (BinTree<T>::rootPtr(), item))
    return true;
  return false;   
}

template <class T>
treeNode<T>* BinSearchTree<T>::retrieveItem (treeNode<T>* node, T item)
{
  if (!node)
    return 0; 
  else if (item == node->item)
    return node;
  else if (item < node->item)
    return retrieveItem (node->leftChild, item);
  else if (item > node->item)
    return retrieveItem (node->rightChild, item);
  return 0;
}

#endif
