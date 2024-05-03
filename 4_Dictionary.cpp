#include <iostream>
#include <string>
using namespace std;

struct Entry {
    string keyword;
    string meaning;
};

class node{
    public:
        Entry data;
        node *lptr;
        node *rptr;
};

class Bst{
    public:
        node *create(Entry entry){
            node *newnode = new node;
            newnode->data = entry;
            newnode->lptr = NULL;
            newnode->rptr = NULL;
            return newnode;
        }
        
        void insert(node *root, Entry entry){
            if(root==NULL)
                return;
            
            node *newnode = new node;
            newnode->data = entry;
            newnode->lptr = NULL;
            newnode->rptr = NULL;
            
            if(entry.keyword < root->data.keyword){
                if(root->lptr==NULL){
                    root->lptr=newnode;
                }
                else{
                    insert(root->lptr, entry);
                }
            }
            else if(entry.keyword > root->data.keyword){
                if(root->rptr==NULL){
                    root->rptr=newnode;
                }
                else{
                    insert(root->rptr, entry);
                }
            }
            else{
                cout<<"Duplicate keywords not allowed"<<endl;
            }
        }
        
        void displayDictionary(node *root){
            if(root!=NULL){
                displayDictionary(root->lptr);
                cout << root->data.keyword << ": " << root->data.meaning << endl;
                displayDictionary(root->rptr);
            }
        }
        
        void searchKeyword(node *root, string keyword, int &comparisons){
            if(root == NULL){
                cout << "Keyword not found!" << endl;
                return;
            }
            
            comparisons++;
            
            if(keyword == root->data.keyword){
                cout << "Meaning of " << keyword << ": " << root->data.meaning << endl;
                return;
            }
            else if(keyword < root->data.keyword){
                searchKeyword(root->lptr, keyword, comparisons);
            }
            else{
                searchKeyword(root->rptr, keyword, comparisons);
            }
        }
};

int main(){
    int choice;
    string keyword, meaning;
    node *root=NULL;
    Bst bst;
    
    while(1){
        cout << "1. Insert a keyword" << endl;
        cout << "2. Display dictionary" << endl;
        cout << "3. Search for a keyword" << endl;
        cout << "4. Exit" << endl;
        
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch(choice){
			case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin>> meaning ;
                if(root==NULL)
                    root=bst.create(Entry{keyword, meaning});
                else
                    bst.insert(root, Entry{keyword, meaning});
                break;
                
            case 2:
                cout << "Dictionary:" << endl;
                bst.displayDictionary(root);
                break;
                
            case 3:
                cout << "Enter keyword to search: ";
                cin >> keyword;
                int comparisons = 0;
                bst.searchKeyword(root, keyword, comparisons);
                cout << "Number of comparisons: " << comparisons << endl;
                break;
            
		}
    }
    return 0;
}

