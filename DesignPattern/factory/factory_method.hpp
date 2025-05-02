#ifndef design_pattern_factory_method_hpp
#define design_pattern_factory_method_hpp

#include <iostream>
#include "product.hpp"

namespace factory {
    //工厂方法
    class MethodFactory{
    public:
        MethodFactory(){
            
        }
        virtual ~MethodFactory(){
            
        }
    public:
        virtual Vehicle* product() = 0;
    };
    
    //小汽车工厂
    class CarFactory:public MethodFactory{
    public:
        CarFactory(){
            
        }
        ~CarFactory(){
            
        }
        Vehicle* product() override{
            return new Car();
        }
    };
    
    //SUV工厂
    class SuvFactory:public MethodFactory{
    public:
        SuvFactory(){
            
        }
        ~SuvFactory(){
            
        }
        Vehicle* product() override{
            return new Suv();
        }
    };
    
    //皮卡工厂
    class PickupFactory :public MethodFactory{
    public:
        PickupFactory(){
            
        }
        ~PickupFactory(){
            
        }
        Vehicle* product() override{
            return new PickupTruck();
        }
    };
}
#endif

