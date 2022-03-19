#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void convert(string &str){
    int len = str.length();

    for(int i = 0; i < len; i++){
        if(str[i]>= 'a' && str[i] <='z'){
            str[i]=str[i]-32;
        }
        else if (str[i]>='A'&& str[i]<='Z')
        {
            str[i]=str[i]+32;
        }

    }
}
int main(){
    string str = "nguyen tu";
    convert(str);

    cout << str;
    return 0;
}