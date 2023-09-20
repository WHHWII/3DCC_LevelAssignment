// Simple basecode showing how to create a window and attatch a openglsurface
#define GATEWARE_ENABLE_CORE // All libraries need this
#define GATEWARE_ENABLE_SYSTEM // Graphics libs require system level libraries
#define GATEWARE_ENABLE_GRAPHICS // Enables all Graphics Libraries
// TODO: Part 2a
#define GATEWARE_ENABLE_MATH
// Ignore some GRAPHICS libraries we aren't going to use
#define GATEWARE_DISABLE_GDIRECTX11SURFACE // we have another template for this
#define GATEWARE_DISABLE_GDIRECTX12SURFACE // we have another template for this
#define GATEWARE_DISABLE_GVULKANSURFACE // we have another template for this
#define GATEWARE_DISABLE_GRASTERSURFACE // we have another template for this
// With what we want & what we don't defined we can include the API
#define GATEWARE_ENABLE_INPUT
#include <Windows.h>
#include <ShObjIdl.h>

#include "../gateware/Gateware.h"
#include "OpenGLExtensions.h"
#include "FileIntoString.h"
#include "load_data_oriented.h"
#include "renderer.h" // example rendering code (not Gateware code!)
#include "CameraController.h"
#include "Camera.h"


// open some namespaces to compact the code a bit
using namespace GW;
using namespace CORE;
using namespace SYSTEM;
using namespace GRAPHICS;
// lets pop a window and use OpenGL to render to a window
int main()
{

	//load models
	GW::SYSTEM::GLog log; // handy for logging any messages/warning/errors
	// begin loading level
	log.Create("../LevelLoaderLog.txt");
	log.EnableConsoleLogging(true); // mirror output to the console
	log.Log("Start Program.");

	Level_Data dataOrientedLoader;
	dataOrientedLoader.LoadLevel("../Levels/GameLevel.txt", MODEL_PATH, log);


	

	GWindow win;
	GEventResponder msgs;
	GOpenGLSurface ogl;
	
	if (+win.Create(0, 0, 800, 600, GWindowStyle::WINDOWEDBORDERED))
	{
		// TODO: Part 1a
		float clr[] = { 48 / 255.0f, 90 / 255.0f, 150 / 255.0f, 1 }; // TODO: Part 1a (optional)
		msgs.Create([&](const GW::GEvent& e) {
			GW::SYSTEM::GWindow::Events q;
			if (+e.Read(q) && q == GWindow::Events::RESIZE)
				clr[2] += 0.01f; // shift color as they resize
		});
		win.Register(msgs);
		if (+ogl.Create(win, GW::GRAPHICS::DEPTH_BUFFER_SUPPORT))
		{
			QueryOGLExtensionFunctions(ogl); // Link Needed OpenGL API functions
			Renderer renderer(win, ogl, dataOrientedLoader);
			win.SetWindowName("Whitman Wilson - Assignment 2 - OpenGL");
			while (+win.ProcessWindowEvents())
			{
				glClearColor(clr[0], clr[1], clr[2], clr[3]);
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				renderer.TickFrame();
				renderer.HandleInput();
				renderer.Render();
				ogl.UniversalSwapBuffers();
			}
		}
	}
	return 0; // that's all folks
}