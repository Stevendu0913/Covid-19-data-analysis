#include <iostream>
#include "support.h"
using namespace std;

int main(int argc, char const *argv[]){
	string filename;
	ifstream fp;
	cout << "Please enter the name of the data csv file: "<< endl;
	getline(cin,filename); //open the input file
	fp.open(filename);
	if(fp.fail()){
		cout<< "Can not open file: " << filename << endl;
		exit(1);
	}

	string dataline;
	getline(fp,dataline);// remove the first line in summary (discription title of the each data)
	//cout << dataline << endl;
	record* myrecords = build_records(fp);
	fp.close();

	sort_plot(myrecords); //sort the vector which contains all country objects
	delete myrecords;
	return 0;
}