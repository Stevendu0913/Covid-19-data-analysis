#ifndef SUPPORT_H
#define SUPPORT_H
#include <fstream>
#include "country.h"
#include "record.h"

record* build_records(std::ifstream& fp);
void sort_plot(record*);
#endif
