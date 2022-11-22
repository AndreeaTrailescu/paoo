#include <iostream>
#include <vector>
#include "VagonCalatori.cpp"

class Uncopyable {
    protected:
        Uncopyable() {}
        virtual ~Uncopyable() {}
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator = (const Uncopyable&);
}; 

class Tren {
    private:
        std::vector<Vagon*> vagoane;

    public:
        Tren() { std::cout<<"Constructor clasa Tren"<<std::endl; }
        ~Tren() { std::cout<<"Destructor clasa Tren"<<std::endl; }
        void adaugaVagon(Vagon *v) {
            this->vagoane.push_back(v);
        }
        void printeaza() {
            for(int i = 0; i < vagoane.size(); i++) {
                std::cout<<(*vagoane[i]).getNume()<<" ";
            }
            std::cout<<std::endl;
        }
};

int main()
{    

    VagonCalatori v1("Vagon1", 1, 30);
    Vagon v2("Vagon2", 2);
    Vagon v3("Vagon3", 3);
    Vagon v6("Vagon6", 6);

    Vagon v4(v2);   //copy constructor
    Vagon v5;
    v5 = v3;        //copy assignment

    Tren t, tAux;
    t.adaugaVagon(&v2);
    t.adaugaVagon(&v3);
    //t.printeaza();

    //tema2
    v2 += v3 += v6;
    std::cout<<v2.getId()<<std::endl;

    v2 = v2;

    VagonCalatori v7("Vagon7", 7, 20);
    VagonCalatori v8;
    v8 = v7;
    std::cout<<v8.getId()<<std::endl; //daca nu apelam copy-ass-op de la clasa de baza am fi avut id = 0
}