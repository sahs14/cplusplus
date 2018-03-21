#include <iostream>     // std::cout
#include <algorithm> 
#include <vector>


int solution(std::vector<bool> &A)
{
	long count = 0;
	while (A.size() >1)
	{
		count = count + std::count(A.begin(), A.end(), true);
		for (auto index = 0; index<A.size(); ++index)
		{
			auto temp = A[index] || A[index + 1];
			A[index] = temp;
		}
		A.erase(A.begin() + A.size());
	}

	count = count + std::count(A.begin(), A.end(), true);

	if (count > 1000000000)
		return 1000000000;

	return count;
}

int main()
{
	std::vector<bool> vec{ true, false, false, true };
	std::cout << solution(vec);

}