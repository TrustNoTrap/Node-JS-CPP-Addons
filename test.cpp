// The file extension can be either cc or cpp, the compiler can handle both of them
// The compilation will succeed even if you see import errors as long as node-gyp is installed and used to compile
#include <node_api.h>

// napi -> Node API
napi_value init(napi_env env, napi_value exports);
napi_value Test(napi_env env, napi_callback_info info);

NAPI_MODULE(NODE_GYP_MODULE_NAME, init);

napi_value init(napi_env env, napi_value exports) {
    napi_value test;

    napi_create_function(env, nullptr, 0, Test, nullptr, &test);

    return test;
}

napi_value Test(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    int64_t upper_limit;
    napi_value output;

    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    napi_get_value_int64(env, args[0], &upper_limit);

    napi_create_double(env, upper_limit + 5, &output);

    return output;
}