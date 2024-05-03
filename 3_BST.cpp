#include<iostream>
using namespace std;


class node{
	public:
		int data;
		node *lptr;
		node *rptr;
};
class Bst{
	public:
		node *create(int key){
			node *newnode = new node;
			newnode->data = key;
			newnode->lptr = NULL;
			newnode->rptr = NULL;
			return newnode;
		}
		
		void insert(node *root,int key){
			if(root==NULL)
			return;
			
			node *newnode = new node;
			newnode->data = key;
			newnode->lptr = NULL;
			newnode->rptr = NULL;
			if(root->data>key){
				if(root->lptr==NULL){
					root->lptr=newnode;
				}
				else{
					insert(root->lptr,key);
				}
			}
			else if(root->data<key){
				if(root->rptr==NULL){
					root->rptr=newnode;
				}
				else{
					insert(root->rptr,key);
				}
			}
			else{
				cout<<"Duplicate elements not alllowed"<<endl;
			}
		}
		
		void preorder(node *root){
			if(root!=NULL){
				cout<<" "<<root->data<<"->";
				preorder(root->lptr);
				preorder(root->rptr);
				cout<<" "<<endl;
			}
		}
		
		void postorder(node *root){
			if(root!=NULL){
				postorder(root->lptr);
				postorder(root->rptr);
				cout<<" "<<root->data<<"->";
				cout<<" "<<endl;
			}
		}
		
		void inorder(node *root){
			if(root!=NULL){
				inorder(root->lptr);
				cout<<" "<<root->data<<"->";
				inorder(root->rptr);
				cout<<" "<<endl;
			}
		}
		
		void minimum(node *root){
			while(root->lptr!=NULL){
				root = root->lptr;
			}
			cout<<"/n The minimum element in the tree is:"<<root->data<<endl;
		}	
};

int main(){
	int choice, key;
	node *root=NULL;
	Bst bst;
	
	while(1){
		
		cout<<"1.insert"<<endl;
		cout<<"2.preorder"<<endl;
		cout<<"3.postorder"<<endl;
		cout<<"4,inorder"<<endl;
		cout<<"5.minimum"<<endl;
		
		cout<<"Enter Your Choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter key to insert::"<<endl;
				cin>>key;
				if(root==NULL)
				root=bst.create(key);
				else
				bst.insert(root,key);
				break;
				
			
			case 2:
				cout<<"preorder"<<endl;
				bst.preorder(root);
				break;	
			
			case 3:
				cout<<"postorder"<<endl;
				bst.postorder(root);
				break;
				
			case 4:
				cout<<"inorder"<<endl;
				bst.inorder(root);
				break;
				
			case 5:
				bst.minimum(root);
				break;
		}
	}
	return 0;
}










