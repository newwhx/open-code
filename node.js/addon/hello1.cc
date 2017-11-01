#include <nan.h>

using namespace v8;

NAN_METHOD(Method){
		NanScope();
		NanReturnValue(String::new("world"));
}


void Init(Handle<Object> exports){
		exports->Set(NanSymbol("hello"), FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(hello, Init)
