#include <nan.h>

/*
 * Nan::New<v8::FunctionTemplate>() called without arguments will be a template for a JS function of form 
 ---JS---
 var template = function() {}
 */
void SetEmptyTemplate(v8::Local<v8::Object>& exports) 
{
    v8::Local<v8::FunctionTemplate> emptyTemplate = Nan::New<v8::FunctionTemplate>();
    exports->Set(Nan::New("emptyTemplate").ToLocalChecked(), emptyTemplate->GetFunction());
}

void Init(v8::Local<v8::Object> exports)
{
    SetEmptyTemplate(exports);
}

NODE_MODULE(fTemplate, Init)
