//
//  publiser.h
//  DesignPattern
//
//  Created by let'sgo on 2025/5/8.
//

#ifndef design_pattern_publiser_h
#define design_pattern_publiser_h
#include <unordered_set>
namespace publisher {


//+---------------------+       +---------------------+         +---------------------+
//|     Publisher       |       |        Pool         |         |     Subscriber      |
//+---------------------+       +---------------------+         +---------------------+
//| +publish(msg): void |------>| +subscrible(sub):void|<------>| +notify(msg): void  |
//+----------^----------+       | +unSubscrible(sub):void|      +---------^-----------+
//           |                  +----------^----------+                   |
//           |                             |                              |
// +---------+---------+         +---------+---------+         +----------+---------+
// |      System       |         |    SystemPool     |         |    MusicPlayer    |
// +-------------------+         +-------------------+         +-------------------+
// | -pool: Pool*      |         | -subscribers: set |         | -pool: Pool*      |
// +-------------------+         +-------------------+         +-------------------+


class Subscriber;

//发布中心
class Pool{
public:
    virtual ~Pool(){
        
    }
public:
    virtual void publish(const std::string& msg) = 0;
    virtual void subscrible(Subscriber* subscriber) = 0;
    virtual void unSubscrible(Subscriber* subscriber) = 0;
};



//发布者
class Publisher{
public:
    virtual ~Publisher(){
        
    }
public:
    virtual void  publish(const std::string& msg) = 0;
};


//订阅者
class Subscriber{
public:
    virtual ~Subscriber(){
        
    }
public:
    virtual void notify(const std::string& msg) = 0;
};



//系统池
class SystemPool :public Pool{
public:
    SystemPool(){
    }
public:
    void publish(const std::string& msg) override{
        for(auto sub:subscribers){
            sub->notify(msg);
        }
    }
    virtual void subscrible(Subscriber* subscriber) override{
        subscribers.insert(subscriber);
    }
    virtual void unSubscrible(Subscriber* subscriber) override{
        subscribers.erase(subscriber);
    }
private:
    std::unordered_set<Subscriber*> subscribers;
};


//System
class System : public Publisher{
public:
    System(Pool* pool){
        this->pool = pool;
    }
public:
    void publish(const std::string& msg){
        std::cout <<"system "<< msg <<std::endl;
        pool->publish(msg);
    }
private:
    Pool* pool{nullptr};
};


class MusicPlayer : public Subscriber{
public:
    MusicPlayer(Pool* pool){
        if(pool != nullptr){
            pool->subscrible(this);
            this->pool = pool;
        }
    }
    ~MusicPlayer(){
        if(pool != nullptr){
            pool->unSubscrible(this);
            pool = nullptr;
        }
    }
public:
    void notify(const std::string& msg) override{
        std::cout<<"music player "<<msg<<std::endl;
    }

private:
    Pool* pool{nullptr};
};



}
#endif /* publiser_h */
