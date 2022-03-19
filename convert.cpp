#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void convert(string &str){
    int len = str.length();
    //convert according to ASCII tables
    for(int i = 0; i < len; i++){
        if(str[i]>= 'a' && str[i] <='z'){
            str[i]=str[i]-32; //convert lowercase to uppercase
        }
        else if (str[i]>='A'&& str[i]<='Z')
        {
            str[i]=str[i]+32; //convert uppercase to lowercase
        }

    }
}
int main(){
    string str = "nguyen tu";
    //call function
    convert(str);

    cout << str;
    return 0;
}