#pragma once
#include<GL/glew.h>
#include <GLFW/glfw3.h>
#define MAX_KEYS 1024
#define MAX_BUTTONS 32
namespace Sparky {
	namespace Graphics {
		class Window {
		

		private:
			const char* name;
			int	m_width, m_height;
			GLFWwindow* m_window;
			//window state
			bool m_closed;
			//input button
			bool m_keys[MAX_KEYS];
			bool m_mouseButtons[MAX_BUTTONS];
			//mouse position
			double m_mx, m_my;
		public:
			Window(int width, int height, const char* name);
			~Window();
			void tick();
			bool closed() const;
			void clear() const;
			int getWidth() const;
			int getHeight() const;
			bool isKeyPressed(unsigned int key_code) const;
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(double& x, double& y) const;

		private:
			bool init();
			//friend meaning it can access private members of the class
			friend static void window_resize(GLFWwindow* window, int width, int height);
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend static void mousebutton_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}