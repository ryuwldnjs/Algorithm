#include <iostream>
using namespace std;
struct Point{
	long long x, y;
};

//점 a,b,c순으로 회전방향 판단 
int CCW(Point a, Point b, Point c){
	//행렬식으로 판단 (신발끈공식)
	// 계산 도중 오버플로우가 발생할 수 있으므로 long long으로 선언 
	long long op = a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x + b.y*c.x + c.y*a.x);
	if(op > 0) return 1;
	else if(op == 0) return 0;
	return -1;
}

Point P1,P2,P3;

int main(){
	long long x,y;
	cin>>x>>y; P1 = {x,y};
	cin>>x>>y; P2 = {x,y};
	cin>>x>>y; P3 = {x,y};

	cout<<CCW(P1,P2,P3);	
	return 0;
}