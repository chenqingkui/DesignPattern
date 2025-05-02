//
//  facade.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/2.
//

#ifndef design_pattern_facade_h
#define design_pattern_facade_h
namespace facade {
using namespace std;
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
        cout<<"engine start"<<endl;
    }
    void stop() override{
        cout<<"engine stop"<<endl;
    }
};

//车辆变速箱
class Transmission:VehiclePart{
public:
    void start() override{
        cout<<"transmission start"<<endl;
    }
    void stop() override{
        cout<<"transmission stop"<<endl;
    }
    
    //加速
    void speedUp(){
        cout<<"transmission speed up"<<endl;
    }
    //减速
    void slowDown(){
        cout<<"transmission slow down'"<<endl;
    }
};

//车机
class HeadUnit:VehiclePart{
public:
    void start() override{
        cout<<"hu start"<<endl;
    }
    void stop() override{
        cout<<"hu stop"<<endl;
    }
};

//ecu车辆控制单元
class ElectronicControlUnit:VehiclePart{
public:
    void start() override{
        cout<<"ecu start"<<endl;
    }
    void stop() override{
        cout<<"ecu stop"<<endl;
    }
};

//传感器
class Sensor:VehiclePart{
public:
    void start() override{
        cout<<"sensor start"<<endl;
    }
    void stop() override{
        cout<<"sensor stop"<<endl;
    }
};


//车辆总体
class Vehicle{
public:
    Vehicle(){
    }
public:
    void start() {
        cout<<"vehcile start"<<endl;
        engine.start();
        transmission.start();
        hu.start();
        ecu.start();
        sensor.start();
    }
    void stop() {
        cout<<"vehcile stop"<<endl;
        sensor.stop();
        ecu.stop();
        hu.stop();
        transmission.stop();
        engine.stop();
 
    }
    void speedUp(){
        cout<<"vehcile speed up"<<endl;
        transmission.speedUp();
    }
    void slowDown(){
        cout<<"vehcile slow down"<<endl;
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
