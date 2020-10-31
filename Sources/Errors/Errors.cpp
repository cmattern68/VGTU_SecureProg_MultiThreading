#include "Errors.hpp"

////////////////////////////////////////////////////////////////////////////////

RuntimeError::RuntimeError(std::string const &errorMessage, int const errorCode) noexcept : Error{"Runtime" + (errorMessage.size() ? " :: " + errorMessage : ""), errorCode} {
}

RuntimeError::RuntimeError(std::string &&errorMessage, int const errorCode) noexcept : RuntimeError{errorMessage, errorCode} {
}

RuntimeError::RuntimeError(char const *const errorMessage, int const errorCode) noexcept : RuntimeError{std::string{errorMessage}, errorCode} {
}

RuntimeError::RuntimeError(IError const &error) noexcept : Error{error} {
}

RuntimeError::RuntimeError(IError &&error) noexcept : Error{error} {
}

RuntimeError::RuntimeError(RuntimeError const &error) noexcept : Error{error} {
}

RuntimeError::RuntimeError(RuntimeError &&error) noexcept : Error{error} {
}

RuntimeError::~RuntimeError() {
}

RuntimeError &RuntimeError::operator=(RuntimeError const &error) noexcept {
	return *dynamic_cast<RuntimeError *>(&(*this = *dynamic_cast<IError const *>(&error)));
}

RuntimeError &RuntimeError::operator=(RuntimeError &&error) noexcept {
	return *this = error;
}

////////////////////////////////////////////////////////////////////////////////

SystemError::SystemError(std::string const &errorMessage, int const errorCode) noexcept : Error{"System" + (errorMessage.size() ? " :: " + errorMessage : ""), errorCode} {
}

SystemError::SystemError(std::string &&errorMessage, int const errorCode) noexcept : SystemError{errorMessage, errorCode} {
}

SystemError::SystemError(char const *const errorMessage, int const errorCode) noexcept : SystemError{std::string{errorMessage}, errorCode} {
}

SystemError::SystemError(IError const &error) noexcept : Error{error} {
}

SystemError::SystemError(IError &&error) noexcept : Error{error} {
}

SystemError::SystemError(SystemError const &error) noexcept : Error{error} {
}

SystemError::SystemError(SystemError &&error) noexcept : Error{error} {
}

SystemError::~SystemError() {
}

SystemError &SystemError::operator=(SystemError const &error) noexcept {
return *dynamic_cast<SystemError *>(&(*this = *dynamic_cast<IError const *>(&error)));
}

SystemError &SystemError::operator=(SystemError &&error) noexcept {
return *this = error;
}


