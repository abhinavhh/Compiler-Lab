#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int state = 0;

//* check each symbol and move to the next state(states will be different for a and b)
void q0(char ch){
    if(ch=='a'){
        state = 0;
    }
    else
        state = 1;
}
void q1(char ch){
    if(ch=='a'){
        state = 2;
    }
    else
        state = 1;
}
void q2(char ch){
    if(ch=='a'){
        state = 0;
    }
    else
        state = 3;
}
void q3(char ch){
    if(ch=='a'){
        state = 3;
    }
    else
        state = 3;
}
int isAccept(char s[]){
    int i;
    int len = strlen(s);

    //* check the state when reading each symbol
    for(i=0 ; i<len ; i++){
        if(state == 0){
            q0(s[i]);
        }
        else if(state == 1){
            q1(s[i]);
        }
        else if(state == 2){
            q2(s[i]);
        }
        else if(state ==3){
            q3(s[i]);
        }
    }
    // If state = 3 we reach last state so accept the input
    if(state==3){
        return 1;
    }
    else
        return 0;
}
void main(){
    int i, n=0;
    char a[100];
    do{
        //todo : read an input string from user either a or b
        printf("Enter the input string : ");
        scanf("%s",a);
        int len = strlen(a);

        //?check wheather the input string contain symbols other than a and b
        for( i=0 ; i<len ; i++ ){
            if( a[i]!='a' && a[i]!='b'){
                printf("\nInvalid input.");
                exit(0);
            }
        }

        //* if input is valid call isAccept()
        if(isAccept(a)){
                printf("\nAccepted.");
        }
        else
            printf("\nNot Accepted.");
    }while(n==1);
}
