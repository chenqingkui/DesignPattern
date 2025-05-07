//
//  mediate.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/7.
//

#ifndef design_pattern_mediate_h
#define design_pattern_mediate_h

namespace  mediate{
//中介者模式
//
//+------------------------------+          +---------------------+
//|     <<interface>>            |          |     <<interface>>   |
//|       Trader                 |<-------->|      Mediator       |
//+---------------------         +          +---------------------+
//| +deal(): void                |          | +deal(): void       |
//| +send(): void                |          | +chat(Trader*): void|
//| +receive(): void             |          +----------^---------+
//| +setMediator(Mediator*): void|                   |
//+----------^-------------------+                   |
//           |                                       |
// +---------+-----------+                    +---------+---------+
// |                     |                    |                   |
// |   VehicleBuyer      |                    |  VehicleMediator  |
// +---------------------+                    +-------------------+
// | -mediator: Mediator*|                    | -buyer: Trader*   |
// +---------------------+                    | -seller: Trader*  |
//           |                                +-------------------+
//           |
//           |
// +---------+-----------+
// |                     |
// |  VehicleSeller      |
// +---------------------+
// | -mediator: Mediator*|
// +---------------------+
                                        

class Mediator;
//交易人
class Trader{
public:
    ~Trader(){
        
    }
public:
    virtual void deal()  = 0;
    virtual void send()  = 0;
    virtual void receive()  = 0;
    virtual void setMediator(Mediator* mediator) = 0;
};
//中介接口类
class Mediator{
public:
    virtual ~Mediator(){
        
    }
public:
    virtual void deal() = 0;
    virtual void chat(Trader* trader) = 0;
};



//卖家
class VehicleSeller:public Trader{
public:
    void deal() override{
        std::cout << "sell vehicle"<<std::endl;
    }
    void send() override{
        std::cout<<"seller send"<<std::endl;
        if(mediator != nullptr){
            mediator->chat(this);
        }
    }
    void receive() override{
        std::cout<<"seller receive"<<std::endl;
    }

    void setMediator(Mediator* mediator) override{
        this->mediator = mediator;
    }
private:
    Mediator* mediator;
};

//买家
class VehicleBuyer:public Trader{
public:
    void deal() override{
        std::cout << "buy vehicle"<<std::endl;
    }
    void send() override{
        std::cout<<"buyer send"<<std::endl;
        if(mediator != nullptr){
            mediator->chat(this);
        }
    }
    void receive() override{
        std::cout<<"buyer receive"<<std::endl;
    }
    void setMediator(Mediator* mediator) override{
        this->mediator = mediator;
    }
private:
    Mediator* mediator;
};


//中介
class VehicleMediator : public Mediator{
public:
    VehicleMediator(Trader* buyer,Trader* seller){
        this->buyer = buyer;
        this->seller = seller;
    }
public:
    void deal() override{
        std::cout<<"vehicle mediator deal begin" << std::endl;
        seller->deal();
        buyer->deal();
        std::cout<<"vehicle mediator deal end" << std::endl;
    }
    void chat(Trader* trader) override{
        std::cout<<"vehicle mediator chat" << std::endl;
        if(trader == buyer){
            seller->receive();
        }else if(trader == seller){
            buyer->receive();
        }
    }
private:
    Trader* buyer{nullptr};
    Trader* seller{nullptr};
};




}

#endif /* mediate_h */
