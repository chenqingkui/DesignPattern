#ifndef design_pattern_factory_hpp
#define design_pattern_factory_hpp

#include <iostream>
#include "product.hpp"
namespace factory{

    //工厂
    class Factory{
    public:
        Factory(){
            
        }
        ~Factory(){
            
        }
    public:
        Vehicle* product(VehicleType type){
            switch (type) {
                case VehicleType::Car:
                    return new Car();
                    break;
                case VehicleType::Suv:
                    return new Suv();
                    break;
                case VehicleType::PickupTruck:
                    return new PickupTruck();
                    break;
                default:
                    break;
            }
        }
        
        Vehicle* productCar(){
            return new Car();
        }
        
        Vehicle* productSuv(){
            return new Suv();
        }
        
        Vehicle* productPickupTruck(){
            return new PickupTruck();
        }
    };

}
#endif

