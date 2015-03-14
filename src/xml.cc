#include <node.h>
#include <v8.h>
#include <iostream>
#include <string>
#include "tinyxml.h"


// 引入v8命名空间
using namespace v8;

// sayHello方法的具体逻辑
Handle<Value> Method(const Arguments& args) {
    HandleScope scope;

    TiXmlDocument* myDocument = new TiXmlDocument();
    char *c_arg = *v8::String::Utf8Value(args[0]->ToString());
    myDocument->LoadFile(c_arg);
    TiXmlElement* rootElement = myDocument->RootElement();  //Class
    TiXmlElement* testsElement = rootElement->FirstChildElement();  //Students
    TiXmlElement* testElement = testsElement->FirstChildElement();  //Students
    while ( testElement ) {
      TiXmlAttribute* attribute= testElement->FirstAttribute();  //获得student的name属性
      while ( attribute ) {
        std::cout << attribute->Name() << " : " << attribute->Value() << std::endl;
        attribute = attribute->Next();
      }
      TiXmlElement* phoneElement = testElement->FirstChildElement();//获得student的phone元素
      std::cout << "phone" << " : " << phoneElement->GetText() << std::endl;
      TiXmlElement* addressElement = phoneElement->NextSiblingElement();
      std::cout << "address" << " : " << addressElement->GetText() << std::endl;
      testElement = testElement->NextSiblingElement();
    }
    return scope.Close(String::New("Finish!"));
}

// 初始化模块
void init(Handle<Object> target) {
    // 定义模块中的sayHello方法
    NODE_SET_METHOD(target, "xml", Method);
}

// 定义"hello"模块
NODE_MODULE(xml, init);