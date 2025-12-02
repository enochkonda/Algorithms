#include <bits/stdc++.h>
 
using namespace std;
 
int solve()
{
	int W, H, gw, gh, x1, x2, y1, y2;
	cin >> W >> H;
	cin >> x1 >> y1 >> x2 >> y2;
	//green rectangle that need to fit in
	cin >> gw >> gh;
	
	int top, bottom, left, right;
	top = H - y2;
	bottom = y1;
	right = W - x2;
	left = x1;
	
	//cout << " top " << top << " bottom " << bottom << " left " << left << " right " << right << endl;
	
	int movement1 = 0;
	int movement2 = 0;
	//cout << "top + bottom " << top + bottom << endl;
	int answer = INT_MAX;
	if(top + bottom >= gh)
	{
		 movement1 = max(gh - bottom, 0);
		 movement2 = max(gh - top, 0);
		 
		 answer = min(answer, movement1);
		 answer = min(answer, movement2);
		 //cout << "answer " << answer << endl;
	 }
	 
	 int movementW1 = 0;
	 int movementW2 = 0;
	 //cout << "left + right " << left + right << endl;
	 if(left + right >= gw)
	 {
		 movementW1 = max(gw - left, 0);
		 movementW2 = max(gw - right, 0);
		 
		 answer = min(answer, movementW1);
		 answer = min(answer, movementW2);
		 //cout << "answer " << answer << endl;
	 }
	 
	 if(answer == INT_MAX)
	 { 
	 return -1;
	 }
	 return answer;
}
 
 
 
 
 
int main()
{
	int N;
	cin >> N;
	vector<int> answer(N);
	for(int i = 0; i < N; i++)
	{
		answer[i] = solve();
	}
	
	for(int i : answer)
	{
		cout << i << "\n";
	}
}