#include<iostream>
using std::cout;
using std::cin;

float sqrt( float x){
	float x1 = x, x2 =0;
	x2 = 0.5 *(x1 + x/x1);
	while((x1 - x2) != 0){
		x1 = x2;
		x2 = 0.5 * (x1 + x/x1);
	}
	return x2;
}

int main(){
	float x;
	cin >>x;
	cout << sqrt(x);

}
