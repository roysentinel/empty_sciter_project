#include "main_window.h"

sciter::string main_window::no_params_callback()
{
}

sciter::string main_window::single_param_callback(sciter::value param)
{
    int parameter = param.get(0);
}
