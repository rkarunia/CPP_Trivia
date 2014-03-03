#ifndef bintree_h
#define bintree_h

#include <stdio.h>
#include <assert.h>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

template <class T>
struct treeNode
{
  T item;
  treeNode *leftChild;
  treeNode *rightChild;

  treeNode(T it, treeNode *left, treeNode *right):
    item(it),
    leftChild(left),
    rightChild(right)
  {}
};

template <class T>
class BinTree
{
public:

  BinTree ();
  virtual ~BinTree ();
  
  BinTree (T rootItem);
  BinTree (T rootItem,
	   BinTree left,
	   BinTree right);
  
  // Copy const
  BinTree (const BinTree& tree);
  
  virtual bool isEmpty ();

  // Accessor 
  virtual T rootData ();
  virtual void setRootData (T newItem);
  virtual bool attachLeft (T newItem);
  virtual bool attachRight (T newItem);
  virtual bool attachLeftSubTree (BinTree left);
  virtual bool attachRightSubTree (BinTree right);
  virtual bool detachLeftSubTree (BinTree left);
  virtual bool detachRightSubTree (BinTree right);
  virtual BinTree leftSubTree ();
  virtual BinTree rightSubTree ();
  
  // Traversal
  virtual void preOrderTraverse (void (*func) (T&), bool recur=true);
  virtual void inOrderTraverse (void (*func) (T&), bool recur=true);  
  virtual void postOrderTraverse (void (*func) (T&), bool recur=true);
  virtual void levelOrderTraverse (void (*func)(T&));

  // Overload
  virtual void operator= (const BinTree& atree);

  void printTreeLevelOrder ();

protected:

  BinTree (treeNode<T> *node);
  void copyTree (treeNode<T> *tree, treeNode<T>*& newTree);
  void destroyTree (treeNode<T>*& tree);
  void setRootPtr (treeNode<T> *newRoot);
  treeNode<T>* rootPtr();
  treeNode<T>*& rootPtrRef();
  
  void preOrder (treeNode<T> *tree, void (*func) (T&));
  void inOrder (treeNode<T> *tree, void (*func) (T&));
  void postOrder (treeNode<T> *tree, void (*func) (T&));
  void levelOrder (treeNode<T> *tree, void (*func) (T&));
  void inOrderNonRecursive (treeNode<T> *tree, void (*func) (T&));
  void preOrderNonRecursive (treeNode<T> *tree, void (*func) (T&));
  void postOrderNonRecursive (treeNode<T> *tree, void (*func) (T&));
  void postOrderNonRecursiveB (treeNode<T> *tree, void (*func) (T&));

private:

  treeNode<T>* root;
};

template <class T>
BinTree<T>::BinTree (): root(0)
{
}

template <class T>
BinTree<T>::~BinTree ()
{
  destroyTree(root);
}

template <class T>
BinTree<T>::BinTree (T rootItem)
{
  root = new treeNode<T>(rootItem, 0, 0);
  assert(root!=0);
}

template <class T>
BinTree<T>::BinTree (T rootItem,
		  BinTree left,
		  BinTree right)
{  
  root = new treeNode<T>(rootItem, 0, 0);
  assert(root!=0);

  if (attachLeftSubTree(left))
    assert(attachRightSubTree(right));
}
  
// Copy const
template <class T>
BinTree<T>::BinTree (const BinTree& tree)
{
  copyTree(tree.root, root);
}
  
template <class T>
bool BinTree<T>::isEmpty ()
{
  return (root==0);
}

// Accessor 
template <class T>
T BinTree<T>::rootData ()
{
  assert (root!=0);
  return root->item;
}

template <class T>
void BinTree<T>::setRootData (T newItem)
{
  if (root)
    root->item = newItem;
  else
    root = new treeNode<T> (newItem, 0, 0);
  assert(root!=0);
}

template <class T>
bool BinTree<T>::attachLeft (T newItem)
{
  if (!isEmpty() && !root->leftChild)
    {
      root->leftChild = new treeNode<T>(newItem, 0, 0);
      assert(root->leftChild!=0);
      return true;
    }
  return false;
}

template <class T>
bool BinTree<T>::attachRight (T newItem)
{
  if (!isEmpty() && !root->rightChild)
    {
      root->rightChild = new treeNode<T>(newItem, 0, 0);
      assert(root->rightChild!=0);
      return true;
    }
  return false;
}

template <class T>
bool BinTree<T>::attachLeftSubTree (BinTree left)
{
  if (!isEmpty() && !root->leftChild)
    {
      copyTree(left.root, root->leftChild);
      return true;
    }
  return false;
}

template <class T>
bool BinTree<T>::attachRightSubTree (BinTree right)
{
  if (!isEmpty() && !root->rightChild)
    {
      copyTree(right.root, root->rightChild);
      return true;
    }
  return false;
}

template <class T>
bool BinTree<T>::detachLeftSubTree (BinTree left)
{
  if (!isEmpty())
    {
      copyTree(root->leftChild, left.root);
      destroyTree(root->leftChild);
      return true;
    }
  return false;
}

template <class T>
bool BinTree<T>::detachRightSubTree (BinTree right)
{ 
  if (!isEmpty())
    {
      copyTree(root->rightChild, right.root);
      destroyTree(root->rightChild);
      return true;
    }
  return false;
}

template <class T>
BinTree<T> BinTree<T>::leftSubTree ()
{
  treeNode<T>* subTree;

  if (isEmpty())
    return BinTree (0);
  else
    {
      copyTree(root->leftChild, subTree);
      return BinTree(subTree);
    }
}
 
template <class T>
BinTree<T> BinTree<T>::rightSubTree ()
{
  treeNode<T>* subTree;

  if (isEmpty())
    return BinTree (0);
  else
    {
      copyTree(root->rightChild, subTree);
      return BinTree(subTree);
    }
}
  
// Traversal
template <class T>
void BinTree<T>::preOrderTraverse (void (*func) (T& item), bool recur)
{
  if (!recur) preOrderNonRecursive (root, func);
  else preOrder(root, func);
}

template <class T>
void BinTree<T>::inOrderTraverse (void (*func) (T& item), bool recur)
{
  if (!recur)
    inOrderNonRecursive (root, func);
  else
    inOrder(root, func);
}

template <class T>
void BinTree<T>::postOrderTraverse (void (*func) (T& item), bool recur)
{
  if (!recur)
    postOrderNonRecursive (root, func);
  else
    postOrder(root, func);
}

template <class T>
void BinTree<T>::levelOrderTraverse (void (*func) (T& item))
{
  levelOrder(root, func);
}

// Overload
template <class T>
void BinTree<T>::operator= (const BinTree& atree)
{
  copyTree(atree.root, root);
}

// Protected
template <class T>
BinTree<T>::BinTree (treeNode<T> *node) : root(node)
{
}

template <class T>
void BinTree<T>::copyTree (treeNode<T> *tree, treeNode<T>*& newTree)
{
  if (tree)
    {
      newTree = new treeNode<T>(tree->item, 0, 0);
      assert (newTree!=0);
      copyTree(tree->leftChild, newTree->leftChild);
      copyTree(tree->rightChild, newTree->rightChild);
    }  
  else
    newTree = 0;
}

template <class T>
void BinTree<T>::destroyTree (treeNode<T>*& tree)
{
  if (tree)
    {
      destroyTree(tree->leftChild);
      destroyTree(tree->rightChild);
      delete tree;
      tree = 0;
    }
}

template <class T>
void BinTree<T>::setRootPtr (treeNode<T> *newRoot)
{
  root = newRoot;
}

template <class T>
treeNode<T>* BinTree<T>::rootPtr()
{
  return root;
}

template <class T>
treeNode<T>*& BinTree<T>::rootPtrRef()
{
  return root;
}
  
  
template <class T>
void BinTree<T>::preOrder (treeNode<T> *tree, void (*func) (T& item))
{
  if (tree)
    {
      func(tree->item);
      preOrder(tree->leftChild, func);
      preOrder(tree->rightChild, func);
    }
}

template <class T>
void BinTree<T>::inOrder (treeNode<T> *tree, void (*func) (T& item))
{
  if (tree)
    {
      inOrder(tree->leftChild, func);
      func(tree->item);
      inOrder(tree->rightChild, func);
    }
}

template <class T>
void BinTree<T>::preOrderNonRecursive (treeNode<T> *tree, void (*func) (T& item))
{
  if (!tree)
    return;

  treeNode<T>* node = root;
  stack<treeNode<T>*> nodeStack;

  if(node)
    nodeStack.push(node);
  
  while (!nodeStack.empty())
    {
      if(node)
	{
	  func(node->item);
	  node = node->leftChild;
	  if (node)
	    nodeStack.push(node);
	}
      else
	{
	  node = nodeStack.top();
	  nodeStack.pop();
	  node = node->rightChild;
	  if (node)
	    nodeStack.push(node);
	}
    }
}

template <class T>
void BinTree<T>::inOrderNonRecursive (treeNode<T> *tree, void (*func) (T& item))
{
  if (!tree)
    return;

  treeNode<T>* node = root;
  stack<treeNode<T>*> nodeStack;

  if(node)
    {
      nodeStack.push(node);
    }

  while (!nodeStack.empty())
    {
      if(node)
	{
	  node = node->leftChild;
	  if (node)
	    nodeStack.push(node);
	}
      else
	{
	  node = nodeStack.top();
	  func(node->item);
	  nodeStack.pop();
	  node = node->rightChild;
	  if (node)
	    nodeStack.push(node);
	}
    }
}

template <class T>
void BinTree<T>::postOrderNonRecursive (treeNode<T> *tree, void (*func) (T& item))
{
  if (!tree)
    return;

  treeNode<T>* node = root;
  stack<treeNode<T>*> nodeStack;
  stack<treeNode<T>*> visitedStack;

  if(node)
    {
      nodeStack.push(node);
      node = node->leftChild;
    }
  while (!nodeStack.empty())
    {
      if(node)
	{
	  nodeStack.push(node);
	  node = node->leftChild;
	}
      else
	{
	  node = nodeStack.top();
	  if (!visitedStack.empty() && visitedStack.top()==node) 
	    {
	      func(node->item);
	      nodeStack.pop();
	      visitedStack.pop();
	      node = 0;
	    }
	  else
	    {
	      visitedStack.push(node);
	      node = node->rightChild;
	    }
	}
    }
}

template <class T>
void BinTree<T>::postOrderNonRecursiveB (treeNode<T> *tree, void (*func) (T& item))
{
  if (!tree)
    return;

  treeNode<T>* node = root;
  stack<treeNode<T>*> nodeStack;
  treeNode<T>* prev = 0;

  if(node)
    nodeStack.push(node);
    
  while (!nodeStack.empty())
    {
      node = nodeStack.top();
      if (node)
	{
	  // If we are just starting from root or
	  // previous node is higher than (parent of) current node
	  if (!prev ||
	      (prev->leftChild == node) ||
	      (prev->rightChild == node))
	    {
	      if (node->leftChild)
		nodeStack.push(node->leftChild);
	      else if (node->rightChild)
		nodeStack.push(node->rightChild);
	    }
	  // If the current node is higher than prev
	  else if (node->leftChild == prev)
	    {
	      if (node->rightChild)
		nodeStack.push(node->rightChild);
	    }
	  // If prev and current node is pointing to the same node
	  else
	    {
	      func(node->item);
	      nodeStack.pop();
	    }
	  prev = node;
	}
    }
}

template <class T>
void BinTree<T>::postOrder (treeNode<T> *tree, void (*func) (T& item))
{
  if (tree)
    {
      postOrder(tree->leftChild, func);
      postOrder(tree->rightChild, func);
      func(tree->item);
    }
}

template <class T>
void BinTree<T>::levelOrder (treeNode<T> *node, void (*func)(T& item))
{
  if (!node)
    return;

  queue<treeNode<T>*> nodeQueue;

  nodeQueue.push(node);
  
  while (!nodeQueue.empty())
    {
      treeNode<T>* node = nodeQueue.front();
      nodeQueue.pop();
      if (node)
	{
	  func(node->item);
     	}
      if (node->leftChild)  nodeQueue.push(node->leftChild);
      if (node->rightChild) nodeQueue.push(node->rightChild);
    }
}

template <class T>
void BinTree<T>::printTreeLevelOrder ()
{
  if (!root)
    return;

  queue<treeNode<T>*> nodeQueue;

  nodeQueue.push(root);
  int nodesCurrentLevel = 1;
  int nodesNextLevel = 0;

  while (!nodeQueue.empty())
    {
      treeNode<T>* node = nodeQueue.front();
      nodeQueue.pop();
      if (node)
	{
       	  cout<<node->item<<" ";
	  nodesCurrentLevel--;
	}

      if (node->leftChild)  
	{
	  nodeQueue.push(node->leftChild);
	  nodesNextLevel++;
	}

      if (node->rightChild) 
	{
	  nodeQueue.push(node->rightChild);
	  nodesNextLevel++;
	}

      if (nodesCurrentLevel==0)
	{
	  nodesCurrentLevel= nodesNextLevel;
	  nodesNextLevel=0;
	  cout<<endl;
	}
    }  
}

#endif

