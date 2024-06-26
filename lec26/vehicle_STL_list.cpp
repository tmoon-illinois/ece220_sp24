#include <iostream>
#include <list>

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

class City{
    private:
        list<Vehicle*> vlist;
        string name;
    public:
        City(){ }
        City(string name_){
            name = name_;
        }
        City(string name_, list<Vehicle*>vlist_){
            name = name_;
            vlist = vlist_;
        }
        void setVehicle(Vehicle *v){

        }
        void AddVehicle(Vehicle *v){
            vlist.push_back(v);
        }
        void ShowList(){
            cout<<name<<endl;
            list<Vehicle*>::iterator it;
            for(it=vlist.begin() ; it != vlist.end(); it++)
                (*it)->ShowData();
        }
        // City operator+(const City &c){
        //     string temp_name = name + c.name;
        //     list<Vehicle*>::iterator it;
        //     list<Vehicle*> temp = c.vlist;
        //     City temp_city(temp_name); //temp city Chamapgin
        //     list<Vehicle*> temp2 = vlist;
        //     for(it = temp.begin(); it != temp.end(); it++){
        //         temp2.push_back( *it );
        //     }
        //     temp_city.vlist = temp2;

        //     return temp_city;

        // }
        City operator+(const City &c){
            string temp_name = name + " "+ c.name;
            list<Vehicle*> temp = c.vlist;
            list<Vehicle*> temp2 = vlist;
            list<Vehicle*>::iterator it;
            for(it = temp.begin(); it != temp.end(); it++){
                temp2.push_back( *it );
            }
            return City(temp_name, temp2);
        }
};
int main(){
    City Champaign("Champaign");
    Champaign.AddVehicle(new Airplane(30,100,5));
    Champaign.AddVehicle(new Airplane(10,200,10));

    City Urbana("Urbana");
    Urbana.AddVehicle(new Train(130,300,15));

    City CU = Champaign + Urbana;    // Champaign.operator+(Urbana)
    CU.ShowList();
    Champaign.ShowList();
    Urbana.ShowList();

}



