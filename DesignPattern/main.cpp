//
//  main.cpp
//  DesignPattern
//
//  Created by let'sgo on 2025/4/29.
//

#include <iostream>
#include "factory/factory.hpp"
#include "factory/factory_method.hpp"
#include "factory/abstract_factory.hpp"
#include "single/single.hpp"
#include "observer/observer.hpp"
#include "iterator/iterator.hpp"
#include "facade/facade.hpp"
#include "builder/builder.hpp"
#include "adapter/adapter.hpp"
#include "memorandum/memorandum.hpp"
#include "flyweight/flyweight.hpp"
#include "decorator/decorator.hpp"
#include "chain/chain.hpp"
int main(int argc, const char * argv[]) {

    //简单工厂
    factory::Factory f;
    factory::Vehicle* v= f.product(factory::VehicleType::PickupTruck);
    v->driving();
    v->brake();
    delete v;
    

    
    //工厂方法(工厂只创建一个单类产品，容易工厂数量膨胀
    factory::MethodFactory* mf = new factory::CarFactory();
    v = mf->product();
    v->driving();
    v->brake();
    delete v;
    
    delete mf;
    
    
    //抽象工厂
    //电车工厂，按一类产品设立工厂(如电车)
    factory::AbstractFactory* af = new factory::ElectricalFactory();
    v = af->productSuv();
    v->driving();
    v->brake();
    delete v;
    //燃油车工厂,按一类产品设立工厂(如油车)
    af = new factory::FuelFactory();
    v = af->productCar();
    v->driving();
    v->brake();
    delete v;
    
    delete af;
    
    
    //单例模式
    single::Single* sIns = single::Single::getInstance();
    sIns->call();
    single::Single11& sIns11 = single::Single11::getInstance();
    sIns11.call();
    
    

    //观察者模式
    //观察者临时类
    class TestOber:public observer::Notifyer{
    public:
        void notify(const char* msg) override{
            std::cout<<msg<<std::endl;
        }
    };
    
    observer::VehicleCorp vCorp;
    TestOber* ober = new TestOber();
    //下单
    vCorp.confirmOrder(ober);
    //通知
    vCorp.notify("car is ready");
    //取消订单
    vCorp.cancelOrder(ober);
    delete ober;
    
    
    //迭代器模式(模板实现，获取get()功能)
    Iterator::ConcreteAggerate<Iterator::VehicleProcess> vpAgg;
    vpAgg.push_back(Iterator::VehicleProcess(Iterator::VehicleProcessType::SubmitOrder));
    vpAgg.push_back(Iterator::VehicleProcess(Iterator::VehicleProcessType::MakePlan));
    vpAgg.push_back(Iterator::VehicleProcess(Iterator::VehicleProcessType::Producting));
    vpAgg.push_back(Iterator::VehicleProcess(Iterator::VehicleProcessType::Testing));
    vpAgg.push_back(Iterator::VehicleProcess(Iterator::VehicleProcessType::Delivery));
    vpAgg.push_back(Iterator::VehicleProcess(Iterator::VehicleProcessType::ArriveSales));

    //迭代器初始化
    Iterator::Iterator<Iterator::VehicleProcess>* vpIter = vpAgg.getIterator();
    while(vpIter->hasNext()){
        vpIter->get();
        vpIter->next();
    }
    
    
    //facade模式(复杂系统统一对外控制接口，解藕外部与内部系统的依赖关系，内部关系facde类来进行控制)
    facade::Vehicle faVeh;
    faVeh.start();
    faVeh.speedUp();
    faVeh.slowDown();
    faVeh.stop();
    
    
    
    //建造者模式
    builder::Vehicle* buildVehicle = nullptr;
    //油车建造者，构建油车构建者传入不一样的参数，参数也可以通过set进行设置，这样的话可以建造者设置多批次车辆生产

    builder::FuelBuilder fuelBuilder(15,820);
    //油车建造指挥者
    builder::Director fuelDirector(&fuelBuilder);
    buildVehicle = fuelDirector.build();
    delete buildVehicle;
    //电车建造模式
    //构建电车构建者传入不一样的参数，参数也可以通过set进行设置，这样的话可以建造者设置多批次车辆生产
    builder::ElectronicBuilder electronicBuilder(100,200,8155);
    //电车建造指挥者
    builder::Director electronicDirector(&electronicBuilder);
    buildVehicle = electronicDirector.build();
    delete buildVehicle;
    
    

    //适配器模式(祼指针模式)
//    adapter::Camera* yuvCamera = new adapter::YUVCamera();
//    adapter::Parser yuvParser(yuvCamera);
//    adapter::Image* yuvImage = yuvParser.getImage();
//    adapter::Camera* rgbCamera = new adapter::RGBCamera();
//    delete yuvCamera;
//    delete yuvImage;
//    yuvParser.setCamera(rgbCamera);
//    adapter::Adapter* adapter = new adapter::RGBAdapter();
//    yuvParser.setAdapter(adapter);
//    yuvImage  = yuvParser.getImage();
//    delete adapter;
//    delete rgbCamera;

    
    auto yuvCamera = std::make_unique<adapter::YUVCamera>();
    adapter::Parser yuvParser(std::move(yuvCamera));
    auto yuvImage = yuvParser.getImage();

    auto rgbCamera = std::make_unique<adapter::RGBCamera>();

    yuvParser.setCamera(std::move(rgbCamera));
    auto adapter = std::make_unique<adapter::RGBAdapter>();
    yuvParser.setAdapter(std::move(adapter));
    yuvImage  = yuvParser.getImage();



    //备忘录模式
    //备忘录发起者
    memorandum::MusicPlayer musicPlayer;
    musicPlayer.setSong("jj");
    musicPlayer.setRatio(0.5f);
    //备忘录管理者
    memorandum::MusicPlayerCaretaker musicCaretaker;
    //存储memo
    musicCaretaker.setContext(musicPlayer.save()); //save返回备忘录，根据MusicPlayer定制的PlayerContext
    
    musicPlayer.setSong("jj-1"); //测试修改
    musicPlayer.setRatio(0.8f);  //测试修改
    //加载memo
    musicPlayer.load(musicCaretaker.getContext()); //load后还原为保存时刻的信息
    
    musicCaretaker.setContext(nullptr); //context置空
    delete musicCaretaker.getContext(); //释放内存
 
    
    
    //享元模式
    //车辆安装轮胎，多组轮胎，品牌和大小一致，一组创建一个实例
    //get出来的不用释放，由享元工厂释放
    flyweight::FlyweightTyreRoom room; //轮胎车间
    flyweight::FlyweightTyre* leftUp = room.getFlyweightTyre("good",19);
    flyweight::FlyweightTyre* rightUp = room.getFlyweightTyre("good",19);
    flyweight::FlyweightTyre* leftDown = room.getFlyweightTyre("good",19);
    flyweight::FlyweightTyre* rightDown = room.getFlyweightTyre("good",19);
    
    leftUp->move();    //get出来无需释放，由享元工厂释放
    rightUp->move();
    leftDown->move();
    rightDown->move();
    
    
    //装饰者模式
    decorator::CarSeat* carSeat =  new decorator::CarSeat("nappa",1,1000);
    decorator::HeatedSeat decorHeat(carSeat,500);
    //座椅加热
    decorHeat.sit();
    decorHeat.getCost();
    decorator::VentilatedSeat decorVSeat(&decorHeat,800);
    //座椅通风
    decorVSeat.sit();
    decorVSeat.getCost();
    delete carSeat;
    
    
    //职责链模式
    chain::Chain* afterSales = new chain::AfterSales();
    chain::Chain* engineer = new chain::Engineer();
    chain::Chain* manager = new chain::Manager();
    chain::Chain* president = new chain::President();

    afterSales->setNext(engineer);
    engineer->setNext(manager);
    manager->setNext(president);
    
    afterSales->deal("crash 1000 times;");
    delete afterSales;
    return 0;
}

