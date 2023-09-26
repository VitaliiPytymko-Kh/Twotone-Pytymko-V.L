//На основе кода паттерна Singleton(см.слайд №15 презентации по Паттернам проектирования) 
// создать класс Twotone, позволяющий создавать только 2 объекта этого класса.

#include <iostream>
#include <stdexcept>
using namespace std;

class Twotone {
private:
    
    static Twotone* s1;
    static Twotone* s2;
    int k;
    
    Twotone(int i) : k(i) {}

public:
    
    static Twotone* getReference(int sNum) {
        if (sNum==0){
            if (!s1) {
                s1 = new Twotone(0);
            } return s1;
        }
        else if (sNum == 1) {
            if (!s2) {
                s2 = new Twotone(0);
            }return s2;
        }
        else {
             throw runtime_error ( " Error: Cannot create more than two object!! ");
             
        }
                 
    }
    
    int getValue() {
        return k;
    }
    
    void setValue(int i) {
        k = i;
    }
};

Twotone* Twotone::s1 ;
Twotone* Twotone::s2 ;

int main() {
    
    try {
        Twotone* p = Twotone::getReference(0);
      
        if (p) {
            cout << p->getValue() << "\n\n";
            p->setValue(p->getValue() + 5);
            cout << p->getValue() << "\n\n";
        }

        Twotone* b = Twotone::getReference(1);
        if (b) {
            cout << b->getValue() << "\n\n";
            b->setValue(b->getValue() + 15);
            cout << b->getValue() << "\n\n";
        }

        Twotone* c = Twotone::getReference(2);
        if (c) {
            cout << c->getValue() << "\n\n";
            c->setValue(c->getValue() + 25);
            cout << c->getValue() << "\n\n";
        }
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return 0;
}

