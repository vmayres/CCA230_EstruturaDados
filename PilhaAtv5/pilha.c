#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define LEN 100


void qInicio (char palavra[LEN]);
void q0( int cont, char palavra[LEN]);
void q1( int cont, char palavra[LEN]);
void q2( int cont, char palavra[LEN]);
void q3( int cont, char palavra[LEN]);
void q4( int cont, char palavra[LEN]);
void q5( int cont, char palavra[LEN]);
void q6( int cont, char palavra[LEN]);
void q7( int cont, char palavra[LEN]);
void q8( int cont, char palavra[LEN]);
void q9( int cont, char palavra[LEN]);
void qCorreto();
void qIncorreto();

void qInicio ( char palavra[LEN] ){
    int cont = 0;
    q0( cont, palavra );
}

void q0( int cont, char palavra[LEN] ){
    if ( palavra[cont] != '\0' ){
        if ( palavra[cont] == '{' ){
           q4( ++cont, palavra ); 

        }
        else if (palavra[cont] == '['){
           q2( ++cont, palavra ); 

        }
        else if (palavra[cont] == '('){
           q1( ++cont, palavra ); 

        }
        else if (palavra[cont] == '}' || palavra[cont] == ']' || palavra[cont] == ')'){
            qIncorreto();
        }
        else{
            q0( ++cont, palavra );
        }
    }
    else{
        qCorreto();
    }
}

void q1( int cont, char palavra[LEN] ){
    if ( palavra[cont] != '\0' ){
        if ( palavra[cont] == ')' ){
            q0( ++cont, palavra ); 

        }
        else if (palavra[cont] == '(' || palavra[cont] == '[' || palavra[cont] == ']' || palavra[cont] == '{' || palavra[cont] == '}'){
            qIncorreto();
        }
        else{
            q1( ++cont, palavra );
        }
    }
    else{
        qIncorreto();
    }

}

void q2( int cont, char palavra[LEN] ){
    if ( palavra[cont] != '\0' ){
        if ( palavra[cont] == ']' ) {
            q0( ++cont, palavra );
            
        }
        else if( palavra[cont] == '(' ){
            q3( ++cont, palavra );
        }
        else if (palavra[cont] == ')' || palavra[cont] == '[' || palavra[cont] == '{' || palavra[cont] == '}'){
            qIncorreto();
        }
        else{
            q2( ++cont, palavra );
        }
    }
    else{
        qIncorreto();
    }
}

void q3( int cont, char palavra[LEN] ){
    if ( palavra[cont] != '\0' ){
        if ( palavra[cont] == ')' ) {
            q2( ++cont, palavra );
            
        } 
        else if( palavra[cont] == '(' || palavra[cont] == '[' || palavra[cont] == ']' || palavra[cont] == '{' || palavra[cont] == '}'){
            qIncorreto();
        }
        
        else{
            q3( ++cont, palavra );
        }
    }
    else{
        qIncorreto();
    }
}

void q4( int cont, char palavra[LEN] ){
    if ( palavra[cont] != '\0' ){
        if( palavra[cont] == '}' ){
            q0( ++cont, palavra );
        }
        else if( palavra[cont] == '[' ){
            q6( ++cont, palavra ); 
        }
        else if( palavra[cont] == '(' ){
            q5( ++cont, palavra ); 
        }
        else if( palavra[cont] == '(' || palavra[cont] == '[' || palavra[cont] == ']' || palavra[cont] == '{' || palavra[cont] == '}'){
            qIncorreto();
        }
        else{
            q4( ++cont, palavra );
        }
    }
    else{
        qIncorreto();
    }
}

void q5( int cont, char palavra[LEN] ){
    if ( palavra[cont] != '\0' ){
        if ( palavra[cont] == ')' ) {
            q4( ++cont, palavra );
            
        }
        else if( palavra[cont] == '(' || palavra[cont] == '[' || palavra[cont] == ']' || palavra[cont] == '{' || palavra[cont] == '}'){
            qIncorreto();
        } 
        else {
            q5( ++cont, palavra );
        }
    }
    
    else{
        qIncorreto();
    }    
}

void q6( int cont, char palavra[LEN] ){
    if ( palavra[cont] != '\0' ){
        if ( palavra[cont] == ']' ) {
            q4 ( ++cont, palavra );
            
        }
        else if( palavra[cont] == '(' ){
            q7( ++cont, palavra );
        }
        else if( palavra[cont] == '(' || palavra[cont] == '[' || palavra[cont] == ']' || palavra[cont] == '{' || palavra[cont] == '}'){
            qIncorreto();
        }
        else{
            q6( ++cont, palavra );
        }
    }
    else{
        qIncorreto();
    }
}

void q7( int cont, char palavra[LEN] ){
    if ( palavra[cont] != '\0' ){
        if( palavra[cont] == ')' ){
            q6( ++cont, palavra );
        }
        else if( palavra[cont] == '(' || palavra[cont] == '[' || palavra[cont] == ']' || palavra[cont] == '{' || palavra[cont] == '}'){
            qIncorreto();
        }
        else{
            q7( ++cont, palavra );
        }
    }
    else{
        qIncorreto();
    }
}


void qIncorreto(){
    printf("incorreto\n");
}
void qCorreto(){
    printf("correto\n");
}



////////////////////////////////////////////////////////////////////////

int main(void) {
    char expr[LEN];
    fgets(expr, sizeof(expr), stdin);


    qInicio(expr);
    
	return 0;
}
