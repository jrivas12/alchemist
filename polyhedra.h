#ifndef POLYHEDRA_H
#define POLYHEDRA_H

#include <string>

class Polyhedra {
public:
    std::string name;
    std::string wythoff;
    std::string symbol;
    std::string c_num;
    std::string w_num;
    std::string u_num;
    std::string k_num;
    int vertices;
    int edges;
    int faces;
    std::string faces_by_type;

    void display(int longest_line_length) const;
};

#endif
