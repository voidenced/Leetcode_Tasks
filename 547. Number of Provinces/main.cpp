#include <algorithm>
#include <iostream>
#include <vector>

void DFSVisit(std::vector<std::vector<int>>& InNodeConnections, std::vector<bool>& InVisited, int InNode)
{
	InVisited[InNode] = true;
	for (int Index = 0; Index < InNodeConnections[InNode].size(); ++Index)
	{
		if (!InVisited[Index] && InNodeConnections[InNode][Index] == 1)
		{
			DFSVisit(InNodeConnections, InVisited, Index);
		}
	}
}

class Solution
{
public:
	int findCircleNum(std::vector<std::vector<int>>& InNodeConnections)
	{
		std::vector<bool> Visited(InNodeConnections.size(), false);
		int ProvinceCount = 0;
		for (int Index = 0; Index < Visited.size(); ++Index)
		{
			if (!Visited[Index])
			{
				++ProvinceCount;
				DFSVisit(InNodeConnections, Visited, Index);
			}
		}
		return ProvinceCount;
	}
};

int main()
{
	Solution _Solution;
	std::vector<std::vector<int>> TestCase = { { 1, 0, 0, 1 },{ 0, 1, 1, 0 },{ 0, 1, 1, 1 },{ 1, 0, 1, 1 } };
	int ProvinceCount = _Solution.findCircleNum(TestCase);
	std::cout << "\nProvince count: " << ProvinceCount << "\n";
}
