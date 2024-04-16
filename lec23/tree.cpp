#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class Node {
    private:
        string key;
        list<Vehicle*> data;
    public:
        Node *left;
        Node *right;

        Node(string key_, list<Vehicle*> data_);
        string getKey();
        void setKey(string key_);
        list<Vehicle*> getData();
        void setData(list<Vehicle*> data_);
};

Node::Node(string key_, list<Vehicle*> data_){ 
}
string Node::getKey(){
}
void Node::setKey(string key_){
}
list<Vehicle*> Node::getData(){
}
void Node::setData(list<Vehicle*> data_){
}
class BinaryTree{
    private:
        Node *root;
    public:
        BinaryTree();
        ~BinaryTree(){};
        Node* getRoot(){return root;};
        void insert_node(Node *root, Node *data);
        void post_order(Node *root);
};
BinaryTree::BinaryTree(){
}
void BinaryTree::post_order(Node *node){
}
void BinaryTree::insert_node(Node *node, Node *data){
}

int main(){
    BinaryTree bst;

    list<Vehicle*> vlist;
    vlist.push_back(new Airplane(10, 10, 5));
    vlist.push_back(new Airplane(100, 10, 50));
    vlist.push_back(new Airplane(200, 10, 5));
    Node *temp = new Node("Savoy", vlist);
    bst.insert_node(bst.getRoot(), temp);

    vlist.clear();
    vlist.push_back(new Train(10, 10, 5));
    vlist.push_back(new Train(100, 10, 50));
    vlist.push_back(new Train(200, 10, 5));
    temp = new Node("Urbana", vlist);
    bst.insert_node(bst.getRoot(), temp);
    
    vlist.clear();
    vlist.push_back(new Airplane(10, 10, 5));
    vlist.push_back(new Train(100, 10, 50));
    vlist.push_back(new Airplane(200, 10, 5));
    temp = new Node("Champaign", vlist);
    bst.insert_node(bst.getRoot(), temp);


    bst.post_order(bst.getRoot());

}
