#include <iostream>
#include <iterator>
#include <string>

template <typename T>
struct ASTNode
{
    std::string type;
    T value;
};

class Parser
{
public:
    auto Program()
    {
        return NumericLiteral();
    }

    auto Parse(const std::string &data)
    {
        this->_source = data;
        return this->Program();
    }

    ASTNode<int> NumericLiteral()
    {
        auto a = ASTNode<int>();
        a.type = "NumericLiteral";
        a.value = std::stoi(this->_source);
        return a;
    };

    void PrintASTNode(ASTNode<int> &node)
    {
        std::cout << "{ \nType: " << node.type << std::endl << "Value: " << node.value << std::endl << "}" << std::endl;
    };

private:
    std::string _source;
};