#include <iostream>
#include <vector>

/* class Uncopyable {
    protected:
        Uncopyable() {}
        virtual ~Uncopyable() {}
    private:
        Uncopyable(const Uncopyable&);
        Uncopyable& operator = (const Uncopyable&);
}; */

class Vagon {
    private:
        std::string nume;
        int id = 0;
    public:
        Vagon() {}
        Vagon(std::string nume, int id) {
            this->id = id;
            this->nume =  nume;
            //std::cout<<"Constructor clasa Vagon"<<std::endl;
        }
        virtual ~Vagon() {  
            //std::cout<<"Destructor clasa Vagon"<<std::endl;
        }
        Vagon(const Vagon&) {                    
            //std::cout<<"Copy Constructor clasa Vagon"<<std::endl; 
        } 
        // item11   
        Vagon& operator = (const Vagon& v) {    
            if(this == &v) {
                std::cout<<"Acelasi obiect"<<std::endl;
                return *this;
            }
            std::cout<<"Copy Assignment clasa Vagon"<<std::endl;
            nume = v.nume;
            id = v.id;
            return *this;
        }  
        //item10
        Vagon& operator+=(const Vagon& v) {
            std::cout<<"Operator += clasa Vagon"<<std::endl;
            nume += v.nume;
            id += v.id;
            return *this;
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
        VagonCalatori() : Vagon() {};
        VagonCalatori(std::string nume, int id, int nr_locuri): Vagon(nume, id) {
            this->nr_locuri = nr_locuri;
            //std::cout<<"Constructor clasa VagonCalatori"<<std::endl;
        }
        ~VagonCalatori() {
            //std::cout<<"Destructor clasa VagonCalatori"<<std::endl;
        }
        //item12
        VagonCalatori(const VagonCalatori& v) : Vagon(v) {
            std::cout<<"Copy Constructor clasa VagonCalatori"<<std::endl; 
            this->nr_locuri = v.nr_locuri;
        }
        VagonCalatori operator=(const VagonCalatori& v) {
            if(this == &v) {
                std::cout<<"Acelasi obiect"<<std::endl;
                return *this;
            }
            std::cout<<"Copy Assignment clasa VagonCalatori"<<std::endl;
            Vagon::operator=(v);
            this->nr_locuri = v.nr_locuri;
            return *this;
        }
        int getLocuri() {
            return nr_locuri;
        }
};

class Locomotiva {
    private:
        std::string numeConductor;
        int nr;
    public:
        Locomotiva(std::string nume, int nr) {
            std::cout<<"Constructor clasa Locomotiva"<<std::endl;
            this->numeConductor = nume;
            this->nr = nr;
        }
        ~Locomotiva() { std::cout<<"Destructor clasa Locomotiva"<<std::endl; }
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
    //std::cout<<v1.getNume()<<"->"<<v1.getId()<<"->"<<v1.getLocuri()<<std::endl;

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
    //std::cout<<v4.getId()<<std::endl;
    v2 += v3 += v6;
    std::cout<<v2.getId()<<std::endl;

    v2 = v2;

    VagonCalatori v7("Vagon7", 7, 20);
    VagonCalatori v8;
    v8 = v7;
    std::cout<<v8.getId()<<std::endl; //daca nu apelam copy-ass-op de la clasa de baza am fi avut id = 0
}