#include <nan.h>

/*
 var my_obj = {}
 */
void SetEmptyObject(v8::Local<v8::Object>& exports) 
{
    v8::Local<v8::ObjectTemplate> tpl = Nan::New<v8::ObjectTemplate>();
    exports->Set(Nan::New("my_obj").ToLocalChecked(), Nan::NewInstance(tpl).ToLocalChecked());
}

/*
 var obj1 = {a: 5}
 */
void SetObjectWithNumberProperty(v8::Local<v8::Object>& exports)
{
    v8::Local<v8::ObjectTemplate> tpl = Nan::New<v8::ObjectTemplate>();
    v8::Local<v8::Object> opl = Nan::NewInstance(tpl).ToLocalChecked();

    opl->Set(Nan::New("a").ToLocalChecked(), Nan::New(5));

    exports->Set(Nan::New("obj1").ToLocalChecked(), opl);
}

/*
 var obj2 = {mth: function(){}}
*/
void SetObjectWithEmptyMethodProperty(v8::Local<v8::Object>& exports)
{
    v8::Local<v8::ObjectTemplate> tpl = Nan::New<v8::ObjectTemplate>();
    v8::Local<v8::Object> opl = Nan::NewInstance(tpl).ToLocalChecked();

    opl->Set(Nan::New("mth").ToLocalChecked(), Nan::New<v8::FunctionTemplate>()->GetFunction());

    exports->Set(Nan::New("obj2").ToLocalChecked(), opl);
}

NAN_METHOD(MyContextChanger) {
    info.This()->Set(Nan::New("a").ToLocalChecked(), Nan::New("a").ToLocalChecked());
}

/*
 var obj3 = {mth: function(){ this.a = "a"; }}
*/
void SetObjectWithMethodProperty(v8::Local<v8::Object>& exports)
{
    v8::Local<v8::ObjectTemplate> tpl = Nan::New<v8::ObjectTemplate>();
    v8::Local<v8::Object> opl = Nan::NewInstance(tpl).ToLocalChecked();

    opl->Set(Nan::New("mth").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(MyContextChanger)->GetFunction());

    exports->Set(Nan::New("obj3").ToLocalChecked(), opl);
}


void Init(v8::Local<v8::Object> exports)
{
    SetEmptyObject(exports);
    SetObjectWithNumberProperty(exports);
    SetObjectWithEmptyMethodProperty(exports);
    SetObjectWithMethodProperty(exports);
}

NODE_MODULE(oTemplate, Init)
