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
    Nan::SetTemplate(tmpl, "MyProperty", Nan::New(5));

    exports->Set(Nan::New("propertyTemplate").ToLocalChecked(), tmpl->GetFunction());
}

/*
 var template = function() {}
 template.prototype.proto_method = function() {}
 template.prototype.proto_const = 100
 */
void SetTemplateWithPrototype(v8::Local<v8::Object>& exports)
{
    //var template = function() {}
    v8::Local<v8::FunctionTemplate> tmpl = Nan::New<v8::FunctionTemplate>(); 

    //template.proto_method = function() {}
    Nan::SetPrototypeTemplate(tmpl, "proto_method", Nan::New<v8::FunctionTemplate>()->GetFunction());

    //template.proto_const = 2
    Nan::SetPrototypeTemplate(tmpl, "proto_const", Nan::New(2));

    exports->Set(Nan::New("prototypeTemplate").ToLocalChecked(), tmpl->GetFunction());
}


void Method(const Nan::FunctionCallbackInfo<v8::Value>& info) 
{
    info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}
/*
 var template = function() { 
    this.instance_const = "instance_const";
    this.instance_method = function() { return "world"; }
 }

 var tempObj = new template;
 console.log(tempObj.instance_const); // instance_const
 console.log(tempObj.instance_method()); // world
 */
void SetTemplateWithInstanceProperty(v8::Local<v8::Object>& exports)
{
    //var template = function() {}
    v8::Local<v8::FunctionTemplate> tmpl = Nan::New<v8::FunctionTemplate>(); 

    //this.instance_const = "instance_const";
    Nan::SetInstanceTemplate(tmpl, "instance_const", Nan::New("instance_const").ToLocalChecked());

    //this.instance_method = function() {}
    Nan::SetInstanceTemplate(tmpl, "instance_method", Nan::New<v8::FunctionTemplate>(Method));

    exports->Set(Nan::New("instanceTemplate").ToLocalChecked(), tmpl->GetFunction());
}

void Init(v8::Local<v8::Object> exports)
{
    SetEmptyTemplate(exports);
    SetTemplateWithProperty(exports);
    SetTemplateWithPrototype(exports);
    SetTemplateWithInstanceProperty(exports);
}

NODE_MODULE(fTemplate, Init)
