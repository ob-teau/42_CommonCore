#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	std::vector<int> vect;

	vect.push_back(42);
	vect.push_back(43);

	std::vector<int>::iterator it;

	for (it = vect.begin(); it != vect.end(); it++)
		if (*it == 43)
			break;


	std::cout << *it << std::endl;

	return 0;
}
