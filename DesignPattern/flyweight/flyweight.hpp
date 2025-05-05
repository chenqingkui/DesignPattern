//
//  flyweight.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/4.
//

#ifndef design_pattern_flyweight_h
#define design_pattern_flyweight_h
#include <unordered_map>
namespace flyweight {

//享元模式
//轮胎
class Tyre{
public:
    virtual ~Tyre(){
        
    }
public:
    Tyre(const std::string& brand,int size){
        this->brand = brand;
        this->size = size;
    }
public:
    virtual void move() = 0;
private:
    std::string brand; //品牌
    int size; //尺寸
};

//车辆轮胎
class FlyweightTyre:public Tyre{
public:
    FlyweightTyre(const std::string& brand,int size):Tyre(brand,size){
        
    }
    ~FlyweightTyre(){
    }
public:
    void move(){
        std::cout << "this:" << this << " moving" << std::endl;
    }
};


//车辆轮胎组装车间
class FlyweightTyreRoom{
public:
    FlyweightTyreRoom(){
       
    }
    ~FlyweightTyreRoom(){
        for (auto& tyreMap1:tyres){
            for (auto& tyre : tyreMap1.second){
                delete tyre.second;
            }
        }
    }
public:
    FlyweightTyre* getFlyweightTyre(const std::string& brand,int size){
        FlyweightTyre* flyTyre = nullptr;
        if(!tyres.count(brand)){
            std::unordered_map<int,FlyweightTyre*> mapSize;
            flyTyre = new FlyweightTyre(brand,size);
            mapSize[size] = flyTyre;
            tyres[brand] = mapSize;
        }else
        {
            if(tyres[brand].count(size)){
                flyTyre = tyres[brand][size];
            }else{
                flyTyre = new FlyweightTyre(brand,size);
                tyres[brand][size] = flyTyre;
            }
        }
        std::cout<<"flyweight tyre:"<<flyTyre<<std::endl;
        return flyTyre;
    }
private:
    std::unordered_map<std::string,std::unordered_map<int,FlyweightTyre*>> tyres;
};

}
#endif /* flyweight_h */
