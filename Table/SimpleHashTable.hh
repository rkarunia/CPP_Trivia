#ifndef hash_h
#define hash_h

const int MAX = 100;

template <class K, class V>
struct nodeItem
{
  K key;
  V val; 
  nodeItem* next;

  nodeItem(K k, V v):
    key(k),
    val(v),
    next(0)
  {}
  
  nodeItem():
    next(0)
  {}
};

template <class K, class V>
class SimpleHashTable
{
public:

  SimpleHashTable();
  SimpleHashTable(const SimpleHashTable&);
  virtual ~SimpleHashTable();

  virtual void insert (K key, V val);
  virtual bool remove (K key);
  virtual bool update (K key, V val);
  virtual bool retrieve (K key, V& val);
  
  virtual void traverse (void (*func)(K,V));
  int numBuckets() {return MAX;}
  void setHashFunc (int (*func)(K key, int nbuckets));

private:

  nodeItem<K,V>* items[MAX];
  int (*hashFunc)(K key, int nbuckets);
};

template <class K, class V>
SimpleHashTable<K,V>::SimpleHashTable()
{
  for (int i=0; i<MAX; ++i)
    items[i] = 0;
}

template <class K, class V>
SimpleHashTable<K,V>::SimpleHashTable(const SimpleHashTable&)
{
}

template <class K, class V>
SimpleHashTable<K,V>::~SimpleHashTable()
{
}

template <class K, class V>
void SimpleHashTable<K,V>::insert (K key, V val)
{
  int idx = hashFunc(key, MAX);
  nodeItem<K,V>* item = new nodeItem<K,V>(key, val);
  item->next = items[idx];
  items[idx] = item;
}

template <class K, class V>
bool SimpleHashTable<K,V>::remove (K key)
{ 
  int idx = hashFunc(key, MAX); 
  nodeItem<K,V>* cur  = items[idx];
  nodeItem<K,V>* prev = items[idx];

  while(cur)
    {
      if (cur->key == key)
	{
	  prev->next = cur->next;
	  delete cur;
	  cur=0;

	  return true;
	}
      else
	{
	  prev = cur;
	  cur = cur->next;
	}
    }

  return false;
}

template <class K, class V>
bool SimpleHashTable<K,V>::update (K key, V val)
{
  int idx = hashFunc(key, MAX); 
  nodeItem<K,V>* cur  = items[idx];
 
  while(cur)
    {
      if (cur->key == key)
	{
	  cur->val = val;
	  return true;
	}
      else
	{
	  cur = cur->next;
	}
    }

  return false;
}

template <class K, class V>
bool SimpleHashTable<K,V>::retrieve (K key, V& val)
{
  int idx = hashFunc(key, MAX); 
  nodeItem<K,V>* cur  = items[idx];
 
  while(cur)
    {
      if (cur->key == key)
	{
	  val = cur->val;
	  return true;
	}
      else
	{
	  cur = cur->next;
	}
    }

  return false;
}

template <class K, class V>
void SimpleHashTable<K,V>::traverse (void (*func)(K,V))
{
  for (int i=0; i<MAX; ++i)
    { 
      nodeItem<K,V>* cur  = items[i];
      while(cur)
	{
	  func(cur->key, cur->val);
	  cur = cur->next;
	}
    }
}

template <class K, class V>
void SimpleHashTable<K,V>::setHashFunc (int (*func)(K key, int nbuckets))
{
  hashFunc = func;
}

#endif
