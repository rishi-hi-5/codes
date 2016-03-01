
//Sample code for class templates

#include <iostream>
#include <cassert>
using namespace std;

// class template
template<typename T=int>
class stk
{
    private:
        int top;
        T *buf;
        int sz;
    public:
        explicit stk(int size=100) : buf (new T[size]), top(-1), sz(size) {}
        //stk(int size): buf (new T[size]), top(-1), sz(size) {}
        bool isEmpty() const { return top == -1; }
        bool isFull() const { return top == sz - 1; }
        void push(const T data) {
            assert(!isFull());
            buf[++top] = data;
        }
        T pop() {
            assert(!isEmpty());
            return buf[top--];
        }
        ~stk() { delete []buf; }
};

int main(int argc, const char *argv[])
{
    stk<> s(10);
    int x;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    while (!s.isEmpty()) {
        x = s.pop();
        cout << x << endl;
    }
    stk<float> sf(10);
    float f;
    sf.push(10.1f);
    sf.push(20.2f);
    sf.push(30.3f);
    sf.push(40.4f);
    sf.push(50.5f);
    while (!sf.isEmpty()) {
        f = sf.pop();
        cout << f << endl;
    }

}
