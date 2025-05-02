#ifndef desgin_pattern_single_hpp
#define desgin_pattern_single_hpp
namespace  single{
#include <mutex>
//前置声明
class Single;
//全局单例
Single* gSingleIns = nullptr;
std::mutex gMutex;

//单例模式
class Single{
private:
    Single(){
        
    }
    ~Single(){
        
    }
public:
    void call(){
        std::cout << "single call" << std::endl;
    }
public:
    static Single* getInstance(){
        //首次不判断，为了提升访问性能
        if(gSingleIns == nullptr){
            gMutex.lock();
            //锁内二次判定，解决多线程冲突
            if(gSingleIns == nullptr){
                gSingleIns = new Single();
            }
            gMutex.unlock();
        }
        return gSingleIns;
    }
};


//单例模式
class Single11{
private:
    Single11(){
        
    }
    ~Single11(){
        
    }
public:
    void call(){
        std::cout << "single11 call" << std::endl;
    }
public:
    static Single11& getInstance(){
        static Single11 singleIns;
        return singleIns;
    }
};

}



#endif /* single_hpp */
