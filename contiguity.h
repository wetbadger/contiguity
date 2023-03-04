/* contiguity.h */

#ifndef CONTIGUITY_H
#define CONTIGUITY_H

#include "core/reference.h"
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        std::size_t h1 = std::hash<T1>{}(p.first);
        std::size_t h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

struct equal_pair {
    template <class T1, class T2>
    bool operator()(const std::pair<T1, T2> &p1, const std::pair<T1, T2> &p2) const {
        return p1.first == p2.first && p1.second == p2.second;
    }
};

class Contiguity : public Reference {
    GDCLASS(Contiguity, Reference);

private:
    std::unordered_map<std::pair<int, int>, bool, pair_hash, equal_pair> shape;

protected:
    static void _bind_methods();
    bool explore(int row, int col);
    bool isFilledCell(int row, int col);

public:
    void addPoint(Vector2 p);
    void removePoint(Vector2 p);
    bool isContiguous(Vector2 startingPoint);

    Contiguity();
};

#endif // CONTIGUITY_H