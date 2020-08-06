#pragma once
#include "sciter-x.h"
#include "sciter-x-window.hpp"

class main_window : public sciter::window
{
public:
    main_window() : sciter::window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN | SW_ENABLE_DEBUG)
    {
    }

    ~main_window() = default;

    //
    // Frontend APIs
    //
    BEGIN_FUNCTION_MAP
    FUNCTION_0("no_params_callback", no_params_callback);
    FUNCTION_1("single_param_callback", single_param_callback);
    END_FUNCTION_MAP

private:
    sciter::string no_params_callback();
    sciter::string single_param_callback(sciter::value param);
};
