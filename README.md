# Algorithms STL, xrange, zip

A set of stl-compatible algorithms, an xrange and zip generator have been implemented. Covered with tests.

### Algorithms

- **all_of** - returns true if all elements of the range satisfy some predicate. Otherwise false
- **any_of** - returns true if at least one of the range elements satisfies some predicate. Otherwise false
- **none_of** - returns true if all elements of the range do not satisfy some predicate. Otherwise false
- **one_of** - returns true if exactly one element of the range satisfies some predicate. Otherwise false
- **is_sorted** - returns true if all elements of the range are in sorted order relative to some criterion
- **is_partitioned** - returns true if there is an element in the range that divides all elements into those that satisfy and do not satisfy - some predicate. Otherwise false.
- **find_not** - finds the first element that is not equal to the given one
- **find_backward** - finds the first element equal to the given one from the end
- **is_palindrome** - returns true if the given sequence is a palindrome with respect to some condition. Otherwise false.

### xrange

Python has a very useful function [xrange](https://docs.python.org/2/library/functions.html#xrange). Implement its analogue in O(1) from memory. The function helps generate a value from a certain range with a certain step.
Three signatures implemented
- xrange(start, end)
-xrange(end)
- xrange(start, end, step)

For example:

```cpp
auto x = xrange(1.5, 5.5);
std::vector<int> v{x.begin(), x.end()}; // 1.5 2.5 3.5 4.5
```

```cpp
auto x = xrange(4);
std::vector<int> v{x.begin(), x.end()}; // 0 1 2 3
```

```cpp
// 1 3 5
for(auto i : xrange(1, 6, 2)) {
     std::cout << i << " ";
}
```

Without specifying a step, at each iteration an increment is generated to the previous value, with three parameters it is increased by the specified step


### zip

Python also has a standard [zip function](https://docs.python.org/2/library/functions.html#zip), also implemented - for 2 arguments in O(1) memory. The function generates pairs, where the i-th pair consists of the i-th number of the first and second sequence. If one sequence is shorter than the second, then after reaching the last element of the shorter sequence, generation ends. The function supports working with any containers that support unidirectional iterators.

Example:
```c++
std::list l = {1, 2, 3, 4, 5};
std::vector v = {'a', 'b', 'c', 'd'};
/*
1 a
2 b
3 s
4 d
*/
for(auto value : zip(l, v)) {
   std::cout << value.first << " " << value.second << std::endl;
}
```
