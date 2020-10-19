#include "country.h"
#include <iostream>
using namespace std;


// each country will have their own country object and a vector inside a object to contains all the data information


// the following vector is to store the title of the data with same order as the data vector of each country
vector<string> country:: stats_names = {"New Confirmed Cases","New Deaths","New Recovered Cases","Total Confirmed Cases","Total Deaths","Total Recovered Cases"};

country:: country(string newName,string newCode, int confirmCase, int deaths, int recoveredCase, int totalCase, int totalDeath, int totalRecovered)
    {
        name.assign(newName);
        code.assign(newCode);
        countryStats[0]=confirmCase;
        countryStats[1] = deaths;
	    countryStats[2] = recoveredCase;
	    countryStats[3] = totalCase;
	    countryStats[4] = totalDeath;
	    countryStats[5] = totalRecovered;
    }

string country:: get_name(){
    return name;
}

string country:: get_code(){
    return code;
}

void country:: print_countryStats(){
    for (int i =0; i<6;i++){
        cout<< countryStats[i]<<" ";
    }
    cout<<endl;
}

/*
return the whole vector that contains one country's information
*/
int* country:: get_countryStats(){
    return countryStats;
}

string& country:: get_stats_name(int index){
    return stats_names[index];
}

country::~country(){};
