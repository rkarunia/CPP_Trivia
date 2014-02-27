#ifndef binsrchtree_h
#define binsrchtree_h

#include <stdio.h>
#include <assert.h>
#include "BinTree.hh"

template <class T>
class BinSearchTree : public BinTree<T>
{
public:

  virtual void insert (T item);
  virtual void remove (T item);
  virtual bool retrieve (T& item);

protected:

  void insertItem (treeNode<T>*& node, T item);
  void processLeftMost (treeNode<T>*& node, T& item);
  void deleteRootItem (treeNode<T>*& root);
  void deleteItem (treeNode<T>*& node, T item);
  bool retrieveItem (treeNode<T> *node, T& item);
};

template <class T>
void BinSearchTree<T>::insert (T item)
{
  //treeNode<T>* rootCopy = BinTree<T>::rootPtr();
  //insertItem (rootCopy, item);
  insertItem(BinTree<T>::rootPtrRef(), item);
}

template <class T>
void BinSearchTree<T>::insertItem (treeNode<T>*& node, T item)
{
  if (!BinTree<T>::rootPtr())
    BinTree<T>::setRootData(item);
      
  if (!node)
    {
      // Insert item
      node = new treeNode<T> (item, 0, 0);
    }
  if (item < node->item)
    insertItem (node->leftChild, item);
  else if (item > node->item)
    insertItem (node->rightChild, item);
}

template <class T>
void BinSearchTree<T>::remove (T item)
{
  deleteItem (BinTree<T>::rootPtrRef(), item);
}

template <class T>
void BinSearchTree<T>::deleteItem (treeNode<T>*& node, T item)
{
  return ;
}

template <class T>
bool BinSearchTree<T>::retrieve (T& item)
{
  return retrieveItem (BinTree<T>::rootPtrRef(), item);
}

template <class T>
bool BinSearchTree<T>::retrieveItem (treeNode<T> *node, T& item)
{
  if (!node)
    return false;
  
  if (item == node->item)
    return true;

  if (item < node->item)
    retrieveItem (node->leftChild, item);
  else if (item > node->item)
    retrieveItem (node->rightChild, item);

  return false;
}

#endif
