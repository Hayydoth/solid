#include "Application.h"

int main()
{
    if (Application::Start()) {
        Application::Loop();
    }
    
    return 0;
}
