#include <catch2/catch_test_macros.hpp>

#include "bitwiseAdjMatrix.h"

#include <string>

using std::string;

template <class T>
size_t find(const vector<T> & v, T t) {
    size_t idx;
    for (idx = 0; idx < v.size(); ++idx) if (v[idx] == t) break;
    return idx;
}

template <class T>
void test_adjMatrix(const vector<pair<T, T>> & v) {
    vector<T> vertices;
    for (const pair<T, T> & p : v) {
        if (find(vertices, p.first) == vertices.size()) vertices.push_back(p.first);
        if (find(vertices, p.second) == vertices.size()) vertices.push_back(p.second);
    }

    BitwiseAdjMatrix<T> m = BitwiseAdjMatrix(v);
    for (const T & src : vertices) for (const T & dest : vertices) {
            if (m.isEdge(src, dest)) REQUIRE(find(v, {src, dest}) != v.size());
            else REQUIRE(find(v, {src, dest}) == v.size());
    }
}

TEST_CASE("int test", "weight = 1") {
    vector<pair<int, int>> v = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {5, 4}};
    test_adjMatrix(v);
}

TEST_CASE("str test", "weight = 1") {
    vector<pair<string, string>> v = {{"a", "b"}, {"a", "c"}, {"a", "d"}, {"b", "e"}, {"a", "f"}, {"f", "e"}};
    test_adjMatrix(v);
}