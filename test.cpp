#include "record.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]){
	country* a = new country("china","a",10000,20000,30000,40000,50000,60000);
	//a->print_countryStats();
	
	country* b = new country("us","b",20000,20000,30000,4000,50000,60000);
	country* c = new country("c","c",30000,20000,30000,40000,9999,69000);
	country* d = new country("china","d",10000,26666,3666,4666,566,66666);
	country* e = new country("china","e",155500,2555,3555,4555,5555,65555);
	country* f = new country("china","f",15555,2666,344,4444,5333,55555);
	country* g = new country("china","g",17777,27777,3777,4777,5777,9999);
	country* h = new country("china","h",17777,2777,3777,7774,5777,6777);
	country* i = new country("china","i",14444,42666,3777,4777,57777,67777);
	country* j = new country("china","j",17773,2666,3555,4666,4445,655555);
	record* hello = new record();
	hello->add(a);
	hello->add(b);
	hello->add(c);
	hello->add(d);
	hello->add(e);
	hello->add(f);
	hello->add(g);
	hello->add(h);
	hello->add(i);
	hello->add(j);
	hello->print_country_list();
	hello->sort_record(0,2);
	hello->plot_first_ten();


}