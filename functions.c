#include<stdio.h>
#include<string.h>
#include <stdlib.h>

char* home(char *query)
{
    char *res = "hello world";
    char *welcome = malloc(12); 
    strcpy(welcome, res);
    return welcome;
}

char* toArray(int number)
{
    int n = 0;
    int d = number;
    while(d)
    {
        n++;
        d/=10;
    }
    int i;
    char *numberArray = calloc(n, sizeof(char));
    for (i = n-1; i >= 0; --i, number /= 10)
    {
        numberArray[i] = (number % 10) + '0';
    }
    return numberArray;
}

char* square(char *query)
{
    if(query==NULL || strlen(query)<=4)
    {
        char *res = "1";
        char *welcome = malloc(2); 
        strcpy(welcome, res);
        return welcome;
    }
    char *res = query+4;
    int y = atoi(res);
    y=y*y;
    return toArray(y);
    
}

char* cube(char *query)
{
    //printf("%s",query);
    if(query==NULL || strlen(query)<=4)
    {
        char *res = "1";
        char *welcome = malloc(2); 
        strcpy(welcome, res);
        return welcome;
    }
    char *res = query+4;
    int y = atoi(res);
    y=y*y*y;
    return toArray(y);
}


char* hello(char *query)
{
    if(query==NULL || strlen(query)<=4)
    {
        char *res = "Hello";
        char *welcome = malloc(6); 
        strcpy(welcome, res);
        return welcome;
    }
    char *res = query+4;
    char *temp = "Hello, ";
    char* welcome;
    welcome = malloc(strlen(res)+8); 
    strcpy(welcome, temp); 
    strcat(welcome, res); 
    return welcome;
}

char* pingpong(char *query)
{
    if(query==NULL || strlen(query)<=4)
    {
        char *res = "pingpong";
        char *welcome = malloc(9); 
        strcpy(welcome, res);
        return welcome;
    }
    char* res = query+4;
    char *welcome = malloc(9); 
    strcpy(welcome, res);
    return welcome;
}

char* prime(char *query )
{
    if(query==NULL || strlen(query)<=4)
    {
        char *res = "False";
        char *welcome = malloc(6); 
        strcpy(welcome, res);
        return welcome;
    }
    
    char *res = query+4;
    int n = atoi(res);
    int flag = 0;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            flag = 1;
            break;
        }
    }
    
    if(flag==0)
    {
        char *res = "True";
        char *welcome = malloc(6); 
        strcpy(welcome, res);
        return welcome;
    }
    else
    {
        char *res = "False";
        char *welcome = malloc(6); 
        strcpy(welcome, res);
        return welcome;
    }
}

char* fibonacci(char *query)
{
    if(query==NULL || strlen(query)<=4)
    {
        char *res = "1";
        char *welcome = malloc(2); 
        strcpy(welcome, res);
        return welcome;
    }
    char *res = query+4;
    int n = atoi(res);
    int a = 0;
    int b = 1;
    int c;
    if( n == 0)
        return toArray(a);
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return toArray(b);
}