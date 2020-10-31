#include "Core.hpp"
#include "Window.hpp"
#include "Errors.hpp"
#include "Collections.hpp"
#include <memory>
#include <utility>
#include <tuple>

namespace vgtu {
    Core::Core() noexcept {
    }

    void Core::run(const int ac, const char * const *av, const char * const* env) {        
        if (ac > 1 || av[1] != NULL)
            throw SystemError {"Cannot run the program with argument."};
        if (env[0] == NULL)
            throw SystemError {"Cannot run the program without environment"};        
        std::shared_ptr<vgtu::engine::Window> window = std::make_shared<vgtu::engine::Window>(std::make_pair(600, 800), "VGTU Practical Work 3");
        std::shared_ptr<vgtu::engine::Event> event = std::make_shared<vgtu::engine::Event>();
        std::unique_ptr<vgtu::collections::Collections> collections = std::make_unique<vgtu::collections::Collections>(window, event);

        while (window->isOpen()) {
            while (window->pollEvent(event.get())) {
                collections->catchEvent();
            }
            collections->run();
            window->clear(std::make_tuple(236, 240, 241));
            collections->draw();
            window->display();            
        }
    }
}