#include <iostream>
#include <string>
#include <iostream>

using namespace std;

string patterns[] = {"","","ABC2","DEF3","GHI4","JKL5","MNO6","PQRS7","TUV8","WXYZ9"};

string showSMS(string inputString)
{
	string resultString = "";
	int crtNumber, crtIndex;
	for(int i = 0; i < inputString.length(); ++ i )
	{
		if(inputString[i] == '#')
			continue;
      		else if(inputString[i] == '*')
        	{
            	resultString.push_back(' ');
            	continue;
        	}
        
		crtNumber = inputString[i] - '0';
		crtIndex = 0;
        	++i;
		while( i < inputString.length() && inputString[i] - '0' == crtNumber)
		{
			crtIndex ++;
			i++;
		}
		crtIndex %= patterns[crtNumber].length();
		resultString.push_back(patterns[crtNumber][crtIndex]);
		i--;
	}
	return resultString;
}

int main()
{
	cout<<showSMS("2222#222*22333444")<<endl;
}
