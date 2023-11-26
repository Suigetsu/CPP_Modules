#include "PmergeMe.hpp"

std::vector<std::vector<int> > sorted(std::vector<std::vector<int> > &vec1, std::vector<std::vector<int> > &vec2)
{
	std::vector<std::vector<int> > result;
	std::vector<std::vector<int> >::iterator it;

	for (size_t i = 0; i < vec2.size(); i++)
	{
		it = std::lower_bound(vec1[0].back(), vec1[vec1.size()].back(), vec2[i].back());
	}
	
	return (result);
}

int main()
{
	size_t i = 0;
	std::vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(4);
	vec1.push_back(6);
	std::vector<int> vec2;
	vec2.push_back(0);
	vec2.push_back(5);
	vec2.push_back(9);
	vec2.push_back(3);
	std::vector<int> vec3;
	vec3.push_back(0);
	vec3.push_back(5);
	vec3.push_back(9);
	vec3.push_back(7);
	std::vector<std::vector<int> > bigVec;
	bigVec.push_back(vec1);
	bigVec.push_back(vec2);
	std::vector<std::vector<int> > bigVec2;
	bigVec2.push_back(vec3);

	std::vector<std::vector<int> > result = sorted(bigVec, bigVec2);
	while (i < result.size())
	{
		int j = 0;
		while (result[i][j])
			std::cout << result[i][j++] << " ";
		std::cout << std::endl;
		i++;
	}
}