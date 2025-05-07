//
//  proxy.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/7.
//

#ifndef design_pattern_proxy_h
#define design_pattern_proxy_h
namespace proxy{
//代理模式

//+---------------------+
//|     <<interface>>   |
//|      Register       |
//+---------------------+
//| +registration():void|
//+----------^----------+
//           |
//   +-------+-----------+
//   |                   |
//+----------------+  +----------------------+
//|Owner           |  |Proxyer               |
//+----------------+  +----------------------+
//| +registration()|  | -principal: Register*|
//+----------------+  +----------------------+


//登记
class Register{
public:
    Register(const std::string& name,const std::string id){
        this->name = name;
        this->id = id;
    }
public:
    ~Register(){
    }
public:
    virtual void registration() = 0;
protected:
    std::string name; //姓名
    std::string id;   //Id
};



//Owner(车主)
class Owner : public Register{
public:
    Owner(const std::string& name,const std::string& id):Register(name,id){
    }
public:
    void registration() override{
        std::cout<<"owner registration"<<" name:"<<name <<" id:"<<id<<std::endl;
    }
};

//Proxyer(代理人)
class Proxyer : public Register{
public:
    Proxyer(const std::string& name,const std::string& id,Register* principal):Register(name,id),principal(principal){
    }
public:
    void setPrincipal(Register* principal){
        this->principal = principal;
    }
    void registration() override{
        if(principal != nullptr){
            principal->registration();
        }
    }
private:
    Register* principal{nullptr};
};






}
#endif /* proxy_h */
