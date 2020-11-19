//	Elliott Long
//  proj4_caesar
//	A Caesar Cypher generator
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>		//this and unistd used for checking permissions

int main(int argc, char * argv[]) {
    int testVal;
    testVal = access(argv[2], R_OK);
    if ( argc != 3 ){					//checks if right number of
        //arguments passed
        printf("Incorrect number of arguments\n");
        printf("Closing program\n");
    }
    else if(errno == EACCES){			//if no permissions
        printf("File cannot be read\n");
        printf("Ending program\n");
    }
    else{
        testVal = 0;					//done to remove warning from gcc
        int ch = 0;
        char *hold = argv[2];				//holds shift value
        int shift = atoi(hold);				//atoi used for casting
        FILE *init = fopen( argv[1] , "rb" );
        if ( init == 0 ){		//file can't be opened
            printf("File cannot be opened\n");
            printf("Please restart program with correct\n");
            printf("file name passed\n");
        }
        else{
            shift = shift % 26;				//creates shift value
            while ((ch = fgetc(init)) != EOF){
                if (ch > 64 && ch < 91){
                    if ((ch + shift) > 90){
                        shift = shift - 26;	//if shift is too much
                    }
                    ch = ch + shift;
                }
                else if (ch > 96 && ch < 123){
                    if ((ch + shift) > 122){
                        shift = shift - 26;
                    }
                    ch = ch + shift;		//if shift is too much
                }
                else{}
                printf("%c",ch);
            }
            fclose(init);
        }
    }
    return 0;
}
