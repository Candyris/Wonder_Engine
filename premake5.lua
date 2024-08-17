workspace "Wonder"
   architecture "x64"
   configurations { "Debug", "Release" }

project "Wonder"
   location "Wonder"
   language "C++"
   
outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architure}"

   targetdir ("vendor/bin/" .. outputdir .. "/%{prj.name}")
   objdir ("vendor/obj/" .. outputdir .. "/%{prj.name}")

   libdirs { "dependencies/lib", "dependencies/lib" }
   
   includedirs 
   {
      "%{prj.name}/vendor",
      "%{prj.name}/vendor/glm",
      "dependencies/include" 
   }
   files 
   {
      --"dependencies/include/**.h",
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp",
      "%{prj.name}/Game/**.h",
      "%{prj.name}/Game/**.cpp",
      "%{prj.name}/src/glad.c",
      "Wonder/vendor/imgui/**.cpp",
      "Wonder/vendor/imgui/**.h",
      "Wonder/vendor/glm/glm/glm.hpp",
      "Wonder/vendor/glm/glm/gtc/glm/**.hpp"
   }
   links { "glfw3.lib", "opengl32", "kernel32", "gdi32" }
   
   filter "system:window"
   systemversion "latest"
   
     
   
   symbols "On"
   
   filter "configurations:Debug"
   cppdialect "C++17"
   kind "ConsoleApp"
   defines  
   {
      "GLFW_STATIC",
      "DEBUG"
   }
   symbols "On"
   
   filter "configurations:Release"
   kind "ConsoleApp"
   --kind "WindowedApp"
   cppdialect "C++17"
   defines  
   {
      "GLFW_STATIC",
      "NDEBUG"
   }
   optimize "On"
   
   -- Post-build commands to copy the Shader folder
   postbuildcommands 
   {
      "{COPY} Shader ../%{cfg.targetdir}/Shader"
   }
   
   