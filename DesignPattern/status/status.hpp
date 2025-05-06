//
//  status.h
//  DesignPattern
//
//  Created by let'sgo on 2025/5/6.
//

#ifndef design_pattern_status_h
#define design_pattern_status_h
namespace status{

//
//+---------------------+          +-------------------+
//|      Context        |          |      State        |
//|  (MusicPlayerUI)    |<>------- |  (Status)         |
//+---------------------+          +-------------------+
//| -state: State       |          | +handle(UI*): void|
//| +setStatus()        |          +-------------------+
//| +updateTime()       |                   ^
//+---------------------+                   |
//                                          |
//                               +-----------+-----------+
//                               |                       |
//                       +-------+-------+       +-------+-------+
//                       |   DayStatus   |       |  NightStatus  |
//                       | +handle():    |       | +handle():    |
//                       |   setColor(white)     |   setColor(dark)
//                       +---------------+       +---------------+


//UI
class Status;

//UI
class UI{
public:
    virtual ~UI(){
        
    }
public:
    virtual void setStatus(Status* status) = 0;
    virtual void setColor(const std::string& color) = 0;
};

//状态
class Status{
public:
    virtual ~Status(){
        
    }
public:
    virtual void handle(UI* ui) = 0;
};

//白天状态
class DayStatus : public Status{
public:
    void handle(UI* ui) override{
        std::string color = "white";
        ui->setColor(color);
    }
};

//夜间状态
class NightStatus : public Status{
public:
    void handle(UI* ui) override{
        ui->setColor("dark");
    }
};

////UI
//class UI{
//public:
//    virtual ~UI(){
//        
//    }
//public:
//    virtual void setStatus(Status* status) = 0;
//    virtual void setColor(const std::string& color) = 0;
//};

//音乐播放器UI
class MusicPlayerUI : public UI{
public:
    void updateTime(){
        status::Status * timeStatus = nullptr;
        // 获取当前系统时间点
        auto statusNow = std::chrono::system_clock::now();
        
        // 转换为 time_t（C风格时间）
        std::time_t statusNowTimeT = std::chrono::system_clock::to_time_t(statusNow);
        
        // 转换为本地时间结构体
        std::tm* statusLocalTime = std::localtime(&statusNowTimeT);
        
        if(statusLocalTime->tm_hour >= 6 && statusLocalTime->tm_hour <= 18){
            timeStatus = new status::DayStatus();
        }else{
            timeStatus = new status::NightStatus();
        }
        setStatus(timeStatus);
        delete timeStatus;
    }
    void setStatus(Status* status) override{
        this->status = status;
        if(status != nullptr){
            status->handle(this);
        }
    }
public:
    void setColor(const std::string& color) override{
        std::cout<<"music player color:"<<color<<std::endl;
    }
private:
    Status* status{nullptr};
};


}


#endif /* status_h */
