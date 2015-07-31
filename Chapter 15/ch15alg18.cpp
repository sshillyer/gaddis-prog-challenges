/* Algorithm Workbench - Chapter 15, number 18

Write a C++ class that has an array of integers as a member variable, a pure virtual
member function
bool compare(int x, int y) = 0;
that compares its two parameters and returns a boolean value, and a member function
void sort()
that uses the comparison defined by the compare virtual function to sort the array.
The sort function will swap a pair of array elements a[k] and a[j] if
compare (a[k], a[j])
returns true. Explain how you can use this class to produce classes that sort arrays in
ascending order and descending order.
*/

class Numbers