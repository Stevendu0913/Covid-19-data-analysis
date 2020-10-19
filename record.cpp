#include <iostream>
#include "record.h"
#include <algorithm>
using namespace std;
int record:: which_to_sort;

// record object has a vector that will contain all the country object


/*
constructor
*/
record:: record(){ 
    which_to_sort=0;
}

/*
compare method to help compare and sorting an object vector by with specific data of a country
*/
bool record:: compare(country* a , country*b){
    return(a->get_countryStats()[which_to_sort]<b->get_countryStats()[which_to_sort]);
}

/*
return the whole vector which contains all country objects
*/
vector<country*>& record::get_country_list(){
    return country_list;
}

/*
print each country's data
*/
void record:: print_country_list(){
    for(vector<country*>:: iterator i = country_list.begin();i != country_list.end();i++) {
        (*i)->print_countryStats();
    }
}

/*
sort the whole vector which contains all the country object by the order and specific data that user chose
*/
void record:: sort_record(int sort_content, int order){
    which_to_sort=sort_content;
    
    sort(country_list.begin(),country_list.end(),compare);// by ascending order
    if(order ==2){//by descending order
        reverse(country_list.begin(),country_list.end());
    }
}

void record:: set_sort_content(int index){
    which_to_sort = index;
}

void record:: plot_first_ten(){
    int symbols = 70; // reference
	int each = 1;
	int first = country_list[0]->get_countryStats()[which_to_sort]; 
	int last = country_list[9]->get_countryStats()[which_to_sort];
	if(first > last){  // if first > last means the whole vector is in descending order
		if(first > symbols){        // if the data is larger than 70, use the default setting for each bar
			each = first/symbols; 
		}
	}
	else{
		if(last > symbols){ // same as above
			each = last/symbols;
		}
	}

	for(int i = 0; i < 10; i ++){
		cout << country_list[i]->get_code() << " | ";
		int num = country_list[i]->get_countryStats()[which_to_sort]/each;
		cout << string(num,'#')<<endl;
		cout << "  |"<<endl;
	}
	cout << string(symbols+5,'-')<<endl;
	cout << country::get_stats_name(which_to_sort) << "; Each # is approx. " << each << " cases" << endl;
}

/*
add country object to the vector
*/
void record:: add(country* new_country){
    country_list.push_back(new_country);
}

record::~record(){
	for (vector<country*>::iterator i = country_list.begin(); i != country_list.end(); i++)
    	delete *i;
}