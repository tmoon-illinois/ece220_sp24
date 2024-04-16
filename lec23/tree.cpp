#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;


class Vehicle{
    private:
        int passenger;
        double baggage;
    public:
        Vehicle(){};
        Vehicle(int person, double weight){
            passenger = person;
            baggage = weight;
        }
        void Ride(int person){
            passenger += person;
        }
        void Load(double weight){
            baggage += weight;
        }
        int getPassenger(){ return passenger;};
        double getBaggage(){ return baggage;};
        void setPassenger(int passenger_){ passenger = passenger_;};
        void getBaggage(double baggage_){ baggage = baggage_;};

        virtual void ShowData() = 0;
};

class Airplane : public Vehicle{
    private:
        int crew_man;
    public:
        Airplane(int person, double weight, int crew) : Vehicle(person, weight){
            crew_man = crew;
        }
        void TakeCrew(int crew){
            crew_man += crew;
        }
        void ShowData(){
            cout<<"<<Airplane>> "<<endl;
            cout<<"passenger: "<<getPassenger()<<endl;
            cout<<"baggage: "<<getBaggage()<<endl;
            cout<<"crew man: "<<crew_man<<endl;
        }
};

class Train : public Vehicle{
    private:
        int length;
    public:
        Train(int person, double weight, int len) : Vehicle(person, weight){
            length = len;
        }
        void AddLength(int len){
            length += len;
        }
        void ShowData(){
            cout<<"<<Train>> "<<endl;
            cout<<"passenger: "<<getPassenger()<<endl;
            cout<<"baggage: "<<getBaggage()<<endl;
            cout<<"length: "<<length<<endl;
        }
};


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
    key = key_;
    data = data_;

    left = NULL;
    right = NULL;
}
string Node::getKey(){
    return key;
}
void Node::setKey(string key_){
    key = key_;
}
list<Vehicle*> Node::getData(){
    return data;
}
void Node::setData(list<Vehicle*> data_){
    data = data_;
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
    root = NULL;
}
void BinaryTree::post_order(Node *node){
    if (node == NULL)
        return;
    else{
        post_order(node->left);
        post_order(node->right);
        cout<<"----- City: "<<node->getKey()<<" ---------"<<endl;
        list<Vehicle*> temp = node->getData();
        list<Vehicle*>::iterator it;
        for( it = temp.begin(); it != temp.end(); it++){
            (*it)->ShowData();
        }
    }
}
void BinaryTree::insert_node(Node *node, Node *data){
    // base 1. first node (root)
    if(node == NULL){
        root = data;
        return;
    }
    else{
        if( data->getKey() < node->getKey() ){
            if(node->left == NULL){
                node->left = data;
            }
            else
                insert_node(node->left, data);
        }
        else if( data->getKey() > node->getKey() ){
            if(node->right == NULL){
                node->right = data;
            }
            else
                insert_node(node->right, data);
        }
        //when the node already contain the new key
        else 
            return;
    }
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
