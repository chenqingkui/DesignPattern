//
//  prototype.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/6.
//

#ifndef design_pattern_prototype_h
#define design_pattern_prototype_h
namespace prototype{
//原型模式

//原型
class Prototype{
public:
    virtual ~Prototype(){
    }
public:
    virtual Prototype* clone() = 0;
    virtual void info() = 0;
};

//销售订单
class SalesOrder :public Prototype{
public:
    SalesOrder(int64_t orderTime,const std::string& name,const std::string phone,int type){
        this->type = new int;
        submitTime = orderTime;
        this->name = name;
        this->phone = phone;
        *(this->type) = type;
    }
    SalesOrder& operator = (const SalesOrder& order){
        if(this == &order){
            return *this;
        }
        this->submitTime = order.submitTime;
        this->name = order.name;
        this->phone = order.phone;
        if(this->type != nullptr){
            delete this->type;
        }
        this->type = new int;
        if(order.type != nullptr)
        {
            *type = *order.type;
        }
        return *this;
    }
    SalesOrder(const SalesOrder& order){
        submitTime = order.submitTime;
        name = order.name;
        phone = order.phone;
        if(type != nullptr){
            delete type;
        }
        type = new int;
        if(order.type != nullptr)
        {
            *type = *order.type;
        }
    }
    ~SalesOrder(){
        if(type != nullptr){
            delete type;
        }
    }
public:
    Prototype* clone(){
        SalesOrder* order = new SalesOrder(*this);
        return order;
    }
   void info(){
       std::cout<<"time:"<<submitTime<<" name:"<<name <<" phone:"<<phone<<" type:" << type <<" *type:"<<((type != nullptr)?(*type):0)<<std::endl;
    }
private:
    int64_t submitTime {0};  //下单时间
    std::string name;    //姓名
    std::string phone;   //联系电话
    int* type{nullptr};  //型号
};



}



#endif /* prototype_h */
