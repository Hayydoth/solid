#include "Application.h"

int main()
{
    if (Application::Instance().Start()) {
        Application::Instance().Loop();
    }
    
    return 0;
}
