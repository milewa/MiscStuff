#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

void printIncludes;
void printMain(stringstream, bool);

int main(int argc, char* argv[]){
	ofstream newCppFile;
	vector<string> includes;
	string filename;

	filename(argv[argc - 1]);
	newCppFile.open(filename);

	printMain(filename, true);

	for (int i = 1; i < argc; i++) {
					
	}

    return 0;
}

void printMain(ofstream& of, bool cmdArgs) {
	if(cmdArgs){
		of << "int main(int argc, char* argv[]){\n";
	}else{
		of << "int main(){\n";
	}

	of << "\nreturn 0;\n}";
}

void printIncludes(){}
