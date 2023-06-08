#pragma once
#include<string>
#include <GL/glew.h>


namespace Sparky {
	namespace Graphics {
	
		class Texture {

		private:
			std::string m_Path;
			GLuint m_TID;
			unsigned m_width, m_height;
		public:
			Texture(const std::string& path);
			~Texture();
			void bind()const;
			void unbind()const;

			inline unsigned int getWidth() const { return m_width; }
			inline unsigned int getHeight() const { return m_height; }

		};
	
	
	}
}