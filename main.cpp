// bet20 2022
// Not to be taken seriously
// And has a lot of mean-bad-horrible code
// PURPOSE: Learning by doing stuff I enjoy

#include "parser.cpp"
#include <bits/stdc++.h>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <list>
#include <ostream>
#include <sstream>
#include <string>
#include <unordered_map>

enum DataTypes
{
    Number,
    String,
    Bool
};

class Position
{
public:
    int col;
    int row;
    Position(int col, int row)
    {
        this->col = col;
        this->row = row;
    }
    Position()
    {
        this->col = 0;
        this->row = 0;
    }
};

template <typename T>
class Block
{
public:
    T *data;
    Position pos;

    Block(T *data, int col, int row)
    {
        this->data = data;
        this->pos = Position(col, row);
    }

    Block(int data, int col, int row)
    {
        this->data = &data;
        this->pos = Position(col, row);
    }

    Block() = default;

    std::string to_data()
    {
        return " data!";
    }

    std::string address()
    {
        return &data;
    }
};

class NumberInteger : public Block<int>
{

public:
    std::string name = "Integer";
    int data;

    NumberInteger(int value, int col, int row) : Block(&value, col, row)
    {
        name = "Integer";
        data = value;
    }

    NumberInteger() = default;

    // Integer exclusive methods
    double Pow(int power)
    {
        return std::pow(this->data, power);
    };

    int _data()
    {
        return data;
    }
};

std::string loop(int iterations, int i)
{
    if (i >= iterations)
    {
        return "Finished";
    }
    std::cout << i << std::endl;
    i++;
    return loop(iterations, i);
}

std::list<std::string> split(std::string str, char delimiter)
{
    std::stringstream s(str);
    std::string word;
    std::list<std::string> words;
    while (!s.eof())
    {
        std::getline(s, word, delimiter);
        words.push_back(word);
    }
    return words;
}

int main(int argc, char **argv)
{

    std::string line;

    std::cout << ">> ";
    std::cin >> line;

    std::list<std::string> words = split(line, ' ');

    // Test variables
    NumberInteger n1(10, 1, 1);
    NumberInteger n2(20, 1, 2);

    std::unordered_map<std::string, NumberInteger> map;

    map["num1"] = n1;
    map["num2"] = n2;

    // for(auto i = words.begin(); i != words.end(); ++i) {
    //   if (i->find('.')) {
    //     auto w = split(*i, '.');
    //     auto a = map.find(w.begin()->c_str());
    //     if(!a->first.empty()) {
    //       std::cout << map[a->first]._data() << std::endl;
    //     }
    //   }
    // }

    auto p = Parser();
    auto l = p.Parse("45asd");
    p.PrintASTNode(l);

    return 0;
}
