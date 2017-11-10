#include <nan.h>

void RunCallBack(const Nan::FunctionCallbackInfo<v8::Value>& info)
{
		v8::Local<v8::Function> cb = info[0].As<v8::Function>();
		const unsigned argc = 1;
		
		printf("In the RuncallBack function\n");
		v8::Local<v8::Value> argv[argc] = {Nan::New("hello world").ToLocalChecked()};
		Nan::MakeCallback(Nan::GetCurrentContext()->Global(), cb, argc, argv);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module)
{
		printf("in the init function \n");
		printf(exports);
		Nan::SetMethod(module, "exports", RunCallBack);
}

NODE_MODULE(addon, Init)
