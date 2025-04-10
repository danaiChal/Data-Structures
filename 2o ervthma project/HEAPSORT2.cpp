#include<stdio.h>
#include <iostream>
#include<string.h>
#include<stdbool.h>
#include <cstdio>
#define MAXCHAR 1000

using namespace std;

int main(){

    FILE *fp;
    char row[MAXCHAR];

    fp = fopen("agn.txt","r");



    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        cout << row << endl;
    }

    //fclose(fp);
    return 0;
}
