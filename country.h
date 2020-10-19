#ifndef COUNTRY_H
#define COUNTRY_H
# include<string>
# include<vector>
class country
{
private:
    std:: string name;
    std:: string code;
    static std::vector<std::string> stats_names;
    int countryStats[6];
public:
    country(std::string,std::string,int,int,int,int,int,int);
    void print_countryStats();
    int* get_countryStats();
    std:: string get_name();
    std:: string get_code();
    static std:: string& get_stats_name(int);
    ~country();
};

#endif