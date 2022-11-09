#include <memory>

#include "ts_quad.h"

using namespace RGL;

int main()
{
    std::shared_ptr<CoreApp> app = std::make_shared<Tessellation2D>();
    app->init(WINDOW_WIDTH, WINDOW_HEIGHT, "Tessellation - 2D Demo" /*title*/, 60.0 /*framerate*/);
    app->start();

    return 0;
}