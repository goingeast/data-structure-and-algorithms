#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::cin;

bool isSpecial(char c){
	if( c == 'A' || c == 'a' || c == 'E'||c == 'e' || c == 'I' || c == 'i'||
		 c == 'O' || c == 'o' || c == 'U'||c == 'u'){
		return true;
	}else
		return false;
}

int main(){

	string str, str1;
	int count = 0;
	cin >> str;
	for(string::iterator it = str.begin(); it != str.end(); ++it){
		count++;
		str1.push_back(*it);
		if(count > 3 && isSpecial(*it)){
			//str1.push_back(*it);
			str1.push_back('^');
		}
	}
	cout << str1;
}
