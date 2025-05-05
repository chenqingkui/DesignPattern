//
//  chain.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/5.
//

#ifndef design_pattern_chain_h
#define design_pattern_chain_h
namespace chain{
//职责链模式
class Chain{
public:
    Chain(Chain* chain){
        next = chain;
    }
    virtual ~Chain(){
        if(next == nullptr){
            return;
        }
        delete next;
    }
public:
    //处理问题
    virtual bool deal(const std::string& question) = 0;
public:
    void setNext(Chain* next){
        this->next = next;
    }
protected:
    Chain* next{nullptr};
};

//售后
class AfterSales : public Chain{
public:
    AfterSales(Chain* next):Chain(next){
        this->next = next;
    }
    AfterSales():Chain(nullptr){
        
    }
    ~AfterSales(){
       
    }
public:
    //处理问题
    bool deal(const std::string& question) override{
        std::cout<<"after sales deal" <<std::endl;
        
        //can deal
        //return true;
        
        //canot deal
        //交给下一环节
        if(next == nullptr){
            return false;
        }
        return next->deal(question);
    }
};

//工程师
class Engineer: public Chain{
public:
    Engineer(Chain* next):Chain(next){
    }
    Engineer():Chain(nullptr){
        
    }
    ~Engineer(){
       
    }
public:
    //处理问题
    bool deal(const std::string& question) override{
        std::cout<<"engineer deal" <<std::endl;
        
        //can deal
        //return true;
        
        //canot deal
        //交给下一环节
        if(next == nullptr){
            return false;
        }
        return next->deal(question);
    }
};

//经理
class Manager: public Chain{
public:
    Manager(Chain* next):Chain(next){
    }
    Manager():Chain(nullptr){
    }
    ~Manager(){
    }
public:
    //处理问题
    bool deal(const std::string& question) override{
        std::cout<<"manager deal" <<std::endl;
        
        //can deal
        //return true;
        
        //canot deal
        //交给下一环节
        if(next == nullptr){
            return false;
        }
        return next->deal(question);
    }
};

//总经理(总裁)
class President: public Chain{
public:
    President(Chain* next):Chain(next){
    }
    President():Chain(nullptr){
    }
    ~President(){
       
    }
public:
    //处理问题
    bool deal(const std::string& question) override{
        std::cout<<"president deal" <<std::endl;
        
        //can deal
        //return true;
        
        //canot deal
        //交给下一环节
        if(next != nullptr){
            return next->deal(question);
        }
        return false;
    }
};


}
#endif /* chain_h */
