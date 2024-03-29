#ifndef UDP_ERROR_HPP
#define UDP_ERROR_HPP
#include <iostream>
#include <vector>
#include "config.h"

enum {
    UDP_ERROR_OK = 0,
    UDP_ERROR_INVAL,
    UDP_ERROR_CREATE_SOCKET,
    UDP_ERROR_SET_SOCK_OPT,
    UDP_ERROR_BIND,
    UDP_ERROR_NUMBER,
    UDP_ERROR_SEND,
    UDP_ERROR_RECEIVE,
#ifdef USE_WOLFSSL
    UDP_ERROR_WOLFSSL_NEW_CTX,
    UDP_ERROR_WOLFSSL_CERTS_LOCATION,
    UDP_ERROR_WOLFSSL_NEW_OBJECT,
    UDP_ERROR_WOLFSSL_CONNECT,
#endif    
    UDP_ERROR_UNKNOWN
};
#define UDP_ERROR_MIN   UDP_ERROR_OK
#define UDP_ERROR_MAX   UDP_ERROR_UNKNOWN


class udp_error {
    public:
        udp_error()
        {
        }
        ~udp_error()
        {
        }
        int set_code(int error_code) 
        {
            if ( (error_code < UDP_ERROR_MIN) || (error_code > UDP_ERROR_MAX)) return UDP_ERROR_INVAL;
            code = error_code;
            return UDP_ERROR_OK;
        }
        int get_code() const
        {
            return code;
        }
        void show_message()
        {
            if (code > messages.size()) return;
            std::cout << messages[code];
        }
    
    protected:

    int code;

        const std::vector <std::string> messages = {
            "No any errors",
            "Invalid parameter",
            "Can not create a socket ",
            "Can not bind IP address and port",
            "",
            "Can not send the package",
            "Can not receive the package",
            "Unknown error"
        }; 

};




#endif//UDP_EROR_HPP
