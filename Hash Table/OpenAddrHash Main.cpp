#include "OpenAddrHash.h"

int main()
{
  HashTable ht(10);

  ht.set("key1", "data5");
  ht.set("key2", "data4");
  ht.set("key3", "data3");
  ht.set("key4", "data2");
  ht.set("key5", "data1");

  ht.get("key3");
  ht.get("key5");
  ht.get("key1");
  
  ht.set("key6", "data8");
  ht.set("key7", "data1");
  ht.set("key8", "data6");
  
  ht.get("key1");
  ht.get("key8");

  return 1;
}
