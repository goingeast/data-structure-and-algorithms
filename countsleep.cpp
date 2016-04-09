#include <iostream>
#include <fstream>

using namespace std;

int main(){


	ifstream input("example.txt");
	ofstream output("output.txt");

	if (myfile.is_open())
	{
		int numTest;
		input >> numTest;
		for(int i = 1; i <= numTest; ++i){
			int argv;
			input >> argv;
			output << "Case #" << i <<": " << countSheep(argv);
		}
		output.close();
		input.close();
	}
}
