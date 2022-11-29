# Syntax in depth
**Subject to change**

Program
: StatementList

Statement
: BlockStatement
| IfStatement
| LoopStatement
| FunctionDeclaration

FunctionDeclaration
: fun Ident Arguments { BlockStatement }
