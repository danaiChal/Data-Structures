#ifndef _INPUTFILE_H
#define _INPUTFILE_H

#include<iostream>
#include<fstream>
#define N 3000

using namespace std;

/*
Dhmiourgia struct metoxhs me ola ta paidia pou periexontai se kathe grammh twn arxeiwn
*/


struct metoxh{
	string Date;
	float Open;
	float High;
	float Low;
	long int Volume;
	float OpenInt;
	float Close;
	//Date,Open,High,Low,Close,Volume,OpenInt

};

/*
ReadValuesfromFile(ifstream &fin, struct metoxh testarray)
;****************************************************************************************************;
1o orisma arxeio typou ifstream p.x. ifstream finput("agn.us.txt"); opou finput mpainei ws orisma kai
2o orisma typou pinaka apo structs typou "metoxh"
*/

void ReadValuesfromFile(ifstream &fin, struct metoxh StocksArray[]){
	int i=0;
	if (fin.good()){

	while(fin >> StocksArray[i].Date >> StocksArray[i].Open >> StocksArray[i].High >> StocksArray[i].Low >> StocksArray[i].Close >> StocksArray[i].Volume >> StocksArray[i].OpenInt){
		//cout <<"Date: "<< StocksArray[i].Date <<" Open: "<< StocksArray[i].Open <<" High: "<< StocksArray[i].High <<" Low: "<< StocksArray[i].Low <<" Close: "<< StocksArray[i].Close <<" Volume: "<< StocksArray[i].Volume <<" OpenInt: "<< StocksArray[i].OpenInt<<endl;
		//emfanish sto terminal olwn twn periexomenwn tou kathe pinaka

		i++;
		}

		//cout<<"\n\nLast input: "<<i;
		//Ean thelete na deite to megethos twn pinakwn vgalte apo ta sxolia thn grammh kwdika apo panw

	fin.close();
	}
	else{
		cout<<"File Corrupted or doesn't Exist!"<<endl;
	}
}

#endif



