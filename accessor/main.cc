#include <nan.h>

NAN_GETTER(PropGetterClbk)
{
    static int x = 0;
    info.GetReturnValue().Set(++x);
}

static int propGSValue = 0;
NAN_GETTER(PropGSGetterClbk)
{
    info.GetReturnValue().Set(propGSValue);
}

NAN_SETTER(PropGSSetterClbk)
{
    //v8::Local<v8::String> property                
    //v8::Local<v8::Value> value         
    //Nan::NAN_SETTER_ARGS_TYPE info
    propGSValue = (int)value->Int32Value();
}

void Init(v8::Local<v8::Object> target)
{
    /*only getter*/
    //accessor = require("./accessor.node")
    //accessor.propGetter; -> 1
    //accessor.propGetter; -> 2
    //accessor.propGetter; -> 3
    Nan::SetAccessor(target, Nan::New("propGetter").ToLocalChecked(), PropGetterClbk);

    /*getter + setter*/
    Nan::SetAccessor(target, Nan::New("propGS").ToLocalChecked(), PropGSGetterClbk, PropGSSetterClbk);
}

NODE_MODULE(accessor, Init)
