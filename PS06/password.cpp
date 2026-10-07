#include "Authenticate.h"

#include <cctype>
#include <iostream>
#include <string>

namespace Authenticate
{
    namespace
    {
        std::string password;

        bool isValid()
        {
            if (password.length() < 8)
            {
                return false;
            }

            for (unsigned char ch : password)
            {
                if (!std::isalpha(ch))
                {
                    return true;
                }
            }

            return false;
        }
    }

    void inputPassword()
    {
        do
        {
            std::cout << "Enter your password (at least 8 characters and at least one non-letter)"
                      << std::endl;
            std::cin >> password;
        } while (!isValid());
    }

    std::string getPassword()
    {
        return password;
    }
}
