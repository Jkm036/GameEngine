#include "Window.h"
#include <GLFW/glfw3.h>
#include <iostream>
namespace Sparky {
	namespace Graphics {
		

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void window_resize(GLFWwindow* window, int width, int height);
		void mousebutton_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		Window::Window(int width, int height, const char* name): m_width(width), m_height(height), name(name){
			//init() creates glfw window and sets windows context
			if (!this->init()) {
				glfwTerminate();
			}
			for (int i = 0; i < MAX_KEYS; i++) {
				this->m_keys[i] = false;
			}
			for (int i = 0; i < MAX_BUTTONS; i++) {
				this->m_mouseButtons[i] = false;
			}
			
		}

		void Window::tick() {
			//takes events off of queue and processes them with related callbacks
			glfwPollEvents();
			//swaps back buffers to display
			glfwSwapBuffers(m_window);
		} 
		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Failed to init glfw" << std::endl;
				return false;
			}
			m_window = glfwCreateWindow(m_width, m_height,name, NULL,NULL);
			if (!m_window) {
				glfwTerminate();
				std::cout << "Window failed" << std::endl;
				return false;
			}
			//Makes context for window
			glfwMakeContextCurrent(m_window);
			//My Guess: Stores User defined window Object in association with Actual Window
			glfwSetWindowUserPointer(m_window, this);
			//Upon resize, calls window_resize
			glfwSetWindowSizeCallback(m_window, window_resize);
			//Upon key press, calls key_callback
			glfwSetKeyCallback(m_window, key_callback);
			//upon mouse button, calls mousebutton_callback
			glfwSetMouseButtonCallback(m_window, mousebutton_callback);
			glfwSetCursorPosCallback(m_window, cursor_position_callback);

			//glew creates function pointers to the 
			//functions in the gpu responsible for graphic generation
			if (glewInit() != GLEW_OK) {
				std::cout << "Failed to initialize glew/GPU Functionality" << std::endl;
			}
			return true;
		}
		
		bool Window::closed() const {
			return glfwWindowShouldClose(m_window);
		}
		void Window::clear() const {
			//clears all pixels on the window
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		}
		bool Window::isKeyPressed(unsigned int key_code) const {
			if (key_code > MAX_KEYS) {
				return false;
			}
			return m_keys[key_code];
		}
		bool Window::isMouseButtonPressed(unsigned int button) const {
			if (button > MAX_BUTTONS) {
				return false;
			}
			return m_mouseButtons[button];
		}
		void Window::getMousePosition(double& x, double& y) const {
			x = m_mx;
			y = m_my;
		}
		int Window::getWidth() const {
			return m_width;
		}
		int Window::getHeight() const {
			return m_height;
		}
		// friends
		void window_resize(GLFWwindow* window, int width, int height) {
			Window* win =((Window*) (glfwGetWindowUserPointer(window)));
			win-> m_width = width;
			win-> m_height = height;
			glViewport(0, 0, width, height);
		}
		//Input Callbacks
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
			//must get currrent window and set it's associated boolean key to true
			Window* win = (Window*)(glfwGetWindowUserPointer(window));
			win->m_keys[key] = (action!=GLFW_RELEASE);
		}
		void mousebutton_callback(GLFWwindow* window, int button, int action, int mods) {
			Window* win = (Window*)(glfwGetWindowUserPointer(window));
			win->m_mouseButtons[button] = (action != GLFW_RELEASE);
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			Window* win = (Window*)(glfwGetWindowUserPointer(window));
			win->m_mx = xpos;
			win->m_my = ypos;
		}
		Window::~Window() {
			
			glfwTerminate();
		}
	}
}