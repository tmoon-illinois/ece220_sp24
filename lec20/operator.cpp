#include <iostream>

using namespace std;
class Point{
    private: 
        int x,y;
    public:
        Point(int _x=0, int _y=0){x=_x; y=_y;}
        
        void ShowPosition(){cout<<x<<", "<<y<<endl;}
       /* 
        void operator+(int val){
            cout<<"operator+(int)"<<endl;
            x = x + val;
            y = y + val;
        }
        */


        Point operator+(int val){
            cout<<"operator+(int)"<<endl;
            Point temp(x+val, y+val);
            return temp;
        }
};
int main(){
    Point p1(1,2);
    Point p2 = p1+10.5;
    p2.ShowPosition();
}

