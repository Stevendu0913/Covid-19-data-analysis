#include <iostream>
#include <string>
#include <sstream>
#include "support.h"
using namespace std;

/*
parse_line method is to help to seperate each information and insert each of them to a vector
*/
void parse_line(vector<string>& tokens,string& record_line){ 
	stringstream stream_line(record_line); 
	string token;
	char c;
	stream_line.get(c);                   // in order to skip the first ' " ' at the begining of the each information
	stream_line.get(c);                  // get the first char of the information
	while(c != '"'){                      //this while loop is only for getting country name
		token.append(1u,c);                //add the every char of country name into vector 
		stream_line.get(c);
	}
	stream_line.get(c);               // get ',' after the country name
	tokens.push_back(token);		// push contry name into vector
	while(getline(stream_line,token,',')){  //seperate each rest information by ','
		if(token.front() == '"')
			token = token.substr(1, token.size() - 2); // remove ' '' ' from the begining and the ending of the information
		tokens.push_back(token);   //add information into vector
	}
}

/*
the following method is to get the information of each country and create 'country' object for each country
*/

record* build_records(ifstream& fp){
	record* myrecords = new record();  // create a record object to store country object
	string record_line;
	while(getline(fp,record_line)){
		vector<string> tokens; // this vector is used to store each information of a country
		parse_line(tokens,record_line);
        string name = tokens[0];
        string code = tokens[1];
        int new_c = stoi(tokens[3],nullptr);
		int new_d = stoi(tokens[4],nullptr);
		int new_r = stoi(tokens[5],nullptr);
		int tot_c = stoi(tokens[8],nullptr);
		int tot_d = stoi(tokens[9],nullptr);
		int tot_r = stoi(tokens[10],nullptr);
		myrecords->add(new country(name,code,new_c,new_d,new_r,tot_c,tot_d,tot_r)); 
	}
	//myrecords->print();
	return myrecords;
}

/*
the following method is to create a simple communication with user. let them to select the information to plot, and in which order
*/

void sort_plot(record* myrecords){
	int field_to_comp;
	int order;
	cout << "Please select a field to sort the data"<< endl;
	cout << "\t0 for new confirmed cases,"<< endl;
	cout << "\t1 for new deaths,"<< endl;
	cout << "\t2 for new recovered cases,"<< endl;
	cout << "\t3 for total confirmed cases,"<< endl;
	cout << "\t4 for total deaths,"<< endl;
	cout << "\t5 for total recovered cases:"<< endl;
	cin >> field_to_comp;
	if(field_to_comp < 0 || field_to_comp > 5){
		cout << field_to_comp << " is not a valid choice."<<endl;
		exit(1);
	}

	cout << "Please select the order of sorting"<< endl;
	cout << "\t1 for ascending,\n\t2 for descending:"<< endl;
	cin >> order;
	if(!(order == 1 || order ==2)){
		cout << order << " is not a valid choice."<<endl;
		exit(1);
	}

	myrecords->sort_record(field_to_comp,order); // sort the vector which cotains all country objects by the order of a specific data that uesr chose
	//myrecords->print();
	myrecords->plot_first_ten();
}
