#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <cstddef>
#include <memory>
#include <string>

struct WindowProperty {
    std::size_t y_pos;
    std::size_t x_pos;
    std::size_t width;
    std::size_t height;
    std::string title;
    WindowProperty(std::size_t y_pos = 0,
                   std::size_t x_pos = 0,
                   std::size_t width = 1280,
                   std::size_t height = 720,
                   std::string title = "Window")
                        : y_pos(y_pos)
                        , x_pos(x_pos)
                        , width(width)
                        , height(height)
                        , title(std::move(title)) {}

    WindowProperty(WindowProperty&& other) = default;
};


class Window {
protected:
    WindowProperty property;
public:
    Window(WindowProperty property): property(std::move(property)) {}
                                            
    virtual ~Window() = default;

    // getters
    std::size_t y_pos() const noexcept { return property.y_pos; }
    std::size_t x_pos() const noexcept { return property.x_pos; }
    std::size_t width() const noexcept { return property.width; }
    std::size_t height() const noexcept { return property.height; }
    const std::string_view title() const noexcept { return {property.title}; }

    virtual bool init() = 0;
    virtual bool window_should_close() const noexcept = 0;
    virtual void update() const = 0;
    virtual void* get_native_window() = 0;
    
    static std::unique_ptr<Window> create_window(WindowProperty wp = WindowProperty());
};


#endif
