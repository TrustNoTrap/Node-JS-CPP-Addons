// The file extension can be either cc or cpp, the compiler can handle both of them
// The compilation will succeed even if you see import errors as long as node-gyp is installed and used to compile
#include <node_api.h>

// napi -> Node API
napi_value init(napi_env env, napi_value exports);
napi_value Test(napi_env env, napi_callback_info info);
// napi_value TestTwo(napi_env env, napi_callback_info info);

NAPI_MODULE(NODE_GYP_MODULE_NAME, init);

napi_value init(napi_env env, napi_value exports) {
    napi_value test;

    napi_create_function(env, nullptr, 0, Test, nullptr, &test);
    // napi_create_function(env, nullptr, 0, TestTwo, nullptr, &test);

    return test;
}

napi_value Test(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    int64_t n_input;
    napi_value output;

    napi_get_cb_info(env, info, &argc, args, NULL, NULL);

    napi_get_value_int64(env, args[0], &n_input);

    napi_create_double(env, n_input + 5, &output);

    return output;
}

// napi_value TestTwo(napi_env env, napi_callback_info info) {
//     size_t argc = 1;
//     napi_value args[1];
//     char* n_input;
//     napi_value output;

//     napi_get_cb_info(env, info, &argc, args, NULL, NULL);

//     napi_get_value_string_utf8(env, args[0], &n_input, size_t 200);

//     napi_create_string_utf8(env, n_input + " | Works", &output);

//     return output;
// }