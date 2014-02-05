#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //making sure that there are two arguments passed in
    if(argc != 2)
    {
        printf("How to use: ./caesar key.\n");
        return 1;
    }
    
    //Turning the passed in key argument into a more usable string format
    char *kString = argv[1];
    
    //making sure every character of the key is of the alphabet
    for(int i = 0; i < strlen(kString); i++)
    {
        if(isalpha(kString[i]) == false)
        {
            printf("Use letters for the key.\n");
            return 1;
        }
    }
    
    //Prompt for a string to encrypt
    char *str = GetString();
        
    //Encrypting the string with the key
    for(int i = 0, n = strlen(str), k = 0; i < n; i++)
    {
        //This picks out a specific letter from the string to be encrypted
        int let = str[i];
            
        //This decides if the beginning letter was a letter to begin with, and prints accordingly
        if(isalpha(str[i]))
        {
            //This picks out a specific character from the key and adjusts its value depending on if it is upper or lower case
            int key = kString[k % strlen(kString)];
            if(isupper(key))
            {
                key = key - 65;
            }
            else
            {
                key = key - 97;
            }
            
            if(isupper(str[i]))
            {
            //This encrypts every uppercase character
                int upRe = (let + key) % 91;
                if(upRe <= 25)
                {
                    upRe = upRe + 65;
                }
                
                printf("%c", upRe);
                //where the key is advanced
                k++;
                }
            else
            {
                //This encrypts every lowercase letter
                int lowRe = (let + key) % 123;
                if(lowRe <= 25)
                {
                    lowRe = lowRe + 97;
                }
                
                printf("%c", lowRe);
                //where the key is advanced
                k++;
                        
            }
        }
        //Where the characters from the encryption string that are not from the alphabet are printed
        else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");  
    return 0;
}
