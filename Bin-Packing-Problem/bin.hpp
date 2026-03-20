#ifndef BIN_HPP
#define BIN_HPP
#include <vector>
class Bin{
    float capacity;
    float size;
    std::vector<float> items;
    public:
    Bin();
    Bin(float item);
    float fit(float item) const;
    bool insert(float item);
    float getSize() const;
    void print();
};
#endif