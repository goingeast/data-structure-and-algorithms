#include<iostream>

using std::cout;
using std::cin;

int main(){
	int num, sum = 0, tmp, count = 0;
	int max3[3] = {0, 0, 0};
	while(cin >> num){
		if(num == 0){
			break;
		}
		sum = sum + num;
                count++;
		if(max3[2] > num){
			if(max3[1] > num){
				if(max3[0] > num){
					continue;
				}else{
					max3[0] = num;
				}
			}else{
				max3[0] = max3[1];
				max3[1] = num;
			}
		}else{
			max3[0] = max3[1];
			max3[1] = max3[2];
			max3[2] = num;
		}
		
	}
	//cout << sum << count << "\n";
	if(count > 3){
     		int average  =( sum - max3[2] -max3[1] -max3[0] )/(count - 3);
		cout << average;
	}else{
		int average = 0;
		cout << average;
	}
}
