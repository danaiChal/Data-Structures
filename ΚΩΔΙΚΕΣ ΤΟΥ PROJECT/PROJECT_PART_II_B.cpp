#include <iostream>
#include <queue>
#include <unordered_map>
#include"InputFile.h"
using namespace std;

struct node {
    struct node *left;
    struct metoxh data;
    int height;
    struct node *right;

};

int BinarySearchArr(struct metoxh array[], int first, int middle, int last, long int WVolume){
	first = 0;
   	last = AGN_SIZE - 1;
   	middle = (first+last)/2;
   	bool found = false;
 
    while (first <= last) {
   
       	if(array[middle].Volume < WVolume)
       	{
        first = middle + 1;
        middle = (first + last)/2;
        //cout<<"Right"<<endl;
    	}
       	else if (array[middle].Volume == WVolume)
	   	{
    	
    	cout<< "\nVolume of this date is:" << array[middle].Volume<<endl;
        found = true;
		return middle;
    	}
    	else
		{
		last = middle - 1;
   		middle = (first + last)/2;
   		//cout<<"Left"<<endl;
		}
	}

 
 	if (!found){
  	cout << "Date Not Found!!!"<<endl;
   	}
return -1;
}

void mergeVolume(struct metoxh arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
  
    /* create temp arrays */
    struct metoxh L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[], xorizo sti mesi ton pinaka arr */ 
    //while(g=1){
	
	for (i = 0; i < n1; i++)
        StructAssignTo(arr[left+i], L[i]);		//L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        StructAssignTo(arr[mid + 1 + j],R[j]);//R[j] = arr[m + 1 + j];
    //}
 
    /* Merge the temp arrays back into arr[l..r]* , ftiaxno tous neous pinakes L kai R */
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].Volume <= R[j].Volume) {
            StructAssignTo( L[i], arr[k] ); //arr[k] = L[i]
            i++;
        }
        else {
            StructAssignTo( R[j],arr[k] );//arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        StructAssignTo( L[i],arr[k] );//arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        StructAssignTo( R[j],arr[k] );//arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */

void mergeSortVolume(struct metoxh met[], int left, int right)
{
    if (left >= right) {
    return;
	}
		// Same as (l+r)/2, but avoids overflow for
        // large l and h
        int mid = left + (right - left) / 2;
 
        // Sort first and second halves
        mergeSortVolume(met, left, mid);
        mergeSortVolume(met, mid + 1, right);
 
        mergeVolume(met, left, mid, right);
        //cout<<"Done"<<endl;  //Debug Help
    }


class AVL
{
   
public:
    struct node * root;
    AVL(){
        this->root = NULL;

    }

    int calheight(struct node *p){

            if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;

    }

    int bf(struct node *n){
            if(n->left && n->right){
                return n->left->height - n->right->height;
            }
            else if(n->left && n->right == NULL){
                return n->left->height;
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
    }

    struct node * llrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp;
    }


    struct node * rrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
    }


    struct node * rlrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp;
       
        return tp2;
    }

    struct node * lrrotation(struct node *n){
        struct node *p;
        struct node *tp;
        struct node *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp;
       
        return tp2;
    }

    struct node* insert(struct node *r,struct metoxh data){
       
        if(r==NULL){
            struct node *n;
            n = new struct node;
            StructAssignTo(data,n->data);//n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1;
            return r;            
        }
        else{
            if(data.Volume < r->data.Volume)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }        

        return r;

        }

    void printInorder(struct node* v)
{

    /*--------------------------------------------------------------------------------------*/
    queue <struct node *> q;
        struct node *cur;
        q.push(v);
        q.push(NULL);      

        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur == NULL && q.size()!=0){
               
            cout << "\n";  
                q.push(NULL);
                continue;
            }
            if(cur!=NULL){
                cout<<" Volume: "<<cur->data.Volume<<"|";

                if (cur->left!=NULL){
                q.push(cur->left);
                }
                if (cur->right!=NULL){
                    q.push(cur->right);
                }
            }
           
           
        }
       
    }

void printInorder()
{
    if (this->root == NULL)
        {
cout<<"\n"<<"Empty tree"<<"\n";
return;
}
    printInorder(this->root->left);
 
    cout <<"Volume: "<<this->root->data.Volume<<"|";
 
    printInorder(this->root->right);
}


 
    struct node * deleteNode(struct node *p,struct metoxh data){

        if(p->left == NULL && p->right == NULL){
                if(p==this->root)
                    this->root = NULL;
            delete p;
            return NULL;
        }

        struct node *t;
        struct node *q;
        if(p->data.Volume < data.Volume){
            p->right = deleteNode(p->right,data);
        }
        else if(p->data.Volume > data.Volume){
            p->left = deleteNode(p->left,data);
        }
        else{
            if(p->left != NULL){
                q = inpre(p->left);
                StructAssignTo(q->data,p->data);//p->data = q->data;
                p->left=deleteNode(p->left,q->data);
            }
            else{
                q = insuc(p->right);
                StructAssignTo(q->data,p->data);//  p->data= q->data;
                p->right = deleteNode(p->right,q->data);
            }
        }

        if(bf(p)==2 && bf(p->left)==1){ p = llrotation(p); }                  
        else if(bf(p)==2 && bf(p->left)==-1){ p = lrrotation(p); }
        else if(bf(p)==2 && bf(p->left)==0){ p = llrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==-1){ p = rrrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==1){ p = rlrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==0){ p = llrotation(p); }

       
        return p;
    }

     struct node* inpre(struct node* p){
        while(p->right!=NULL)
            p = p->right;
        return p;    
    }

    struct node* insuc(struct node* p){
        while(p->left!=NULL)
            p = p->left;

        return p;    
    }

struct node* BinarySearch(struct node* n, int WantedDate){
if (n->data.Volume==WantedDate){
cout<<"Found, Date is: "<<n->data.Date<<endl;
return n;
}
else if(n->data.Volume>WantedDate){
n=n->right;
//cout<<"Not Found, Volume is: "<<n->data.Volume;
BinarySearch(n, WantedDate);
}
else{
n=n->left;
//cout<<"Not Found, Volume is: "<<n->data.Volume;
BinarySearch(n, WantedDate);
}
return NULL;
}

    ~AVL(){

    }
};





int main(){
	AVL avltree;
	int choice, x;
	ifstream infile("agn.us.txt");
	struct metoxh Stocks[AGN_SIZE];
	int first = 0;
  	int last = AGN_SIZE-1;
  	int middle = (first + last)/2;
    ReadValuesfromFile(infile, Stocks);
	mergeSortVolume(Stocks, 0, AGN_SIZE-1);
	for (int i = 0; i<AGN_SIZE; i++){
		
		avltree.root=avltree.insert(avltree.root,Stocks[i]);
	//	cout<<avltree.root->data.Date<<endl;

	}
	
	
	do{
		cout<<"AVL Tree Display with In Order Traversal\t(1)\nSearch by Volume and Print Volume\t\t(2)\nSearch by Volume and Set new Volume\t\t(3)\nSearch by Volume and Delete Record\t\t(4)\nFind Min Volume\t\t\t\t\t(5)\nFind Max Volume\t\t\t\t\t(6)\n\nExit\t\t\t\t\t\t(0)"<<endl;
		cin>>choice;
		system("cls");
		switch(choice){
			case 1:
				avltree.printInorder();
				system("PAUSE");
				system("cls");
				break;
			case 2:
				long int find;
				
				cin>>find ;
				BinarySearchArr(Stocks , first, middle, last, find);
				system("PAUSE");
				system("cls");
				break;
			case 3:
				long int find2;
				int t;
				cin>>find2 ;
				t = BinarySearchArr(Stocks , first, middle, last, find2);
				if(t == -1){
					system("cls");
					break;
				}
				cout<<"Give new Volume: ";
				int newvol;
				cin>>newvol;
				Stocks[t].Volume = newvol;
				for (int i = 0; i<AGN_SIZE; i++){
		
				avltree.root=avltree.insert(avltree.root,Stocks[i]);
				//	cout<<avltree.root->data.Date<<endl;
				//cout<<"Tree is Rebuilding"<<endl;
				//system("cls");
				}
				cout<<"Tree Rebuilt"<<endl;
				system("PAUSE");
				system("cls");
				break;
			case 4:
				long int find3;
				int j;
				cin>>find3;
				j = BinarySearchArr(Stocks , first, middle, last, find3);
				if(j == -1){
					system("cls");
					break;
				}
				Stocks[j].Close = -1;
				Stocks[j].Date = -1;
				Stocks[j].High = -1;
				Stocks[j].Low = -1;
				Stocks[j].Open = -1;
				Stocks[j].OpenInt = -1;	
				Stocks[j].Volume = -1;	
				for (int i = 0; i<AGN_SIZE; i++){
				if(Stocks[i].Date!=-1){
				avltree.root=avltree.insert(avltree.root,Stocks[i]);
				//	cout<<avltree.root->data.Date<<endl;
				//cout<<"Tree is Rebuilding"<<endl;
				}
				//system("cls");
				}
				cout<<"Tree Rebuilt"<<endl;			
				system("PAUSE");
				system("cls");
				break;
			case 5:
				mergeSortVolume(Stocks, 0, AGN_SIZE-1);
				cout<<"Date with Min Volume is: "<<Stocks[0].Date<<endl;			//Meta apo to sorting sthn prwti thesi toy pinaka tha vrisketai to mikrotero Volume
				system("PAUSE");
				system("cls");
				break;
			case 6:
				mergeSortVolume(Stocks, 0, AGN_SIZE-1);
				cout<<"Date with Max Volume is: "<<Stocks[AGN_SIZE-1].Date<<endl;	//Meta apo to sorting sthn teleftaia thesi toy pinaka tha vrisketai to megalytero Volume			
				system("PAUSE");
				system("cls");
				break;
			default:
				system("cls");
				break;
		}
			
	}while(choice!=0);
	
	return 0;
}
