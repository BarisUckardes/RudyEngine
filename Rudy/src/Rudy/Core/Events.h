#pragma once
#include <functional>
#define RUDY_BIND_EVENT(function) std::bind(&function,this,std::placeholders::_1)
#define RUDY_BIND_EVENT(object,function) std::bind(&function,object,std::placeholders::_1)