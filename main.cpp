#include "Application.hpp"

int main(void)
{
    Application& app = Application::get_instance();

    app.run();

    return 0;
}
