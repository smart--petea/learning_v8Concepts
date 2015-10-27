#include <nan.h>

/*
 var template = function() {}
 */
void SetEmptyTemplate(v8::Local<v8::Object>& exports) 
{
    v8::Local<v8::FunctionTemplate> emptyTemplate = Nan::New<v8::FunctionTemplate>();
    exports->Set(Nan::New("emptyTemplate").ToLocalChecked(), emptyTemplate->GetFunction());
}

/*
 var template = function() {}
 template.MyProperty = 5
 */
void SetTemplateWithProperty(v8::Local<v8::Object>& exports)
{
    v8::Local<v8::FunctionTemplate> tmpl = Nan::New<v8::FunctionTemplate>();
    tmpl->Set(Nan::New("MyProperty").ToLocalChecked(), Nan::New(5));

    exports->Set(Nan::New("propertyTemplate").ToLocalChecked(), tmpl->GetFunction());
}

void Init(v8::Local<v8::Object> exports)
{
    SetEmptyTemplate(exports);
    SetTemplateWithProperty(exports);
}

NODE_MODULE(fTemplate, Init)
