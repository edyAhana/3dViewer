#include "Application.hpp"

int main(void)
{
    Application* app = Application::get_instance();

    if(!app->init()) {
        return -1;
    }

    app->run();

    return 0;
}
