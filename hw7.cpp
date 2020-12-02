/*
PSEUDOCODE:
My HW4 does not work and this will not work either, but here goes nothing.
hash_test1 function
  Sets hash_output to fib(set)
  Sets old_hash_output to hash_output
  Sets new_hash_output to sum(old_hash_output)
  Returns new_hash_output

hash_test2 function
  Sets hash_output to filter_odd(set2)
  Sets odd_fn to product(hash_output)
  Sets even_fn to sum(odd_fn)
  Returns even_fn

CollisionCounter function
  

main function
  Declares set 1
  Declares set 2
  Sets n to the size of the set
  Initializes int count to 0
  Calls the hash_test function
  Calls the hash_test2 function
  Calls the CollisionCounter function
*/
#include <iostream>
#include <hw4.h>
#include <unordered_set>

int hast_test1(int n, unordered_set<int> set)  {
  hash_output = fib(set);
  old_hash_output = hash_output;
  new_hash_output = sum(old_hash_output);
  return new_hash_output;
}

int hash_test2(int n, unordered_set<int> set2)  {
  hash_output = filter_odd(set2);
  odd_fn = product(hash_output);

  even_fn = sum(odd_fn);
  return even_fn; 
}

int CollisionCounter()  {
  
}

int main()  {
  std::unordered_set<int> set = {1, 2, 3, 4, 5};
  std::unordered_set<int> set2 = {1, 2, 3, 4, 5, 6};

  int n = set.size();
  int count = 0;
  hash_test(n, set);
  hash_test2(n, set2);

  CollisionCounter(count, set);

  return 0;
}