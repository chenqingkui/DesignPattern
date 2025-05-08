//
//  interpreter.hpp
//  DesignPattern
//
//  Created by let'sgo on 2025/5/8.
//

#ifndef design_pattern_interpreter_h
#define design_pattern_interpreter_h
#include <vector>
namespace interpreter{
//
//
//+------------------------------------------------------------------+
//|                   <<interface>>                                  |
//|                   Interpreter                                    |
//+------------------------------------------------------------------+
//|                   + run(): int                                   |
//+----------↑--------------------------------------------------^----+
//           |                                                  |
//           |                                                  |
//           |                                                  |
//+----------+-----+           +------------+             +-----------------+
//| Navigation     |           |   Context  |             | SpitInterprerter|
//| Interprerter   |<----------+------------+------------>+-----------------+
//+----------------+           | + run()    |             | + run(): int    |
//| + run():int    |           +------------+             +-----------------+
//+----------------+
       
           

//解释器
class Interpreter{
public:
    virtual ~Interpreter(){
        
    }
public:
    virtual int run(std::string& rules,std::string& processed) = 0;
};


//x执行器
class NavigationInterprerter:public Interpreter{
public:
    int run(std::string& rule,std::string& processed){
        std::cout<<"navi run:"<<rule<<std::endl;
        return 1;
    }
private:
    
   
};

//分隔执行器
class SpitInterprerter:public Interpreter{
public:
    int run(std::string& rule,std::string& processed){
        if(rule == "")
        {
            return 0;
        }
        int pos = rule.find(",");
        if(pos == -1){
            processed = rule;
            rule = "";
            return 1;
        }
        processed = rule.substr(0,pos);
        rule =  rule.substr(pos+1,rule.length()-pos-1);
        return 1;
    }
   
};


//上下文
class Context{
public:
    Context(Interpreter* navi,Interpreter* split){
        this->navi = navi;
        this->split = split;
    }
public:
    void run(const std::string& rules){
        std::cout<<"run rules:"<<rules<<std::endl;
        std::string ruleStr = rules;
        std::string processed;
        int splitOk = 0;
        do {
            splitOk = split->run(ruleStr,processed);
            if(splitOk){
                navi->run(processed,processed);
            }
            
        }while(splitOk);
    }
private:
    Interpreter* split{nullptr};
    Interpreter* navi{nullptr};
};

}


#endif /* interpreter_h */
