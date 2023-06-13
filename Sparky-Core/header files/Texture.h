#pragma once
#include<string>
#include <GL/glew.h>


namespace Sparky {
	namespace Graphics {
	
		class Texture {

		private:
			std::string m_fileName;
			GLuint m_TID;
			GLsizei m_Width, m_Height;
			GLuint load();
		public:
			Texture(const std::string& path);
			~Texture();
			void bind()const;
			void unbind()const;
			inline const unsigned int getID()     const { return m_TID; }
			inline const unsigned int getWidth()  const { return m_Width; }
			inline const unsigned int getHeight() const { return m_Height; }

		};
	
	
	}
}