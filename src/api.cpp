#include <string>
#include <stdio.h>
#include <napi.h>

using namespace Napi;

Napi::Boolean CheckUSBKey(const CallbackInfo& info) {
    Env env = info.Env();

    return Napi::Boolean::New(env, true);
}

Napi::Array GetExpDate(const CallbackInfo& info) {
    Env env = info.Env();

    Napi::Array list = Napi::Array::New(env, 1);
    Napi::Object item = Napi::Object::New(env);
    item.Set("id", 1);
    item.Set("licenseType", "perpetual");
    item.Set("expDate", 0);
    item.Set("timeStart", 0);
    item.Set("totalTime", 0);
    item.Set("counterFix", 0);
    item.Set("counterVar", 0);

    int i = 0;
    list.Set(i, item);
    
    return list;
}

Napi::Number IsLimit(const CallbackInfo& info) {
    Env env = info.Env();

    return Napi::Number::New(env, 0);
}

Napi::Boolean CheckMacInfo(const CallbackInfo& info) {
    Env env = info.Env();

    return Napi::Boolean::New(env, true);
}

Napi::String GetFingerprint(const CallbackInfo& info) {
    Env env = info.Env();

    return Napi::String::New(env, "aaa");
}

Napi::Boolean UpdateFingerprint(const CallbackInfo& info) {
    Env env = info.Env();

    return Napi::Boolean::New(env, true);
}

Napi::String GetHardwareInfo(const CallbackInfo& info) {
    Env env = info.Env();

    return Napi::String::New(env, "aaa");
}

Napi::String GetDogMemoryInfo(const CallbackInfo& info) {
    Env env = info.Env();

    return Napi::String::New(env, "aaa");
}

Object Initialize(Env env, Object exports) {
    exports.Set("checkUSBKey", Function::New(env, CheckUSBKey));
    exports.Set("getExpDate", Function::New(env, GetExpDate));
    exports.Set("isLimit", Function::New(env, IsLimit));
    exports.Set("checkMacInfo", Function::New(env, CheckMacInfo));
    exports.Set("getFingerprint", Function::New(env, GetFingerprint));
    exports.Set("updateFingerprint", Function::New(env, UpdateFingerprint));
    exports.Set("getHardwareInfo", Function::New(env, GetHardwareInfo));
    exports.Set("getDogMemoryInfo", Function::New(env, GetDogMemoryInfo));

    return exports;
}

NODE_API_MODULE(phoneme_tool_x64, Initialize)