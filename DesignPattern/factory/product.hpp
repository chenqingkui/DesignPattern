#ifndef design_pattern_product_hpp
#define design_pattern_product_hpp

#include <iostream>
namespace factory {
    using namespace std;

    #define CLASS_NAME(name) #name

    //车辆
    class Vehicle{
    public:
        virtual ~Vehicle(){
            
        }
        virtual void driving(){
            cout << "moving" << endl;
        }
        virtual void brake(){
            cout << "brake" << endl;
        }
    };

    //小汽车
    class Car: public Vehicle{
    public:
        void driving() override{
            cout << CLASS_NAME(Car) << " "  << "moving" << endl;
        }
        void brake() override{
            cout << CLASS_NAME(Car)<< " "  << "brake" << endl;
        }
    };

    //suv(越野车)
    class Suv : public Vehicle{
    public:
        void driving() override{
            cout << CLASS_NAME(Suv) << " "  << "moving" << endl;
        }
        void brake() override{
            cout << CLASS_NAME(Suv) << " "  << "brake" << endl;
        }
    };

    //皮卡车
    class PickupTruck:public Vehicle{
    public:
        void driving() override{
            cout << CLASS_NAME(PickupTruck)  << " " << "moving" << endl;
        }
        void brake() override{
            cout << CLASS_NAME(PickupTruck) << " " << "brake" << endl;
        }
    };


    //车辆类型
    enum class VehicleType{
        Car = 0, //小汽车
        Suv = 1, //越野车
        PickupTruck = 2, //越野车
    };



    //小汽车(电动)
    class ElectricalCar: public Car{
    public:
        void driving() override{
            cout << CLASS_NAME(ElectricalCar) << " "  << "moving" << endl;
        }
        void brake() override{
            cout << CLASS_NAME(ElectricalCar)<< " "  << "brake" << endl;
        }
    };

    //suv(越野车)(电动)
    class ElectricalSuv : public Vehicle{
    public:
        void driving() override{
            cout << CLASS_NAME(ElectricalSuv) << " "  << "moving" << endl;
        }
        void brake() override{
            cout << CLASS_NAME(ElectricalSuv) << " "  << "brake" << endl;
        }
    };

    //皮卡车(电动)
    class ElectricalPickupTruck:public Vehicle{
    public:
        void driving() override{
            cout << CLASS_NAME(ElectricalPickupTruck)  << " " << "moving" << endl;
        }
        void brake() override{
            cout << CLASS_NAME(ElectricalPickupTruck) << " " << "brake" << endl;
        }
    };


    //小汽车(燃油)
    class FuelCar: public Car{
    public:
        void driving() override{
            cout << CLASS_NAME(FuelCar) << " "  << "moving" << endl;
        }
        void brake() override{
            cout << CLASS_NAME(FuelCar)<< " "  << "brake" << endl;
        }
    };

    //suv(越野车)(燃油)
    class FuelSuv : public Vehicle{
    public:
        void driving() override{
            cout << CLASS_NAME(FuelSuv) << " "  << "moving" << endl;
        }
        void brake() override{
            cout << CLASS_NAME(FuelSuv) << " "  << "brake" << endl;
        }
    };

    //皮卡车(燃油)
    class FuelPickupTruck:public Vehicle{
    public:
        void driving() override{
            cout << CLASS_NAME(FuelPickupTruck)  << " " << "moving" << endl;
        }
        void brake() override{
            cout << CLASS_NAME(FuelPickupTruck) << " " << "brake" << endl;
        }
    };
}

#endif

