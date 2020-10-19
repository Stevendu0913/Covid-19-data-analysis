#ifndef RCORD_H
#define RCORD_H
#include <vector>
#include "country.h"

class record
{
private:
    std:: vector<country*> country_list;
    static bool compare(country*, country*);
    static int which_to_sort;
public:
    record();
    std:: vector<country*>& get_country_list();
    void print_country_list();
    void sort_record(int,int);
    void set_sort_content(int);
    void plot_first_ten();
    void add(country*);
    ~record();
};


#endif