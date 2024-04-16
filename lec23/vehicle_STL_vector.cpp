#include <iostream>
#include <vector>

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
        // Vehicle *vlist[100];
        vector<Vehicle*> vlist;
        // int index;
    public:
        City(){ }
        void AddVehicle(Vehicle *v){
            // vlist[index++] = v;
            vlist.push_back(v);
        }
        void ShowList(){
            for(int i=0;i<vlist.size();i++)
                vlist[i]->ShowData();
        }
};
int main(){
    City Champaign;

    Champaign.AddVehicle(new Airplane(30,100,5));
    Champaign.AddVehicle(new Train(100,300,10));
    Champaign.AddVehicle(new Train(130,300,15));

    Champaign.ShowList();


}



