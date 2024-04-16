#include <iostream>

template <typename T>
T Mul(T a, T b){
    return a*b;
}

using namespace std;
class Point{
    private:
        int x,y;
    public:
        Point(int _x = 0, int _y = 0){ x = _x; y = _y;}
        void ShowPosition() const {cout<<x<<", "<<y<<endl;}
        Point operator*(Point &p){
            Point temp(x*p.x, y*p.y);
            return temp;
        }
        Point& operator++(){
            x++;y++;
            return *this;
        }
};


int main(){
    Point p1(1,2), p2(2,3);

    Point p3 = Mul(p1, p2);
//    Point p3 = Mul(++(++p1), ++p2);
    p1.ShowPosition();
    p2.ShowPosition();
    p3.ShowPosition();
}
