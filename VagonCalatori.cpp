#include <iostream>
#include "Vagon.cpp"

class VagonCalatori :public Vagon {
    private:
        int nr_locuri;
    public:
        VagonCalatori() : Vagon() {};
        VagonCalatori(std::string nume, int id, int nr_locuri): Vagon(nume, id) {
            this->nr_locuri = nr_locuri;
            std::cout<<"Constructor clasa VagonCalatori"<<std::endl;
        }
        ~VagonCalatori() {
            std::cout<<"Destructor clasa VagonCalatori"<<std::endl;
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