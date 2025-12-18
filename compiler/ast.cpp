#include <string>
#include <memory>
#include <vector>

// expr AST - base class for all "EXPRESSION NODES."
class ExprAST {
    public:
        virtual ~ExprAST() = default;
};

// expression class for "NUMERIC LITERALS", such as "PI."
// it captures the numeric value of the double literal as an instance variable.
class NumberExprAST : public ExprAST {
    double val;

    public:
        NumberExprAST(double val) : val(val) {}
};

// expression class for "VARIABLES". such as "o."
class VariableExprAST : public ExprAST {
    std::string name;

    public:
        VariableExprAST(const std::string &name) : name(name) {}
};

// abstract syntax tree class for a "BINARY EXPRESSION."
class BinaryExprAST : public ExprAST {
    char op;

    std::unique_ptr<ExprAST> LHS, RHS;

    public:
        BinaryExprAST(char op, std::unique_ptr<ExprAST> LHS, std::unique_ptr<ExprAST> RHS) :
            op(op),
            LHS(std::move(LHS)), // we use std::move because a unique_ptr cannot be copied, it must be moved.
            RHS(std::move(RHS)) // we use std::move because a unique_ptr cannot be copied, it must be moved. 
        {}
};

// abstract syntax tree for a "FUNCTION CALL."
class CallExprAST : public ExprAST {
    std::string callee;
    std::vector<std::unique_ptr<ExprAST>> args;

    public:
        CallExprAST(const std::string &callee, std::vector<std::unique_ptr<ExprAST>> args) :
            callee(callee),
            args(std::move(args))
        {}
};

// protype AST.
// which will represent the PROTOTYPE of a function. this will capture the name, arguments, argument names,
// (thus implicitly the number of arguments the function takes)

class PrototypeAST : public ExprAST {
    std::string name;
    std::vector<std::string> args;

    public:
        PrototypeAST(const std::string &name, std::vector<std::string> args):
            name(name),
            args(std::move(args))
        {}

        const std::string &get_name() const {
            return name;
        }
};