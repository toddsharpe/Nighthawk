using System.Diagnostics;
using Client.UI;
using Terminal.Gui;

Application.UseSystemConsole = true;
Application.Init();

try
{
	Application.Run<MainView>();
}
finally
{
	Application.Shutdown();
	Process.GetCurrentProcess().Kill();
}