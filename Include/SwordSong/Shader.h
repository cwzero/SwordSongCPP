#pragma once

#include <string>

namespace SwordSong {
	class Shader {
	public:
		Shader(float wr, float hr);
		~Shader();
		
		void Load(const char* vertexPath, const char* fragmentPath);
		void Use();

	    void SetBool(const std::string &name, bool value) const;  
    	void SetInt(const std::string &name, int value) const;   
    	void SetFloat(const std::string &name, float value) const;
		void SetVec4(const std::string &name, float x, float y, float z, float a) const;
		void SetVec3(const std::string &name, float x, float y, float z) const;
		void SetVec2(const std::string &name, float x, float y) const;

		void SetPosition(float x, float y) const;
	private:
		float wr, hr;
		unsigned int ID;
		const char* vertexPath;
		const char* fragmentPath;
	};
}