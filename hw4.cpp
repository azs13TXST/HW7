/*
This program is meant to take a linked list and modify it based on the functions ran. Most functions have a helper function to achieve the status of tail-recursive. The pseudocode will be above each function, explaining what they are achieving.
*/
#include <iostream>
#include "recursive.h"
#include "hw4.h"

using namespace std;

/*
SumHelper function
  Returns acc if the list is empty
  Returns the sum of the list values
*/
static int SumHelper(list_t list, int acc)  {
  if (list_isEmpty(list))  {
    return acc;
  }
  return SumHelper(list_rest(list), list_first(list) + acc);
}

/*
sum function
  Returns the SumHelper function
*/
int sum(list_t list)  {
  if (list_isEmpty(list))  {
    return 0;
  }
  return SumHelper(list, 0);
}

/*
ProductHelper function
  Returns acc=(1) if the list is empty
  Returns the product of the list values
*/
static int ProductHelper(list_t list, int acc)  {
  if (list_isEmpty(list))
    return acc;

  return ProductHelper(list_rest(list), list_first(list)* acc);
}

/*
product function
  Returns the ProductHelper function
*/
int product(list_t list)  {
  if (list_isEmpty(list))  {
    return 0;
  }
  return ProductHelper(list, 1);
}

/*
accumulate function
  If the list is empty
    Returns base
  Else
    Returns accumulate function
*/
int accumulate(list_t l, int (*fn)(int, int), int base)
{
    if (list_isEmpty(l)) {
        return base;
    }
    else {
        return accumulate(list_rest(l), fn, fn(base, list_first(l)));
    }
}

/*
reverse_help function
  If the list is empty
    Returns reverse
  Else
    Returns reverse_help function
*/
static list_t
reverse_help(list_t forward, list_t reverse)
{
  if (list_isEmpty(forward))  {
    return reverse;
  } 
  else  {
    return reverse_help(list_rest(forward),
			list_make(list_first(forward), reverse));
  }
}

/*
reverse function
  Returns reverse_help function
*/
list_t reverse(list_t l)
{
  return reverse_help(l, list_make());
}

/*
AppendHelper function
  If the first element is empty, returns the second
  If the second element is empty, returns the first
  If the entire list is empty, creates a new list
    Returns the new list
  Creates a new list wih the new element
    Returns the new list
*/
static list_t AppendHelper(list_t first, list_t second, list_t new_list)  {
  if (list_isEmpty(first))  {
    return second;
  }
  if (list_isEmpty(second))  {
    return first;
  }
  if(list_isEmpty(new_list))  {
    new_list = list_make(list_first(first), new_list);
    return AppendHelper(list_rest(first), second, new_list);
  }
  else  {
    new_list = list_make(list_first(second), new_list);
    return AppendHelper(first, list_rest(second), new_list);
  }
}

/*
append function
  Returns the AppendHelper function with the new list
*/
list_t append(list_t first, list_t second)  {
  return AppendHelper(first, second, list_make());
}

/*
FilterOddHelper function
  Checks if the list if empty
    Returns new list if so
  Checks if the values in the list are divisible by 2
    Returns the ones that are
  Return the function with the new list
*/
static list_t FilterOddHelper(list_t list, list_t new_list) {
  if(list_isEmpty(list))  {
    return new_list;
  }
  if (list_first(list) % 2 == 1)  {
    new_list = list_make(list_first(list), new_list);
    return FilterOddHelper(list_rest(list), list_rest(new_list));
  }
  else
    return FilterOddHelper(list_rest(list), new_list);
}

/*
  filter_odd function
    Makes a new list
    Returns the FilterOddHelper function with the new list
*/
list_t filter_odd(list_t list)  {
  list_t new_list = list_make();
  return FilterOddHelper(list_rest(list), new_list);
}

/*
FilterEvenHelper function
  Checks if the list if empty
    Returns new list if so
  Checks if the values in the list are divisible by 2
    Returns the ones that are not
  Return the function with the new list
*/
static list_t FilterEvenHelper(list_t list, list_t new_list)  {
  if(list_isEmpty(list))  {
    return new_list;
  }
  if (list_first(list) % 2 != 1)  {
    new_list = list_make(list_first(list), new_list);
    return FilterEvenHelper(list_rest(list), list_rest(new_list));
  }
  else
    return FilterEvenHelper(list_rest(list), new_list);
}

/*
filter_even function
  Makes a new list
  Returns the FilterEvenHelper function with the new list
*/
list_t filter_even(list_t list)  {
  list_t new_list = list_make();
  return FilterEvenHelper(list_rest(list), new_list);
}

/*
FilterHelper function
  Checks if the list is empty
    Returns the new list
  Returns the new list without the target elements
*/
static list_t FilterHelper(list_t list, bool (*fn))  {
  if (list_isEmpty(list))
    return list;
  return FilterHelper(list, fn);
}

/*
filter function
  Returns the FilterHelper function with the new list
*/
list_t filter(list_t list, bool (*fn))  {
  return FilterHelper(list, fn);
}

/*
rotateHelper function
  Sets saved_list to list_make
  If list is empty
    Returns saved_list
  Else
    Returns RotateHelper
*/
static list_t RotateHelper(list_t input_list, list_t saved_list){

    saved_list = list_make(list_first(input_list), saved_list);

    if (list_isEmpty(list_rest(input_list))) {
        return saved_list;
    }
    else {
        return RotateHelper(list_rest(input_list), saved_list);
    }

}

/*
rotate function
  If n is greater than 0
    Initializes temp_list to list_make
    Initializes temp_list by calling RotateHelper function
    Returns rotate function
  Else
    Returns input_list
*/
list_t rotate(list_t input_list, unsigned int n) {
  if (n > 0) {
    list_t temp_list = list_make();
    temp_list = list_make(list_first(input_list), temp_list);
    temp_list = RotateHelper(reverse(list_rest(input_list)), temp_list);
    return rotate(temp_list, (n - 1));
  }
  else {
      return input_list;
  }
}

/*
InsertListHelper function
  Checks if count and n are the same
    Creates a new list using the reverse function if so
    Returns the new list
  If not, sets second and goes from there
  Returns the function with the new list
*/
static list_t InsertListHelper(list_t first, list_t second, unsigned int n, list_t new_list, int count)  {
  if (count == n)  {
    new_list = append(reverse(first), second);
    return new_list;
  }
  else  {
    second = list_make(list_first(first), second);
    return InsertListHelper(list_rest(first), second, n, new_list, count + 1);
  }
}

/*
insert_list function
  Returns the InsertListHelper function with the new list
*/
list_t insert_list(list_t first, list_t second, unsigned int n)  {
  return InsertListHelper(reverse(first), second, n, list_make(), 0);
}

/*
chop function
  If n is greater than 0
    If the list is not empty
      Initializes input_list to reverse function
      Initializes input_list to list_rest function
      Initializes input_list to reverse function
      Returns the chop function
    Returns input_list
*/
list_t chop(list_t input_list, unsigned int n){
  if (n > 0) {
    if (!list_isEmpty(input_list)) {
      input_list = reverse(input_list);
      input_list = list_rest(input_list);
      input_list = reverse(input_list);
      return chop(input_list, (n - 1));
    }
  }
    return input_list;
}

/*
fib function
  If n is less than or equal to 1
    Returns n
  Returns the function twice with different parameters
*/
int fib(int n)  {
  if (n <= 1)  {
    return n;
  }

  return fib(n-1) + fib(n-2);
}

/*
fib_tailHelper function
  If n == 0
    Returns var1
  If n == 1
    Returns var2
  Returns fib_tailHelper function
*/
static int fib_tailHelper(int n, int var1 = 0, int var2 = 1)  {
  if(n == 0){
    return var1;
  }
  if(n == 1){
    return var2;
  }
  return fib_tailHelper(n-1, var2, (var1+var2));
}

/*
fib_tail function
  Initializes var1 to 0
  Initializesvar2 to 1
  Returns fib_tail
*/
int fib_tail(int n)  {
  int var1 = 0;
  int var2 = 1;
  
  return fib_tailHelper(n, var1, var2);
}