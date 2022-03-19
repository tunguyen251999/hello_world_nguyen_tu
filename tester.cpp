#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

enum months{
    Jan ,Feb ,Mar ,Apr ,May ,Jun ,Jul ,Aug ,Sep ,Oct ,Nov ,Dec, Not_Month}month;

static char* month_out[] = {(char*)"Jan", (char*)"Feb", (char*)"Mar", (char*)"Apr", (char*)"May", (char*)"Jun", (char*)"Jul", (char*)"Aug", (char*)"Sep", (char*)"Oct", (char*)"Nov", (char*)"Dec", (char*)"Not_Month"};

static int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
enum  months translate(char*);
void check(int, enum months);
void tomorrow(int, enum months);

int main(){
    int day;
    char mon[4];
    cout<<"Enter a date (number 3 letter lower case e.g. 31 Jan): \n";
    cin >>day>>mon;

    month = translate(mon);
    check(day, month);
    tomorrow(day, month);
    
    return 0;
}

enum months translate(char *m){
    if(strcmp(m, "Jan")==0) //compare m and "Jan" => Value = 0 then m is equal to "Jan" 
        return Jan;
    else if(strcmp(m, "Feb")==0)
        return Feb;
    else if(strcmp(m, "Mar")==0)
        return Mar;
    else if(strcmp(m, "Apr")==0)
        return Apr;
    else if(strcmp(m, "May")==0)
        return May;
    else if(strcmp(m, "Jun")==0)
        return Jun;
    else if(strcmp(m, "Jul")==0)
        return Jul;
    else if(strcmp(m, "Aug")==0)
        return Aug;
    else if(strcmp(m, "Sep")==0)
        return Sep;
    else if(strcmp(m, "Oct")==0)
        return Oct;
    else if(strcmp(m, "Nov")==0)
        return Nov;
    else if(strcmp(m, "Dec")==0)
        return Dec;
    else
        return Not_Month;
}

void check(int day, enum months month_in){
    //check that input is valid
    if((month_in == Not_Month)||(day < 1)||(day > days_in_month[month])){
        cout << "Error: Invalid Input "<< day <<" "<< month_out[month_in] <<"\n";
        exit(-1);
    }
}
void tomorrow(int day, enum months month_in){
    if(day < days_in_month[month_in])
        cout <<"Tomorrow is "<< day+1<<" "<< month_out[month_in]<<"\n";
    else
        cout <<"Tomorrow is 1 "<< month_out[month_in+1]<<"\n";
}