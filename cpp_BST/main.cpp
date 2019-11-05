#include <iostream>
using namespace std;

class node{
private:
  int key;      //key attribute
  node *right;  //right pointer
  node *left;   //left pointer
public:
  node(int key){          //constructor for our class node
    this->key = key;      //assign the parameter key to the attribute key
    right = NULL;         //setting all the pointers null
    left = NULL;
  }
  /*===== GETTERS =====*/
  int getKey(){
    return this->key;
  }
  node* getLeft(){
    return this->left;
  }
  node* getRight(){
    return this->right;
  }
  /*===== SETTERS =====*/
  void setKey(int key){
    this->key = key;
  }
  void setLeft(node *left){
    this->left = left;
  }
  void setRight(node *right){
    this->right = right;
  }
};

class BST{
private:
  node *root;
public:
  BST(){
    root = NULL;
  }
  void add(node *temp){
    if(root == NULL){
      root = temp;
    }else{
      recursive_add(root,temp);
    }
  }
  void recursive_add(node *current, node *temp){
    if(temp->getKey() < current->getKey()){
      if(current->getLeft() != NULL){
        recursive_add(current->getLeft(),temp);
      }else{
        current->setLeft(temp);
      }
    }else if (temp->getKey() > current->getKey()){
      if(current->getRight() != NULL){
        recursive_add(current->getRight(),temp);
      }else{
        current->setRight(temp);
      }
    }
  }
  void inorder(){
    inorder_recursive(root);
  }
  void inorder_recursive(node *current){
    if(current->getLeft()!=NULL){
      inorder_recursive(current->getLeft());
    }
    cout<<current->getKey();
    cout<<"->";
    if(current->getRight()!=NULL){
      inorder_recursive(current->getRight());
    }
  }
};

int main(){
  BST *tree = new BST();
  tree->add(new node(5));
  tree->add(new node(2));
  tree->add(new node(7));
  tree->add(new node(1));
  tree->add(new node(3));
  tree->add(new node(6));
  tree->add(new node(8));

  tree->inorder();
  cout<<"\n";
}
