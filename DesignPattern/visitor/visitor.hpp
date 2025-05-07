//
//  visitor.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/7.
//

#ifndef design_pattern_visitor_h
#define design_pattern_visitor_h
namespace visitor{
//
//
//+--------------------------------------+              +---------------------+
//|     <<interface>>                    |              |     <<interface>>   |
//|      Hardware                        |              |       Visitor       |
//+--------------------------------------+<-------------+---------------------+
//| +accept(Visitor*):void               |              |  +visit(Screen*):void|
//| +test(): void                        |              | +visit(Button*):void|
//+-------------------------------------+               +--------------------+
//           ^                       ^                            ^
//           |                       |                            |
// +---------+---------+   +---------+---------+        +---------+-----------+
// |                   |   |                   |        |                     |
// |      Screen       |   |      Button       |        |    HardwareVisitor  |
// +-------------------+   +-------------------+        +---------------------+
// | +accept(): void   |   | +accept(): void   |        | +visit(Screen*):void|
// | +test(): void     |   | +test(): void     |        | +visit(Button*):void|
// +-------------------+   +-------------------+        +---------------------+
                        


class Screen;
class Button;
//访问者
class Visitor{
public:
    ~Visitor(){
        
    }
public:
   virtual void visit(Screen* screen) = 0;
   virtual void visit(Button* button) = 0;
};

//硬件
class Hardware{
public:
    virtual ~Hardware(){
        
    }
public:
    virtual void test() = 0;
    
    virtual void accept(Visitor* vistor) = 0;
    
    
};
//屏幕
class Screen :public Hardware{
    
public:
    void test() override{
        std::cout<<"screen test"<<std::endl;
    }
    void accept(Visitor* visitor) override{
        std::cout<<"screen accept vistor"<<std::endl;
        visitor->visit(this);
    }
};

class Button :public Hardware{
public:
    void test() override{
        std::cout<<"button test"<<std::endl;
    }
    void accept(Visitor* visitor) override{
        std::cout<<"button accept vistor"<<std::endl;
        visitor->visit(this);

    }
};



//车机
class HardwareVistior:public Visitor{
public:
  
    void visit(Screen* screen) override{
        std::cout<<"visit screen"<<std::endl;
        screen->test();
    }
    void visit(Button* button) override{
        std::cout<<"visit button"<<std::endl;
        button->test();
    }
};







}
#endif /* visitor_h */
