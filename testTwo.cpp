#include <node.h>

namespace testing {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::NewStringType;
    using v8::Object;
    using v8::String;
    using v8::Value;
    using v8::Exception;

    void Method(const FunctionCallbackInfo<Value>& args) { // We bind this method to our JS object's "start" method
        Isolate* isolate = args.GetIsolate();
        
        if (args.Length() < 1) {
            args.GetReturnValue().Set(String::NewFromUtf8(
                isolate, "This is the default value when empty argument", NewStringType::kNormal
            ).ToLocalChecked());
            return;
        }

        if (!args[0]->IsString()) {
            // isolate->ThrowException(Exception::TypeError(
            //     String::NewFromUtf8(isolate, "Currently accepting only strings"), NewStringType::kNormal).ToLocalChecked()
            // );
            return;
        }

        Local<String> result = String::NewFromUtf8(isolate, "\nResult: \t").ToLocalChecked();
        Local<String> v8String = args[0].As<String>();
        args.GetReturnValue().Set(
            String::Concat(isolate, result, v8String)
        );
    }

    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "testMethod", Method); // Set a method for our object in JS -> const test = require('our_module); test.start();
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}