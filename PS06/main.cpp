#include "Authenticate.h"

#include <iostream>

using namespace Authenticate;

int main()
{
    inputUserName();
    inputPassword();

    std::cout << "Your username is " << getUserName()
              << " and your password is: " << getPassword() << std::endl;

    return 0;
}
