#pragma once

#include <string>

namespace SwordSong {
	class Shader {
	public:
		Shader();
		virtual ~Shader();
		
		virtual void Load(const char* vertexPath, const char* fragmentPath);
		virtual void Use();

	    virtual void SetBool(const std::string &name, bool value) const;  
    	virtual void SetInt(const std::string &name, int value) const;   
    	virtual void SetFloat(const std::string &name, float value) const;
		virtual void SetVec4(const std::string &name, float x, float y, float z, float a) const;
		virtual void SetVec3(const std::string &name, float x, float y, float z) const;
		virtual void SetVec2(const std::string &name, float x, float y) const;
	private:
		unsigned int ID;
		const char* vertexPath;
		const char* fragmentPath;
	};
}