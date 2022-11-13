#include "assert.h"

template <class T>
BitwiseAdjMatrix<T>::BitwiseAdjMatrix(int n) : _size(n) {
    int area = n*n;
    int bits = sizeof(int)*8;
    _matrix = vector<int>(area/bits + (area%bits != 0));
}

template <class T>
BitwiseAdjMatrix<T>::BitwiseAdjMatrix(const vector<pair<T, T>> & v) {
    int count = 0;
    for (const pair<T, T> & p : v) {
        if (_map.find(p.first) == _map.end()) {_map[p.first] = count; count++;}
        if (_map.find(p.second) == _map.end()) {_map[p.second] = count; count++;}
    }
    _size = count;
    int area = _size*_size;
    int bits = sizeof(int)*8;
    _matrix = vector<int>(area/bits + (area%bits != 0));

    for (const pair<T, T> & p : v) setEdge(p.first, p.second, true);
}

template <class T>
void BitwiseAdjMatrix<T>::setEdge(T src, T dest, bool val) {
    int bits = sizeof(int)*8;
    int idx = _map.at(src)*_size+_map.at(dest);
    _matrix[idx/bits] |= (1 << (idx%bits));
}

template <class T>
bool BitwiseAdjMatrix<T>::isEdge(T src, T dest) const {
    int bits = sizeof(int)*8;
    int idx = _map.at(src)*_size+_map.at(dest);
    return _matrix[idx/bits] & (1 << (idx%bits));
}