#include <node.h>

namespace demo{

		using namespace v8;
		void Method(const FunctionCallbackInfo<Value>& args) 
		{
				Isolate* isolate = args.GetIsolate();
				printf("hello world from adon nan and v8\n");
				args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello world"));
		}

		void init(Local<Object> exports)
		{
				NODE_SET_METHOD(exports, "helloAddon", Method);
		}

		NODE_MODULE(hello, init)
}
