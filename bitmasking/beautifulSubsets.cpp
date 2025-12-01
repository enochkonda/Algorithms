#include <bits/stdc++.h>

using namespace std;

vector<int> nums = {10,4,5,7,2,1};
int k = 3;

int main()
{
	 int ans = 0;
	//start at 1 because we only wan beautiful subsets
	for(int mask = 1; mask < (1 << (int)nums.size()); mask++)
	{
		vector<int> subset;
		//check if bits are on
		for(int i = 0; i < (int)nums.size(); i++)
		{
			if((1 << i) & mask)
			{
				subset.push_back(nums[i]);
			}
		}
		sort(subset.begin(), subset.end());
		
		int p = 1;
		int q = 0;
		bool noBad = true;
		while(q <= (int)subset.size() - 1)
		{
			int diff = subset[p] - subset[q];
			cout << diff << " = " << subset[p] << " - " << subset[q] << "\n"; 
			if(diff > k || p == (int)subset.size() - 1)
			{
				q++;
			}
			else
			{
				p++;
			}
			if(diff == k)
			{
				noBad = false;
				break;
			}
		}
		if(noBad)
		{
			ans++;
			cout << "[";
			for(int help = 0; help < (int)subset.size(); help++)
			{
				cout << subset[help] << ",";
			}
			cout << "]\n";
		}
	}
	cout << ans << "\n";
}
