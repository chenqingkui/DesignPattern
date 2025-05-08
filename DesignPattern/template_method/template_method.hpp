//
//  template_method.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/8.
//

#ifndef design_pattern_template_method_h
#define design_pattern_template_method_h
namespace template_method{
//音乐推荐
class Recommend{
public:
    virtual ~Recommend(){
        
    }
public:
    std::string recommend(){
        std::string info = search();
        rank(info);
        return match(info);
    }
    virtual std::string search() = 0;
    virtual void rank(const std::string& msg) = 0;
    virtual std::string match(const std::string& msg) = 0;
};

//歌曲推荐
class MusicSongRecommend:public Recommend{
public:
    MusicSongRecommend(){
    }
public:
    std::string search() override{
        std::cout<<"song recommend"<<std::endl;
        return "jaz,soft,rock";
    }
    void rank(const std::string& msg) override{
        std::cout<<"song rank " << msg <<std::endl;
    }
    std::string match(const std::string& msg) override {
        std::cout<<"song match " << msg <<std::endl;
        return "match jaz";
    }
};

}

#endif /* template_method_h */
