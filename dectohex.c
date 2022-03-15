#include <stdio.h>

int main(){
    int dec;
    printf("Enter decimal number: ");
    scanf("%d", &dec);

    char reversedDigits[100];
    int i = 0;

    while (dec > 0)
    {
        int remain = dec % 16;
        if(remain < 10){
            reversedDigits[i] = '0' + remain;
        }else{
            reversedDigits[i] = 'A' + (remain - 10); //ASCII table, char 'A' 'B' 'C' 'D' 'E' 'F' <=> 65 66 67 68 69 70
        }
        dec = dec / 16;
        i++;
    }

    printf("Hexa number: ");
    while(i--){
        printf("%c", reversedDigits[i]);
    }
    printf("\n");

    return 0;
    
}