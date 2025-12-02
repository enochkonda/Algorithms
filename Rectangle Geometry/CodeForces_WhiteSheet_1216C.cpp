#include <bits/stdc++.h>
using namespace std;
 
 
using ll = long long;
 
struct Rectangle {
	int x1 , y1; // lower-left
	int x2 , y2; // upper-right
 
	Rectangle(){}
	Rectangle(int _x1 , int _y1 , int _x2 , int _y2) {
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}
 
	ll area() {
		if(isValid()) {
			//      long long * int = long long
			return (ll)(x2 - x1) * (y2 - y1);
		}
 
		return 0;
	}
 
	bool isValid() {
		return (x2 > x1) && (y2 > y1);
	}
};
 
Rectangle intersection(Rectangle r1 , Rectangle r2) {
	return Rectangle(max(r1.x1 , r2.x1) , max(r1.y1 , r2.y1), // lower-left
					 min(r1.x2 , r2.x2) , min(r1.y2 , r2.y2));// upper-right
}
 
Rectangle getRectangle() {
	Rectangle r;
	cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
	return r;
}
 
int main() {
	Rectangle A = getRectangle();
 
	Rectangle B = getRectangle();
	Rectangle C = getRectangle();
 
	B = intersection(A , B);
	C = intersection(A , C);
 
	ll BCarea = B.area() + C.area() - intersection(C , B).area();
 
	ll finalArea = A.area() - BCarea;
 
	if(finalArea > 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
 
	return 0;
}