#ifndef RADIOEXCEPTION_H
#define RADIOEXCEPTION_H
#include <exception>
#include <string>
class RadioException : public std::exception {
    std::string m_msg;
public:
    explicit RadioException(const std::string& msg) : m_msg(msg) {}
    const char* what() const noexcept override { return m_msg.c_str(); }
};
#endif
