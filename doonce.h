#pragma once
#include <functional>
#include <string>

class doonce {
  private:
    std::string name;
    std::function<void(std::string)> fun;
    std::function<void(std::string)> funS;
    std::function<void(std::string)> funL;

  public:
    doonce(std::string, std::function<void(std::string)>,std::function<void(std::string)>,std::function<void(std::string)>);
    bool done;
    ~doonce();
    void doF();
    void reset();
    void resetO();
};