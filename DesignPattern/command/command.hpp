//
//  command.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/6.
//

#ifndef design_pattern_command_h
#define design_pattern_command_h

namespace command {

//命令模式
//+----------------+       +----------------+       +-----------------+
//|    Client      |       |    Invoker     |       |    Receiver     |
//|                |------>|                |------>|                 |
//| 创建命令对象    |       | 管理命令队列    |       | 执行业务逻辑    |
//+----------------+       +-------+--------+       +-----------------+
//                                 ^
//                                 |
//                        +--------+--------+
//                        |    Command      |
//                        |                 |
//                        | +doAction()     |
//                        | +cancelAction() |
//                        +--------+--------+
//                                 ^
//                                 |
//                   +-------------+-------------+
//                   |                           |
//           +-------+-------+           +-------+-------+
//           | MusicCommand  |           | NaviCommand   |
//           |               |           |               |
//           | -receiver     |           | -receiver     |
//           +---------------+           +---------------+


class Command {
public:
    virtual ~Command(){
        
    }
public:
    //响应动作
    virtual void doAction() = 0;
    //取消动作
    virtual void cancelAction() = 0;
};


//receiver(命令接收者)
class Receiver{
public:
    ~Receiver(){
    }
public:
    virtual void action(const std::string& action) = 0;
};

//音乐播放器
class MusicPlayer : public Receiver {
public:
    MusicPlayer(){
    }
public:
    void action(const std::string& action) override {
        std::cout<< "music action:" << action<<std::endl;
    }
};

//音乐播放器命令
class MusicCommand : public Command{
public:
    MusicCommand(const std::string& action,Receiver* player){
        this->action = action;
        this->player = player;
    }
public:
    void doAction() override{
        std::cout<< "music do action:" << action<<std::endl;
        if(player != nullptr){
            player->action(action);
        }
    }
    void cancelAction() override{
        std::cout<< "music cancel action:" << action<<std::endl;
    }
private:
    std::string action;
    Receiver* player{nullptr};
};



//导航
class Navigation :public Receiver{
public:
    Navigation(){
    }
public:
    void action(const std::string& action) override{
        std::cout<<"navigation action:" << action << std::endl;
    }
};


//导航播报命令
class NavigationCommand:public Command{
public:
    NavigationCommand(const std::string& action,Receiver* navigation){
        this->action = action;
        this->navigation = navigation;
    }
public:
    void doAction() override{
        std::cout<< "navigation do action:" << action<<std::endl;
        navigation->action(action);
    }
    void cancelAction() override{
        std::cout<< "navigation cancel action:" << action<<std::endl;
    }
private:
    std::string action;
    Receiver* navigation{nullptr};
    
};




//Commander(Invoker)
//指挥者
class Commander{
public:
    virtual ~Commander(){
    }
public:
    virtual void doCommand() = 0;
    virtual void addCommand(Command* cmd) = 0;
    virtual void cancleCommand(Command* cmd) = 0;
};

//娱乐系统命令器(具体Invoker)
class EnviormentCommander:public Commander{
public:
    EnviormentCommander(){
    }
public:
    void doCommand() override{
        for(auto command : commands){
            command->doAction();
        }
    }
public:
    void addCommand (Command* cmd) override{
        commands.push_back(cmd);
    }
    void cancleCommand(Command* cmd) override{
        for(auto cmdIt = commands.begin();cmdIt != commands.end();){
            if(cmd == *cmdIt){
                cmdIt = commands.erase(cmdIt);
                cmd->cancelAction();
                break;
            }
            else{
                cmdIt++;
            }
        }
    }
private:
    std::vector<Command*> commands;
};


}
#endif /* command_h */
