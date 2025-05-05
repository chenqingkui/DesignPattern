//
//  decorator.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/5.
//

#ifndef dessign_pattern_decorator_h
#define dessign_pattern_decorator_h

namespace  decorator {

//座椅
class Seat{
public:
    virtual ~Seat(){
        
    }
public:
    virtual void sit() = 0; //坐
    virtual float getCost(){
        return cost;
    }
protected:
    void setMaterial(const std::string& material){
        this->material = material;
    }
    void setSize(int size){
        this->size = size;
    }
protected:
    std::string material; //材质
    int size; //大小
    float cost; //成本
};

//车辆座椅
class CarSeat:public Seat {
public:
    CarSeat(const std::string& material,int size,int cost){
        this->material = material;
        this->size = size;
        this->cost = cost;
    }
public:
    void sit() override {
        std::cout << "this:" << this << " car sit" << " cost:" << getCost() << std::endl;
    }
};

//装钸者
class SeatDecorator :public Seat {
public:
    SeatDecorator(Seat* seat){
        pSeat = seat;
    }
    virtual ~SeatDecorator(){
        
    }
public:
    void sit() override{
        pSeat->sit();
    }
    float getCost() override{
        return pSeat->getCost();
    }
protected:
    Seat* getSeat(){
        return pSeat;
    }
private:
    Seat* pSeat{nullptr};
};

//座椅加热
class HeatedSeat :public SeatDecorator{
public:
    HeatedSeat(Seat* seat,float cost):SeatDecorator(seat),heatedCost(cost){
    }
public:
    void sit() override{
        SeatDecorator::sit();
        std::cout << "seat:"<< getSeat() << " heating" << std::endl;
    }
    float getCost() override{
        //成本加和
        float totalCost = SeatDecorator::getCost() + heatedCost;
        std::cout<< "seat:" << getSeat() << " cost:" << totalCost << std::endl;
        return totalCost;
    }
private:
    float heatedCost {0.0};
};

//座椅通风
class VentilatedSeat:public SeatDecorator{
public:
    VentilatedSeat(Seat* seat,float cost):SeatDecorator(seat),ventilatedCost(cost){
    }
public:
    void sit() override{
        SeatDecorator::sit();
        std::cout << "seat:"<< getSeat() << " ventilation" << std::endl;
    }
    float getCost() override{
        //成本加和
        float totalCost = SeatDecorator::getCost() + ventilatedCost;
        std::cout<< "seat:" << getSeat() << " cost:" << totalCost << std::endl;
        return totalCost;
    }
private:
    float ventilatedCost {0.0};
};


}

#endif /* decorator_h */
