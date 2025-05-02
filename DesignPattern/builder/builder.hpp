//
//  builder.h
//  DesignPattern
//
//  Created by let'sgo on 2025/5/2.
//

#ifndef design_pattern_builder_h
#define design_pattern_builder_h
namespace builder{



//部件
class VehiclePart{
public:
    virtual ~VehiclePart(){
        
    }
public:
    virtual void install() = 0;
};


//引擎
class Engine :public VehiclePart{
public:
    Engine(int power){
        this->power = power;
    }
public:
    void install() override
    {
        std::cout<<"engine install "<< "power:" << power << std::endl;
    }
private:
    int power{0};
};

//变速箱
class Transmission:public VehiclePart{
public:
    void install() override
    {
        std::cout<<"Transmission install"<<std::endl;
    }
};


//电池
class Battery:public VehiclePart{
public:
    Battery(int kwh){
        this->kwh = kwh;
    }
public:
    void install() override
    {
        std::cout<<"batery install "<< "kwh:" << kwh << std::endl;
    }
private:
    int kwh{0};
};

//电机
class ElectronicMotor :public VehiclePart{
public:
    ElectronicMotor(int power){
        this->power = power;
    }
public:
    void install() override
    {
        std::cout<<"electronic motor install "<< "power:" << power << std::endl;
    }
private:
    int power{0};
};


//底盘
class Chassis:public VehiclePart{
public:
    void install() override
    {
        std::cout<<"Chassis install"<<std::endl;
    }
};


//车机
class HeadUnit:public VehiclePart{
public:
    HeadUnit(int cpu){
        this->cpu = cpu;
    }
public:
    void install() override
    {
        std::cout<<"HeadUnit install"<<std::endl;
    }
private:
    int cpu {0};
};


//建造者
class Vehicle{
public:
    ~Vehicle(){
        for(auto part:parts){
            delete part;
        }
    }
public:
    Vehicle* install(VehiclePart* part){
        part->install();
        parts.push_back(part);
        return this;
    }
private:
    std::vector<VehiclePart*> parts;
};


//builder
class Builder{
public:
    virtual Vehicle* build() = 0;

};

//油车建造者
class FuelBuilder:public Builder{
public:
    FuelBuilder(int power,int cpu){
        this->power = power;
        this->cpu = cpu;
    }
public:
    Vehicle* build() override{
        std::cout <<"build fuel vehicle" <<std::endl;
        Vehicle* vehicle = new Vehicle();
        
        Engine* engine = new Engine(power);
        //安装发动机
        vehicle->install(engine);
        
        Transmission* transmission = new Transmission();
        //安装变速箱
        vehicle->install(transmission);
        
        Chassis* chassis = new Chassis();
        //安装底盘
        vehicle->install(chassis);
        
        HeadUnit* hu = new HeadUnit(cpu);
        //安装车机
        vehicle->install(hu);
        
        return vehicle;
    }
private:
    int power {0};
    int cpu {0};

};

//电车建造者
class ElectronicBuilder :public Builder{
public:
    ElectronicBuilder(int kwh,int power,int cpu){
        this->kwh = kwh;
        this->power = power;
        this->cpu = cpu;
    }
public:
            
    Vehicle* build() override{
        std::cout<<"build electrionic vehicle"<<std::endl;
        Vehicle* vehicle = new Vehicle();
        
        Battery* engine = new Battery(kwh);
        //安装电池
        vehicle->install(engine);
        
        ElectronicMotor* motor = new ElectronicMotor(kwh);
        //安装电机
        vehicle->install(motor);
        
        //安装底盘
        Chassis* chassis = new Chassis();
        vehicle->install(chassis);
        
        //安装车机
        HeadUnit* hu = new HeadUnit(cpu);
        vehicle->install(hu);
        
        return vehicle;
    }
private:
    int kwh {0};//电池包容量
    int power {0}; //电机功率
    int cpu {0}; //cpu型号
};


//导演(指挥者)
class Director{
public:
    Director(Builder* builder){
        this->builder = builder;
    }
    Vehicle* build(){
        if(builder == nullptr){
            return nullptr;
        }
        return builder->build();
    }
private:
        Builder* builder{nullptr}; //建造者
        
};

}
#endif /* builder_h */
