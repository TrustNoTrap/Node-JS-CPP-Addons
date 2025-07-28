#include <node.h>

namespace testing {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::NewStringType;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void Method(const FunctionCallbackInfo<Value>& args) { // We bind this method to our JS object's "start" method
        Isolate* isolate = args.GetIsolate();
        args.GetReturnValue().Set(String::NewFromUtf8(
            isolate, "testing", NewStringType::kNormal
        ).ToLocalChecked());
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "start", Method); // Set a method for our object in JS -> const test = require('our_module); test.start();
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}