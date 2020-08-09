#include "main_window.h"

sciter::string main_window::no_params_callback()
{
    // Sciter uses wide strings so need to convert the regular string to wide string
    return sciter::string(WSTR("This is the string you get from a callback with no parameters"));
}

sciter::string main_window::single_param_callback(sciter::value param)
{
    int parameter = param.get(0);
    std::string return_value("This is the string you get from a callback with parameter, value: " +
                             std::to_string(parameter));

    // Sciter uses wide strings so need to convert the regular string to wide string
    return sciter::string(aux::utf2w(return_value));
}
