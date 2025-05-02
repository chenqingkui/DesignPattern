#ifndef design_pattern_observer_h
#define design_pattern_observer_h
#include <unordered_set>
namespace observer{

//观察者
class Notifyer{
public:
    virtual void notify(const char* msg) = 0;
};


//生产者
class VehicleCorp {
public:
    VehicleCorp(){
        
    }
public:
    //订阅消息
    void confirmOrder(Notifyer* notify){
        if(notify == nullptr){
            return;
        }
        //查找存在则返回
        if(notifyers.count(notify)){
            return;
        }
        notifyers.insert(notify);
    }
    //取消订阅
    void cancelOrder(Notifyer* notify){
        if(notify == nullptr){
            return;
        }
        //不存在无法取订
        if(!notifyers.count(notify)){
            return;
        }
        notifyers.erase(notify);
    }
public:
    void notify(const char* msg){
        for(auto er :notifyers){
            er->notify(msg);
        }
    }
private:
    //记录订阅者
    std::unordered_set<Notifyer*> notifyers;
};

}

#endif
