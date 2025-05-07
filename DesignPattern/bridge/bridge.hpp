//
//  bridge.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/7.
//

#ifndef design_pattern_bridge_h
#define design_pattern_bridge_h
namespace bridge {

//
//        +-------------------------------+                    +---------------------------------------+
//        |     <<interface>>             |                    |     <<interface>>                     |
//        |      Software                 |------------------->|      Hardware                         |
//        +-------------------------------+                    +---------------------------------------+
//        | -hardware: Hardware*          |                    | +working(): void                      |
//        +-------------------------------+                    +---------------------------------------+
//        | +aiWorking(): void            |                            ^                          ^
//        +-------------------------------+                            |                          |
//           ^                       ^                                 |                          |
//           |                       |                                 |                          |
//           |                       |                                 |                          |
// +---------+---------+   +---------+---------+            +----------+----------+     +---------+---------+
// |                   |   |                   |            |                     |     |       AMDGPU      |
// |    MusicPlayer    |   |   VideoPlayer     |            |      NvidaGPU       |     +-------------------+
// +-------------------+   +-------------------+            +---------------------+     | +working(): void  |
// | +aiWorking(): void|   | +aiWorking(): void|            | +working(): void    |     +-------------------+
// +-------------------+   +-------------------+            +---------------------+
                        
                        






                                 
//硬件
class Hardware{
public:
    ~Hardware(){
        
    }
public:
    virtual void working() = 0;
};

//Nvida GPU
class NvidaGPU:public Hardware{
public:
    void working() override{
        std::cout<<"nvida gpu working"<<std::endl;
    }

};

//AMD GPU
class AMDGPU:public Hardware{
public:
    void working() override{
        std::cout<<"amd gpu working"<<std::endl;
    }

};


//软件
class Software{
public:
    ~Software(){
        
    }
public:
    //依赖gpu ai能力
    virtual void aiWorking()  = 0;
protected:
    Hardware* hardware{nullptr};
};

//播放器
class MusicPlayer:public Software{
public:
    MusicPlayer(Hardware* hardware){
        this->hardware = hardware;
    }
public:
    //依赖gpu ai能力
    void aiWorking() override{
        std::cout<<"music player ai working"<<std::endl;
        hardware->working();
    }
    
};


//播放器
class VideoPlayer:public Software{
public:
    VideoPlayer(Hardware* hardware){
        this->hardware = hardware;
    }
public:
    void aiWorking()override{
        std::cout<<"video player ai working"<<std::endl;
        hardware->working();
    }
};

}

#endif /* bridge_h */
