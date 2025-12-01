#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> vectOne(N);
	int length, height;
	int area = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> vectOne[i].first >> vectOne[i].second;
	}
	for(int i = 0; i < N; i++)
	{
		for(int j  = 0; j < N; j++)
		{
			for(int p = 0; p < N; p++)
			{
				if(vectOne[i].second == vectOne[j].second)
				{
					if(vectOne[j].first == vectOne[p].first)
					{
						length = abs(vectOne[p].first - vectOne[i].first);
						height = abs(vectOne[p].second - vectOne[i].second);
						area = max(area, length * height);
					}
				}
			}
		}
	}
	cout << area;
}
