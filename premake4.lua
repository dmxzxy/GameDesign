
local action = _ACTION or ""

solution "gamedesign"
	location ( "build" )
	configurations { "Debug", "Release" }
	platforms {"native", "x64", "x32"}

	project "lifegame"

		kind "ConsoleApp"
		language "C"
		files { "lifegame/main.c", "lifegame/lifegamecore.c"}
		includedirs { "lifegame", "../../Depends/Lib/GLFW/include", "../../Depends/Lib/GLEW/include", "../../Depends/Lib/nanovg/include" }
		libdirs {"../../Depends/Lib/GLEW/lib", "../../Depends/Lib/GLFW/lib", "../../Depends/Lib/nanovg/lib"}
		targetdir("build")

		configuration { "linux" }
			 linkoptions { "`pkg-config --libs glfw3`" }
			 links { "GL", "GLU", "m", "GLEW" }
			 defines { "NANOVG_GLEW" }

		configuration { "windows" }
			 links { "glfw3", "gdi32", "winmm", "user32", "GLEW32", "glu32","opengl32", "kernel32" }
			 defines { "NANOVG_GLEW", "_CRT_SECURE_NO_WARNINGS" }

		configuration { "macosx" }
			links { "glfw3" }
			linkoptions { "-framework OpenGL", "-framework Cocoa", "-framework IOKit", "-framework CoreVideo" }

		configuration "Debug"
			defines { "DEBUG" }
			flags { "Symbols", "ExtraWarnings"}

		configuration "Release"
			defines { "NDEBUG" }
			flags { "Optimize", "ExtraWarnings"}
