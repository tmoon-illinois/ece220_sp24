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
    public:
        City(){ }
        void AddVehicle(Vehicle *v){
            vlist.push_back(v);
        }
        void ShowList(){
            list<Vehicle*>::iterator it;
            for(it=vlist.begin() ; it != vlist.end(); it++)
                (*it)->ShowData();
        }
};
int main(){
    City Champaign("Champaign");
    Champaign.AddVehicle(new Airplane(30,100,5));
    Champaign.AddVehicle(new Airplane(10,200,10));
    Champaign.ShowList();

    City Urbana("Urbana");
    Urbana.AddVehicle(new Train(130,300,15));
    Urbana.ShowList();

    City CU = Champaign + Urbana;
    CU.ShowList();

}



