//
//  facade.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/2.
//

#ifndef design_pattern_facade_h
#define design_pattern_facade_h
#include <iostream>
namespace facade {
//车辆接口
class VehiclePart{
public:
    virtual ~VehiclePart(){
        
    }
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};





//车辆发动机
class Engine:VehiclePart{
public:
    void start() override{
        std::cout<<"engine start"<<std::endl;
    }
    void stop() override{
        std::cout<<"engine stop"<<std::endl;
    }
};

//车辆变速箱
class Transmission:VehiclePart{
public:
    void start() override{
        std::cout<<"transmission start"<<std::endl;
    }
    void stop() override{
        std::cout<<"transmission stop"<<std::endl;
    }
    
    //加速
    void speedUp(){
        std::cout<<"transmission speed up"<<std::endl;
    }
    //减速
    void slowDown(){
        std::cout<<"transmission slow down'"<<std::endl;
    }
};

//车机
class HeadUnit:VehiclePart{
public:
    void start() override{
        std::cout<<"hu start"<<std::endl;
    }
    void stop() override{
        std::cout<<"hu stop"<<std::endl;
    }
};

//ecu车辆控制单元
class ElectronicControlUnit:VehiclePart{
public:
    void start() override{
        std::cout<<"ecu start"<<std::endl;
    }
    void stop() override{
        std::cout<<"ecu stop"<<std::endl;
    }
};

//传感器
class Sensor:VehiclePart{
public:
    void start() override{
        std::cout<<"sensor start"<<std::endl;
    }
    void stop() override{
        std::cout<<"sensor stop"<<std::endl;
    }
};


//车辆总体
class Vehicle{
public:
    Vehicle(){
    }
public:
    void start() {
        std::cout<<"vehcile start"<<std::endl;
        engine.start();
        transmission.start();
        hu.start();
        ecu.start();
        sensor.start();
    }
    void stop() {
        std::cout<<"vehcile stop"<<std::endl;
        sensor.stop();
        ecu.stop();
        hu.stop();
        transmission.stop();
        engine.stop();
 
    }
    void speedUp(){
        std::cout<<"vehcile speed up"<<std::endl;
        transmission.speedUp();
    }
    void slowDown(){
        std::cout<<"vehcile slow down"<<std::endl;
        transmission.slowDown();
    }
private:
    Engine engine;
    Transmission transmission;
    HeadUnit hu;
    ElectronicControlUnit ecu;
    Sensor sensor;
};


}
#endif /* facade_h */
