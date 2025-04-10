// C++ program for implementation of Heap Sort
//#ifndef _INPUTFILE_H
#define _INPUTFILE_H

#include<iostream>
#include<fstream>
#define AGN_SIZE 3239
#define AINV_SIZE 3201
#define ALE_SIZE 3201

using namespace std;

struct metoxh
{
	long int Date;
	float Open;
	float High;
	float Low;
	long int Volume;
	float OpenInt;
	float Close;
	//Date,Open,High,Low,Close,Volume,OpenInt

};

void StructAssignTo(struct metoxh &s1, struct metoxh &s2)
{ //StructAssignTo(s1[i], R[n])---->R[n]=s1[i] ,,,,,,,,,,,,,,,,,,,,,,s2=s1
	s2.Date=s1.Date;
	s2.Open=s1.Open;
	s2.High=s1.High;
	s2.Low=s1.Low;
	s2.OpenInt=s1.OpenInt;
	s2.Volume=s1.Volume;
	s2.Close=s1.Close;
}

/*
ReadValuesfromFile(ifstream &fin, struct metoxh testarray)
;****************************************************************************************************;
1o orisma arxeio typou ifstream p.x. ifstream finput("agn.us.txt"); opou finput mpainei ws orisma kai
2o orisma typou pinaka apo structs typou "metoxh"
*/

void ReadValuesfromFile(ifstream &fin, struct metoxh StocksArray[]){
	int i=0;
	if (fin.good())
        {

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

void PrintValuesfromFile(ifstream &fin, struct metoxh StocksArray[]){
	int i=0;
	if (fin.good()){

	while(fin >> StocksArray[i].Date >> StocksArray[i].Open >> StocksArray[i].High >> StocksArray[i].Low >> StocksArray[i].Close >> StocksArray[i].Volume >> StocksArray[i].OpenInt){
		cout <<"Date: "<< StocksArray[i].Date <<" Open: "<< StocksArray[i].Open <<" High: "<< StocksArray[i].High <<" Low: "<< StocksArray[i].Low <<" Close: "<< StocksArray[i].Close <<" Volume: "<< StocksArray[i].Volume <<" OpenInt: "<< StocksArray[i].OpenInt<<endl;
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


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{
    struct metoxh pinakas[4000];
    int n = sizeof(pinakas) / sizeof(pinakas[0]);
    long int Date;
    float Close;
    int i;
//ifstream myfile;
//myfile.open ("agn.us");
//ReadValuesfromFile( myfile, StocksArray);
//myfile.close();
ifstream myfile ("agn.us");
 if (myfile.is_open())
  {
      ReadValuesfromFile(myfile, pinakas);
      StructAssignTo(Date, Close);
      PrintValuesfromFile(myfile, pinakas);
      heapSort(pinakas,n-1);

    cout << "Sorted array is \n";
    //printArray(pinakas, n);
    //myfile << "This is a line.\n";
    //myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";

ifstream myfile1 ("ainv.us");
 if (myfile1.is_open())
  {
      ReadValuesfromFile( myfile1, pinakas);
      StructAssignTo(Date, Close);
      PrintValuesfromFile(myfile1, pinakas);
      heapSort(pinakas,n-1);
    cout << "Sorted array is \n";
    //printArray(pinakas, n);
    //myfile << "This is a line.\n";
    //myfile << "This is another line.\n";
    myfile1.close();
  }
  else cout << "Unable to open file";

ifstream myfile2 ("ale.us");
 if (myfile2.is_open())
  {
      ReadValuesfromFile( myfile2, pinakas);
      StructAssignTo(Date, Close);
      PrintValuesfromFile(myfile2, pinakas);
      heapSort(pinakas,n-1);
    cout << "Sorted array is \n";
    //printArray(pinakas, n);
    //myfile << "This is a line.\n";
    //myfile << "This is another line.\n";
    myfile2.close();
  }
  else cout << "Unable to open file";
return 0;
}
/*ifstream myfile1;
myfile1.open ("ainv.us");
ReadValuesfromFile( myfile1,StocksArray);
myfile1.close();

ifstream myfile2;
myfile2.open ("ale.us");
ReadValuesfromFile( myfile2,StocksArray);
myfile2.close();*/




    /*cout<< "given array is \n"<< " ";
    printArray(StocksArray, n);

    /*heapSort(StocksArray,n-1);
    cout << "Sorted array is \n";
    printArray(StocksArray, n);
    return 0;*/

// diavase arxeio apo link sofias email
// kanw to date me to close mia sthlh kai taxinomw thn sthlh ayth
