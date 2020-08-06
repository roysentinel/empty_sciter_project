/*
 *
 */
#include <functional>
#include "main_window.h"

// Resources file auto-generated during build that packs all the
// web resources into a single blob that sciter knows how to reference
#include "resources.h"

int uimain(std::function<int()> run)
{
    sciter::archive::instance().open(aux::elements_of(resources));

    sciter::om::hasset<main_window> window = new main_window();

    window->load(WSTR("this://src/web/main.htm"));

    window->expand();

    return run();
}
