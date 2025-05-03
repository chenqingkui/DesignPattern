//
//  iterator.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/1.
//

#ifndef design_pattern_iterator_h
#define design_pattern_iterator_h
#include <vector>
#include <iostream>

//迭代器模式
namespace Iterator{

//车辆生产流程类型
enum class VehicleProcessType{
    Unknown = 0,//未知
    SubmitOrder = 1 ,//下单
    MakePlan = 2,//排产
    Producting = 3, //生产中
    Testing = 4,//测试中
    Delivery =5 , //运输中
    ArriveSales = 6,//到店
};

//车辆处理流程
class VehicleProcess{
public:
    VehicleProcess(){
        this->type = VehicleProcessType::Unknown;
    }
    VehicleProcess(VehicleProcessType type){
        this->type = type;
    }
    operator int() const {
        return static_cast<int>(type);
    }
private:
    VehicleProcessType type;
};


//迭代器
template <typename T>
class Iterator{
public:
    
    virtual bool next() = 0;
    virtual bool hasNext() = 0;
    virtual T get() = 0;
};


//具体迭代器
template<typename T>
class ConcreteIterator :public Iterator<T>{
public:
    ConcreteIterator(const std::vector<T>& elements){
        this->elements = elements;
        this->index =0;
    }
    bool next() override{
        if(elements.empty()){
            std::cout<<"ConcreteIterator::next empty"<<std::endl;
            return false;
        }
        index++;
        std::cout<<"ConcreteIterator::next index:"<<index<<std::endl;
        return true;
    }
    bool hasNext() override{
        if(elements.empty()){
            std::cout<<"ConcreteIterator::hasnext empty"<<std::endl;
            return false;
        }
        if(index >= elements.size()){
            std::cout<<"ConcreteIterator::hasnext overfow"<<std::endl;
            return false;
        }
        std::cout<<"ConcreteIterator::hasnext index "<<index<< " true"<<std::endl;
        return true;
    }
    T get() override{
        if(elements.empty()){
            std::cout<<"ConcreteIterator::get empty" << std::endl;
            return T();
        }
        if(index >= elements.size()){
            std::cout<<"ConcreteIterator::get index overflow" << std::endl;
            return T();
        }
        std::cout<<"ConcreteIterator::get value:"<<elements[index]<<std::endl;
        return elements[index];
    }
private:
    std::vector<T> elements;
    int index{0};
};


//迭代元素集合体
template <typename T>
class Aggerate{
    virtual Iterator<T>* getIterator() = 0;
};


//具体信息集合体
template<typename T>
class ConcreteAggerate : public Aggerate<T>{
public:
    ConcreteAggerate(){
    }
    ~ConcreteAggerate(){
    }
public:
    void push_back(T t){
        elements.push_back(t);
    }
    void pop_back(){
        elements.pop_back();
    }
public:
    Iterator<T>* getIterator() override{
        return new ConcreteIterator<T>(elements);
    }
private:
    std::vector<T> elements;
};

}
#endif /* iterator_h */
