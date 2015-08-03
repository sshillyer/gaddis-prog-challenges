/*

I'm ONLY including the code for the binary search, see the text book for the rest of the class (requires the base class as well)

8. SearchableVector Modification
Modify the SearchableVector class template, presented in this chapter, so it performs a
binary search instead of a linear search. Test the template in a driver program.
*/

template <class T>
int SearchableVector<T>::findItem(T item)
{
	int 	first = 0,
			last = this->size() - 1;
			middle,
			position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;

		if (this->operator[](middle) == value)
		{
			found = true;
			position = middle;
		}
		else (if this->operator[](middle) > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;
	}
	return position;
}
#endif