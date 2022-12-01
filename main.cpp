#define _HAS_AUTO_PTR_ETC 1
#include <iostream>
#include <vector>
#include<memory>
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

Vagon* createVagonInstance() {
    return (new Vagon);
};

void lock(VagonCalatori& v) {
    std::cout<<"Se blocheaza vagonul"<<std::endl;
    v.setIsLocked(true);
};

void unlock(VagonCalatori& v) {
    std::cout<<"Se deblocheaza vagonul"<<std::endl;
    v.setIsLocked(false);
};

class Lock {
    private:
        VagonCalatori& lockPtr;
    public:
        Lock(VagonCalatori& ptr): lockPtr(ptr) {
            lock(lockPtr);
        }
        ~Lock() {
            unlock(lockPtr);
        }
};

int main()
{    

    VagonCalatori v1("Vagon1", 1, 30);
    /* Vagon v2("Vagon2", 2);
    Vagon v3("Vagon3", 3);
    Vagon v6("Vagon6", 6);

    Vagon v4(v2);   //copy constructor
    Vagon v5;
    v5 = v3; */        //copy assignment

    //Tren t, tAux;
    //t.adaugaVagon(&v2);
    //t.adaugaVagon(&v3);
    //t.printeaza();

    //tema2
    /*  v2 += v3 += v6;
    std::cout<<v2.getId()<<std::endl;

    v2 = v2;

    VagonCalatori v7("Vagon7", 7, 20);
    VagonCalatori v8;
    v8 = v7;
    std::cout<<v8.getId()<<std::endl; //daca nu apelam copy-ass-op de la clasa de baza am fi avut id = 0
 */
    //tema3
    //item13
    std::auto_ptr<Vagon> autoVagon1(createVagonInstance());
    std::cout<<autoVagon1->getId()<<std::endl;
    std::auto_ptr<Vagon> autoVagon2(autoVagon1); 
    //std::cout<<autoVagon1->getId()<<std::endl;  //nu va printa nimic, deoarece autoVagon1 este null acum

    std::shared_ptr<Vagon> sharedVagon1(createVagonInstance());
    std::cout<<sharedVagon1.use_count()<<std::endl;
    std::shared_ptr<Vagon> sharedVagon2(sharedVagon1);
    std::cout<<sharedVagon1.use_count()<<std::endl;
    sharedVagon2->setId(3);
    std::cout<<sharedVagon1->getId()<<std::endl;    //atat sharedVagon2 si sharedVagon1 pointeaza la acelasi obiect returnat de createVagonInstance
    std::shared_ptr<Vagon> sharedVagon3(sharedVagon1);
    std::cout<<sharedVagon1.use_count()<<std::endl; //use_count ne arata numarul de instante pe care le are sharedVagon1

    //item14
    Lock* vagonLocked = new Lock(v1);
    std::cout<<v1.getIsLocked()<<std::endl;
    delete vagonLocked;
    std::cout<<v1.getIsLocked()<<std::endl;
}