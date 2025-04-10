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

int BinarySearchArr(struct metoxh array[], int first, int middle, int last, long int WantedDate){
	first = 0;
   	last = AGN_SIZE - 1;
   	middle = (first+last)/2;
   	bool found = false;
 
    while (first <= last) {
   
       	if(array[middle].Date < WantedDate)
       	{
        first = middle + 1;
        middle = (first + last)/2;
        //cout<<"Right"<<endl;
    	}
       	else if (array[middle].Date == WantedDate)
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
            if(data.Date < r->data.Date)
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
                
                cout<<"\n";
                q.push(NULL);
                continue;
            }
            if(cur!=NULL){
                cout<<"|Date: "<<cur->data.Date<<", Volume: "<<cur->data.Volume<<"|";

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
 
    cout <<"|Date: "<<this->root->data.Date << ", Volume: "<<this->root->data.Volume<<"|";
 
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
        if(p->data.Date < data.Date){
            p->right = deleteNode(p->right,data);
        }
        else if(p->data.Date > data.Date){
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
	if (n->data.Date==WantedDate){
		cout<<"Found, Volume is: "<<n->data.Volume<<endl;
		return n;
	}
	else if(n->data.Date>WantedDate){
		n=n->right;
	//	cout<<"Not Found, Volume is: "<<n->data.Volume;
		BinarySearch(n, WantedDate);
	}
	else{
		n=n->left;
	//	cout<<"Not Found, Volume is: "<<n->data.Volume;
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

	for (int i = 0; i<AGN_SIZE; i++){
		
		avltree.root=avltree.insert(avltree.root,Stocks[i]);
	//	cout<<avltree.root->data.Date<<endl;

	}
	
	
	do{
		cout<<"AVL Tree Display with In Order Traversal\t(1)\nSearch by Date and Print Volume\t\t\t(2)\nSearch by Date and Set new Volume\t\t(3)\nSearch by Date and Delete Record\t\t(4)\n\nExit\t\t\t\t\t\t(0)"<<endl;
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
				find = getDatefromKeyboard();
				BinarySearchArr(Stocks , first, middle, last, find);
				system("PAUSE");
				system("cls");
				break;
			case 3:
				long int find2;
				int t;
				find2 = getDatefromKeyboard();
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
				find3 = getDatefromKeyboard();
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
			default:
				system("cls");
				break;
		}
			
	}while(choice!=0);
	
	return 0;
}
