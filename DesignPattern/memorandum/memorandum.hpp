//
//  memorandum.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/3.
//

#ifndef design_pattern_memorandum_h
#define design_pattern_memorandum_h

#include <iostream>
#include <string>
#include <sstream>
namespace memorandum{

//备忘录模式

//上下文
class Context{
public:
    virtual ~Context(){
        
    }
public:
    virtual void load() = 0;
    virtual std::string save() = 0;
    virtual void setSong(const std::string& song) = 0;
    virtual void setRatio(float ratio) = 0;
    virtual std::string getSong() = 0;
    virtual float getRatio() = 0;
};


//播放器上下文
class PlayerContext:public Context{
public:
    ~PlayerContext(){
        
    }
public:
    void load() override{
        std::istringstream loadStream(playingContext);
        std::string songFlag;
        std::string ratioFlag;
        loadStream >> songFlag >> playingSong >>ratioFlag >> playingRatio;
        std::cout<<"load:"<<"song:"<<playingSong<<",ratio:"<<playingRatio<<std::endl;
    }
    std::string save() override{
        std::ostringstream saveStream;
        saveStream << "song:" << playingSong << ",ratio:" << playingRatio;
        std::cout<<"save:"<<saveStream.str()<<std::endl;
        playingContext = saveStream.str();
        return playingContext;
    }
    void setSong(const std::string& song) override{
        playingSong = song;
        std::cout<<"song:"<<song<<std::endl;

    }
    void setRatio(float ratio) override{
        playingRatio = ratio;
        std::cout<<"ratio:"<<ratio<<std::endl;
    }
    std::string getSong() override{
        return playingSong;

    }
    float getRatio() override{
        return playingRatio;
    }
private:
    std::string playingContext;    //存储序列化内容
private:
    std::string playingSong; //播放歌曲
    float playingRatio; //播放进度
};


//音乐播放器
class MusicPlayer{
public:
    MusicPlayer(){
    }
public:
    void load(Context* context){
        if(context == nullptr){
            return;
        }
        context->load();
        playingSong = context->getSong();
        playingRatio = context->getRatio();
    }
    Context* save(){
        Context* context = new PlayerContext();
        context->setSong(playingSong);
        context->setRatio(playingRatio);
        context->save();
        return context;
    }
    void setSong(const std::string& song){
        playingSong = song;
    }
    void setRatio(float ratio){
        playingRatio = ratio;
    }
private:
    std::string playingSong; //播放歌曲
    float playingRatio; //播放进度
};



//音乐播放器
class MusicPlayerCaretaker{
public:
    MusicPlayerCaretaker(){
    }
public:
    void setContext(Context* context){
        this->context = context;
    }
    Context* getContext(){
        return context;
    }
private:
    Context* context;
};

}//end namespace


#endif /* memorandum_h */
