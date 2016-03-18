#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	int status = 0;
	if(argc == 1) {
		cerr << "No file specified. Please specify a filename" << endl;
		status = 1;
	}

	for (int i = 1; i < argc; ++i) {
		string line = "";
		string filename = argv[i], new_filename = "new" + filename;
		ifstream infile;
		ofstream myfile;
		
		infile.open(filename);
		if(infile.fail()) {
			status = 1;
			cerr << filename << "： No Such File Exist" << endl;
		}
		else{
			myfile.open (new_filename);
			while(getline(infile, line)) {
				auto index1 = line.find('(');
				auto index2 = line.find(')');
				if(index1 != string::npos)	line[index1] = '[';
				if(index2 != string::npos)	line[index2] = ']';

				myfile << line << "\n";
			}
			infile.close();
			myfile.close();
		}
	}


	return status;
}