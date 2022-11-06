#include <iostream>
#include <vector>

// previne copierea prin declararea privata a copy constructorului si copy assignmentului
class Uncopyable {
    protected:
        Uncopyable() {}
        virtual ~Uncopyable() {}
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator = (const Uncopyable&);
};

class Vagon {
    private:
        std::string nume;
        int id;
    public:
        Vagon() {}
        Vagon(std::string nume, int id) {
            this->id = id;
            this->nume =  nume;
            std::cout<<"Constructor clasa Vagon"<<std::endl;
        }
        virtual ~Vagon() {  //pentru a fi siguri ca se distruge si clasa derivata odata cu cea de baza
            std::cout<<"Destructor clasa Vagon"<<std::endl;
        }
        Vagon(const Vagon&) {                    //deep copy
            std::cout<<"Copy Constructor clasa Vagon"<<std::endl; 
        }    
        Vagon& operator = (const Vagon& v) {    //shallow copy
            std::cout<<"Copy Assignment clasa Vagon"<<std::endl;
        }     
        int getId() {
            return id;
        }
        std::string getNume() {
            return nume;
        }
};

class VagonCalatori :public Vagon {
    private:
        int nr_locuri;
    public:
        VagonCalatori(std::string nume, int id, int nr_locuri): Vagon(nume, id) {
            this->nr_locuri = nr_locuri;
            std::cout<<"Constructor clasa VagonCalatori"<<std::endl;
        }
        ~VagonCalatori() {
            std::cout<<"Destructor clasa VagonCalatori"<<std::endl;
        }
        int getLocuri() {
            return nr_locuri;
        }
};

class Tren: private Uncopyable {
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
    std::cout<<v1.getNume()<<"->"<<v1.getId()<<"->"<<v1.getLocuri()<<std::endl;

    Vagon v2("Vagon2", 2);
    Vagon v3("Vagon3", 3);

    Vagon v4(v2);   //copy constructor
    Vagon v5;
    v5 = v3;        //copy assignment

    Tren t, tAux;
    t.adaugaVagon(&v2);
    t.adaugaVagon(&v3);
    t.printeaza();

    // nu se vor putea realiza nicio forma de copiere
    /*  tAux = t;
    Tren tt(t); */
}