#ifndef design_pattern_product_hpp
#define design_pattern_product_hpp

#include <iostream>
namespace factory {

    #define CLASS_NAME(name) #name

    //车辆
    class Vehicle{
    public:
        virtual ~Vehicle(){
            
        }
        virtual void driving(){
            std::cout << "moving" << std::endl;
        }
        virtual void brake(){
            std::cout << "brake" << std::endl;
        }
    };

    //小汽车
    class Car: public Vehicle{
    public:
        void driving() override{
            std::cout << CLASS_NAME(Car) << " "  << "moving" << std::endl;
        }
        void brake() override{
            std::cout << CLASS_NAME(Car)<< " "  << "brake" << std::endl;
        }
    };

    //suv(越野车)
    class Suv : public Vehicle{
    public:
        void driving() override{
            std::cout << CLASS_NAME(Suv) << " "  << "moving" << std::endl;
        }
        void brake() override{
            std::cout << CLASS_NAME(Suv) << " "  << "brake" << std::endl;
        }
    };

    //皮卡车
    class PickupTruck:public Vehicle{
    public:
        void driving() override{
            std::cout << CLASS_NAME(PickupTruck)  << " " << "moving" << std::endl;
        }
        void brake() override{
            std::cout << CLASS_NAME(PickupTruck) << " " << "brake" << std::endl;
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
            std::cout << CLASS_NAME(ElectricalCar) << " "  << "moving" << std::endl;
        }
        void brake() override{
            std::cout << CLASS_NAME(ElectricalCar)<< " "  << "brake" << std::endl;
        }
    };

    //suv(越野车)(电动)
    class ElectricalSuv : public Vehicle{
    public:
        void driving() override{
            std::cout << CLASS_NAME(ElectricalSuv) << " "  << "moving" << std::endl;
        }
        void brake() override{
            std::cout << CLASS_NAME(ElectricalSuv) << " "  << "brake" << std::endl;
        }
    };

    //皮卡车(电动)
    class ElectricalPickupTruck:public Vehicle{
    public:
        void driving() override{
            std::cout << CLASS_NAME(ElectricalPickupTruck)  << " " << "moving" << std::endl;
        }
        void brake() override{
            std::cout << CLASS_NAME(ElectricalPickupTruck) << " " << "brake" << std::endl;
        }
    };


    //小汽车(燃油)
    class FuelCar: public Car{
    public:
        void driving() override{
            std::cout << CLASS_NAME(FuelCar) << " "  << "moving" << std::endl;
        }
        void brake() override{
            std::cout << CLASS_NAME(FuelCar)<< " "  << "brake" << std::endl;
        }
    };

    //suv(越野车)(燃油)
    class FuelSuv : public Vehicle{
    public:
        void driving() override{
            std::cout << CLASS_NAME(FuelSuv) << " "  << "moving" << std::endl;
        }
        void brake() override{
            std::cout << CLASS_NAME(FuelSuv) << " "  << "brake" << std::endl;
        }
    };

    //皮卡车(燃油)
    class FuelPickupTruck:public Vehicle{
    public:
        void driving() override{
            std::cout << CLASS_NAME(FuelPickupTruck)  << " " << "moving" << std::endl;
        }
        void brake() override{
            std::cout << CLASS_NAME(FuelPickupTruck) << " " << "brake" << std::endl;
        }
    };
}

#endif

