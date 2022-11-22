#include <iostream>

class Vagon {
    private:
        std::string nume;
        int id = 0;
    public:
        Vagon() {}
        Vagon(std::string nume, int id) {
            this->id = id;
            this->nume =  nume;
            std::cout<<"Constructor clasa Vagon"<<std::endl;
        }
        virtual ~Vagon() {  
            std::cout<<"Destructor clasa Vagon"<<std::endl;
        }
        Vagon(const Vagon&) {                    
            std::cout<<"Copy Constructor clasa Vagon"<<std::endl; 
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