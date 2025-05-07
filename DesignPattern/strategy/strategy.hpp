//
//  strategy.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/7.
//

#ifndef design_pattern_strategy_h
#define design_pattern_strategy_h

namespace strategy{
//
//            +---------------------+              +---------------------+
//            |     <<interface>>   |              |    SalesPromotion   |
//            |      Strategy       |              +---------------------+
//            +---------------------+              | -strategy: Strategy*|
//            | +discount(): int    |<-----------  +---------------------+
//            +---------------------+              | +setStrategy(Strategy*)|
//               ^              ^                  | +getDiscount(): int   |
//               |              |                  +---------------------+
//               |              |
//+------+---+----------+    +------+-----------+
//|                     |    |                  |
//| Top100OrderStrategy |    | Deposit3W        |
//+---------------------+    +------------------+
//| +discount(): int    |    | +discount(): int |
//|   return 50000;     |    |   return 30000;  |
//+---------------------+    +------------------+

//策略模式
class Strategy{
public:
    virtual ~Strategy(){
        
    }
public:
    virtual int discount() = 0;
};


//前100名下单
class Top100OrderStrategy:public Strategy{
public:
    int discount()override{
        return 50000;
    }

};


//订金1W减3W
class Deposit3W:public Strategy{
public:
    int discount()override{
        return 30000;
    }
};


//销售活动
class SalesPromotion{
    
public:
    void setStrategy(Strategy* strategy){
        this->strategy = strategy;
    }
    int getDiscount() {
        if(strategy == nullptr){
            return 0;
        }
        int discountVal =  strategy->discount();
        std::cout<<"discount:"<<discountVal<<std::endl;
        return discountVal;
    }
private:
    Strategy* strategy {nullptr};
};



}

#endif /* strategy_h */
