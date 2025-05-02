#ifndef design_pattern_abstract_factory_hpp
#define design_pattern_abstract_factory_hpp

#include <iostream>
#include "product.hpp"
namespace factory{

    //抽象工厂
    class AbstractFactory{
    public:
        AbstractFactory(){
            
        }
        virtual ~AbstractFactory(){
            
        }
    public:
        virtual Vehicle* productCar() = 0;
        virtual Vehicle* productSuv() = 0;
        virtual Vehicle* productPickupTruck() = 0;
    };

    //电车生产工厂
    class ElectricalFactory:public AbstractFactory{
    public:
        ElectricalFactory(){
            
        }
        ~ElectricalFactory(){
            
        }
        Vehicle* productCar() override{
            return new ElectricalCar();
        }
        Vehicle* productSuv() override{
            return new ElectricalSuv();
        }
        Vehicle* productPickupTruck() override{
            return new ElectricalPickupTruck();
        }
    };


    //油车生产工厂
    class FuelFactory:public AbstractFactory{
    public:
        FuelFactory(){
            
        }
        ~FuelFactory(){
            
        }
        Vehicle* productCar() override{
            return new FuelCar();
        }
        Vehicle* productSuv() override{
            return new FuelSuv();
        }
        Vehicle* productPickupTruck() override{
            return new FuelPickupTruck();
        }
    };
}
#endif

