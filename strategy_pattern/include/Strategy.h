#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include <memory>

//test the Strategy pattern
//use different derived class to achieve the
//function of the base class

//to define different derived class
enum SY{ SA,SB,SC};

class Strategy
{
    public:
        virtual void print() = 0;
        Strategy();
        virtual ~Strategy();
    private:
};

class StrategyA : public Strategy
{
public:
    void print()
    {
        std::cout << "SA" << std::endl;
    }
};

class StrategyB : public Strategy
{
public:
    void print()
    {
        std::cout << "SB" << std::endl;
    }
};

class StrategyC : public Strategy
{
public:
    void print()
    {
        std::cout << "SC" << std::endl;
    }
};

class Context
{
private:
    std::shared_ptr<Strategy> strategy;
public:
    Context(SY sy)
    {
        if(sy == SA)
        {
            strategy = std::make_shared<StrategyA>();
        }
        else if(sy == SB)
        {
            strategy = std::make_shared<StrategyB>();
        }
        else
        {
            strategy = std::make_shared<StrategyC>();
        }
    }
    void doPrint()
    {
        strategy->print();
    }
};

#endif // STRATEGY_H
