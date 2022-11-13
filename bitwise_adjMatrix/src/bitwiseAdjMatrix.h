#pragma once

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::pair;

template <class T>
class BitwiseAdjMatrix {
    public:
        BitwiseAdjMatrix(int n);
        BitwiseAdjMatrix(const vector<pair<T, T>> & v);

        void setEdge(T src, T dest, bool val);
        bool isEdge(T src, T dest) const;

    private:
        vector<int> _matrix;
        unordered_map<T, int> _map;
        int _size;
};

#include "bitwiseAdjMatrix.hpp"