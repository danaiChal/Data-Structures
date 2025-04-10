// Counting sort in C++ programming

#include <iostream>
#include <fstream>
using namespace std;


struct metoxh
{
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


void countSort(int array[], int size) {
  // The size of count must be at least the (max+1) but
  // we cannot assign declare it as int count(max+1) in C++ as
  // it does not support dynamic memory allocation.
  // So, its size is provided statically.
  int output[10];
  int count[10];
  int max = array[0];

  // Find the largest element of the array
  for (int i = 1; i < size; i++)
    {
    if (array[i] > max)
      max = array[i];
    }

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i)
    {
    count[i] = 0;
    }

  // Store the count of each element
  for (int i = 0; i < size; i++)
    {
    count[array[i]]++;
    }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++)
    {
    count[i] += count[i - 1];
    }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--)
    {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
    }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++)
    {
    array[i] = output[i];
    }
}

// Function to print an array
void printArray(int array[], int size)
{
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main()
{
    struct metoxh StocksArray[4000];
    int n = sizeof(StocksArray) / sizeof(StocksArray[0]);

//ifstream myfile;
//myfile.open ("agn.us");
//ReadValuesfromFile( myfile, StocksArray);
//myfile.close();
ifstream myfile ("agn.us");
 if (myfile.is_open())
  {
      ReadValuesfromFile( myfile, StocksArray);
      countSort((StocksArray,n-1);
    cout << "Sorted array is \n";
    printArray(StocksArray, n);
    //myfile << "This is a line.\n";
    //myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";

ifstream myfile1 ("ainv.us");
 if (myfile1.is_open())
  {
      ReadValuesfromFile( myfile1, StocksArray);
      countSort(StocksArray,n-1);
    cout << "Sorted array is \n";
    printArray(StocksArray, n);
    //myfile << "This is a line.\n";
    //myfile << "This is another line.\n";
    myfile1.close();
  }
  else cout << "Unable to open file";

ifstream myfile2 ("ale.us");
 if (myfile2.is_open())
  {
      ReadValuesfromFile( myfile2, StocksArray);
      countSort(StocksArray,n-1);
    cout << "Sorted array is \n";
    printArray(StocksArray, n);
    //myfile << "This is a line.\n";
    //myfile << "This is another line.\n";
    myfile2.close();
  }
  else cout << "Unable to open file";
return 0;
}


