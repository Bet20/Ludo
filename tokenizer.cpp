#include "parser.cpp"
#include <cmath>
#include <cstddef>
#include <ctype.h>
#include <string>
#include <valarray>

bool is_integer(float k)
{
    return std::floor(k) == k;
}

class Tokenizer
{

public:
    Tokenizer(std::string &source)
    {
        this->_source = source;
        this->_cursor = 0;
    }
    bool HasMoreToken()
    {
        return (this->_source.size() > _cursor);
    }
    template <typename T>
    auto GetNextToken()
    {
        auto ret = ASTNode<T>;
        if (!this->HasMoreToken())
        {
            ret.type = "EOF";
            ret.value = -1;
            return ret;
        };

        auto ch = this->_source.substr(this->_cursor, this->_source.size() - this->_cursor);

        if (is_integer(ch[0]))
        {
            auto number = "";
            while (is_integer(ch[this->_cursor]))
            {
                number += ch[this->_cursor++];
            }
            ret.type = "IntegerLiteral";
            ret.value = std::stoi(number);
            return ret;
        };

        if (isalpha(ch[0]))
        {
            auto chr = "";
            while (isalpha(ch[this->_cursor]))
            {
                chr += ch[this->_cursor++];
            }
            ret.type = "StringLiteral";
            ret.value = chr;
        }

        if (ch[0] == '{')
        {
        };
        if (ch[0] == '}')
        {
        };
        if (ch[0] == '_')
        {
        };
        if (ch[0] == ' ')
        {
        }
        return ret;
    };

private:
    std::string _source;
    int _cursor;
};