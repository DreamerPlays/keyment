#include "doonce.h"

doonce::doonce(std::string n, std::function<void(std::string)> function, std::function<void(std::string)> stop, std::function<void(std::string)> load) {
  doonce::name = n;
  doonce::fun = std::bind(function, std::placeholders::_1);
  doonce::funS = std::bind(stop, std::placeholders::_1);
  doonce::funL = std::bind(load, std::placeholders::_1);
  doonce::done = false;
  doonce::funL(doonce::name);
}

doonce::~doonce() {
}

void doonce::doF() {
  if (doonce::done == false) {
    doonce::funS(doonce::name);
    doonce::fun(doonce::name);
    doonce::done = true;
  }
}

void doonce::reset() {
  if (doonce::done == true) {
    doonce::funS(doonce::name);
    doonce::done = false;
  }
}