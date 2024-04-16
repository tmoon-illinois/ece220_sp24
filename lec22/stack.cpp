#include <iostream>
using namespace std;
template <class T>
class MyStack{
    private:
        int TOS;
        int size;
        T *data;
    public:
        MyStack(int _size =3){
            TOS = -1;
            size = _size;
            data = new T[size];
        }
        ~MyStack(){delete []data;}
        void push(const T &value){
            if(full()){cout<<"overflow"<<endl;return;}
            TOS++;
            data[TOS] = value;
        }
        T top() const {return data[TOS];}
        void pop(){
            if(empty()){cout<<"underflow"<<endl;return;}
            TOS--;
        }
        bool empty()const{
            if(TOS==-1) return true;
            else return false;
        }
        bool full()const{
            if(TOS==size-1) return true;
            else return false;
        }
};

class Point{
    private:
        int x,y;
    public:
        Point(){x=0;y=0;}
        Point(int _x, int _y){x=_x;y=_y;}
        void show(){cout<<x<<","<<y<<endl;}
        Point operator*(const Point &p){
            Point temp(x * p.x, y * p.y);
            return temp;
        }
        void set(int _x, int _y){x=_x; y=_y;}
};
int main(){
    MyStack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    s.pop();
    
    MyStack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    s1.pop();

    MyStack<Point> s2;
    s2.push(Point(1,1));
    s2.push(Point(2,1));
    s2.push(Point(3,3));

    Point temp;
    while(!s2.empty()){
        temp = s2.top();
        temp.show();
        s2.pop();
    }
}




