#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include "IError.hpp"

////////////////////////////////////////////////////////////////////////////////

    class RuntimeError final : public Error {
    public:
	explicit RuntimeError(std::string const &errorMessage = "", int const errorCode = ERRORCODE::RUNTIMEERROR) noexcept;
	explicit RuntimeError(std::string &&, int const) noexcept;
        explicit RuntimeError(char const *const, int const) noexcept;
        RuntimeError(IError const &) noexcept;
	explicit RuntimeError(IError &&) noexcept;
        RuntimeError(RuntimeError const &) noexcept;
	explicit RuntimeError(RuntimeError &&) noexcept;
	virtual ~RuntimeError() noexcept override final;

	using Error::operator=;
        RuntimeError &operator=(RuntimeError const &) noexcept;
	RuntimeError &operator=(RuntimeError &&) noexcept;

    private:
    };

////////////////////////////////////////////////////////////////////////////////

    class SystemError final : public Error {
    public:
	explicit SystemError(std::string const &errorMessage = "", int const errorCode = ERRORCODE::SYSTEMERROR) noexcept;
	explicit SystemError(std::string &&, int const) noexcept;
        explicit SystemError(char const *const, int const) noexcept;
        SystemError(IError const &) noexcept;
	explicit SystemError(IError &&) noexcept;
        SystemError(SystemError const &) noexcept;
	explicit SystemError(SystemError &&) noexcept;
	virtual ~SystemError() noexcept override final;

	using Error::operator=;
        SystemError &operator=(SystemError const &) noexcept;
	SystemError &operator=(SystemError &&) noexcept;

    private:
    };

////////////////////////////////////////////////////////////////////////////////

#endif
